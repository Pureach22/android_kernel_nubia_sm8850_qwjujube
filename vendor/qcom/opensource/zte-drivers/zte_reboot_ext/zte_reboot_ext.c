// SPDX-License-Identifier: GPL-2.0-only
/*
 * zte_reboot_ext.c - ZTE Custom Reboot Extension Driver
 *
 * Captures kernel panic arguments via a kretprobe on panic(),
 * extracts panic strings and telemetry, and saves them to Qualcomm/ZTE
 * NVMEM cells (NVRAM). Also exposes sysfs node to retrieve previous boot reason.
 *
 * Reconstructed from binary analysis of zte_reboot_ext.ko
 * extracted from NX809J (Red Magic 11 Pro) production firmware.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/kprobes.h>
#include <linux/notifier.h>
#include <linux/nvmem-consumer.h>
#include <linux/sysfs.h>
#include <linux/kobject.h>
#include <linux/ctype.h>
#include <linux/string.h>
#include <linux/of.h>
#include <linux/panic_notifier.h>

#define DRIVER_NAME "zte_reboot_ext"

/* Custom data structure matching binary offsets (160 bytes) */
struct zte_reboot_ext_data {
	struct device *dev;               // 0
	struct kobject kobj;             // 8
	struct notifier_block panic_nb;   // 104
	struct nvmem_cell *zlog_ss_cell;  // 128
	struct nvmem_cell *zlog_w_cell;   // 136
	struct nvmem_cell *zlog_p_cell;   // 144
	struct nvmem_cell *zlog_panic_ext_cell; // 152
};

/* Globals matching ROM binary */
static char saved_nvmem_buf[16];
static char read_nvmem_buf[18];
static int once_entry_panic_count = 0;

/* Declared externally by qcom_q6v5 modem subsystem driver */
extern u8 get_ss_panic_buf_byte(void);

/* ======================================================================
 * Helper Functions
 * ====================================================================== */

static int count_format_args(const char *fmt, unsigned int *s_idx)
{
	int args_count = -1;
	const char *p = fmt;

	if (!s_idx)
		return -1;

	*s_idx = -1;
	args_count = 0;

	if (!fmt)
		return 0;

	int state = 0;
	int s_arg_found = -1;

	while (*p) {
		char c = *p;
		if (c == '%') {
			state ^= 1;
			p++;
			continue;
		}

		if (state & 1) {
			if (strchr("diouxXfFeEgGaAcsSpn", c)) {
				state = 0;
				args_count++;
				if (c == 's' && s_arg_found == -1) {
					*s_idx = args_count;
					s_arg_found = args_count;
				}
			} else {
				if (c == '*')
					return -1;
				state = 1;
			}
		} else {
			state = 0;
		}
		p++;
	}

	return args_count;
}

static const char *fill_nvmem_buf(const char *s, const char *fmt, char *dest, int offset, size_t max_len)
{
	size_t len_s = 0, len_fmt = 0;
	size_t to_copy = 0;

	if (s) {
		len_s = strlen(s);
		if (fmt)
			len_fmt = strlen(fmt);
		
		if (len_s > 0) {
			to_copy = (len_s >= max_len) ? max_len : len_s;
			memcpy(dest + offset, s, to_copy);
			if (len_s >= max_len)
				return dest;
		}
	} else {
		if (fmt)
			len_fmt = strlen(fmt);
	}

	if (fmt && len_fmt > 0) {
		size_t remaining = max_len - to_copy;
		size_t to_copy_fmt = (len_fmt >= remaining) ? remaining : len_fmt;
		memcpy(dest + to_copy + offset, fmt, to_copy_fmt);
		to_copy += to_copy_fmt;
	}

	if (max_len > to_copy) {
		memset(dest + to_copy + offset, 0, max_len - to_copy);
	}

	return dest;
}

static void save_panic_buf_data_to_nvmem(struct zte_reboot_ext_data *data)
{
	if (!data) {
		pr_err("%s: NULL private data\n", __func__);
		return;
	}

	if (data->zlog_p_cell && !IS_ERR(data->zlog_p_cell)) {
		pr_info("%s: Writing zlog_p: %d\n", __func__, saved_nvmem_buf[3]);
		nvmem_cell_write(data->zlog_p_cell, &saved_nvmem_buf[3], 1);
	}

	if (data->zlog_w_cell && !IS_ERR(data->zlog_w_cell)) {
		pr_info("%s: Writing zlog_w: %d\n", __func__, saved_nvmem_buf[1]);
		nvmem_cell_write(data->zlog_w_cell, &saved_nvmem_buf[1], 1);
	}

	if (data->zlog_ss_cell && !IS_ERR(data->zlog_ss_cell)) {
		pr_info("%s: Writing zlog_ss: %d\n", __func__, saved_nvmem_buf[0]);
		nvmem_cell_write(data->zlog_ss_cell, &saved_nvmem_buf[0], 1);
	}

	if (data->zlog_panic_ext_cell && !IS_ERR(data->zlog_panic_ext_cell)) {
		pr_info("%s: Writing zlog_panic_ext: %d\n", __func__, saved_nvmem_buf[4]);
		nvmem_cell_write(data->zlog_panic_ext_cell, &saved_nvmem_buf[4], 1);
	}
}

/* ======================================================================
 * sysfs Interface
 * ====================================================================== */

struct bootreason_attribute {
	struct attribute attr;
	ssize_t (*show)(struct kobject *kobj, struct bootreason_attribute *attr, char *buf);
	ssize_t (*store)(struct kobject *kobj, struct bootreason_attribute *attr, const char *buf, size_t count);
};

static ssize_t boot_nvmem_show(struct kobject *kobj, struct bootreason_attribute *attr, char *buf)
{
	char clean_buf[14];
	int i;

	for (i = 0; i < 12; i++) {
		unsigned char c = read_nvmem_buf[i];
		/* Verify if character is printable according to ctype validation */
		if (isprint(c) || isspace(c)) {
			clean_buf[i] = c;
		} else {
			clean_buf[i] = '*';
		}
	}
	clean_buf[12] = '\n';
	clean_buf[13] = '\0';

	return scnprintf(buf, 4096, "%s", clean_buf);
}

static ssize_t boot_nvmem_store(struct kobject *kobj, struct bootreason_attribute *attr, const char *buf, size_t count)
{
	pr_warn("%s: Writing bootreason via sysfs is not allowed\n", __func__);
	return -EINVAL;
}

static struct bootreason_attribute boot_nvmem_attr = {
	.attr = { .name = "boot_nvmem", .mode = 0644 },
	.show = boot_nvmem_show,
	.store = boot_nvmem_store,
};

static ssize_t attr_show(struct kobject *kobj, struct attribute *attr, char *buf)
{
	struct bootreason_attribute *battr = container_of(attr, struct bootreason_attribute, attr);
	if (!battr->show)
		return -EIO;
	return battr->show(kobj, battr, buf);
}

static ssize_t attr_store(struct kobject *kobj, struct attribute *attr, const char *buf, size_t count)
{
	struct bootreason_attribute *battr = container_of(attr, struct bootreason_attribute, attr);
	if (!battr->store)
		return -EIO;
	return battr->store(kobj, battr, buf, count);
}

static const struct sysfs_ops bootreason_sysfs_ops = {
	.show = attr_show,
	.store = attr_store,
};

static struct kobj_type bootreason_nvmem_kobj_type = {
	.sysfs_ops = &bootreason_sysfs_ops,
};

static struct attribute *qcom_boot_nvmem_attrs[] = {
	&boot_nvmem_attr.attr,
	NULL,
};

static const struct attribute_group qcom_boot_nvmem_attr_group = {
	.attrs = qcom_boot_nvmem_attrs,
};

/* ======================================================================
 * Panic Hooks & Notifier callbacks
 * ====================================================================== */

static int entry_panic(struct kretprobe_instance *ri, struct pt_regs *regs)
{
	const char *fmt;
	unsigned int s_idx = -1;
	int args_count = 0;
	const char *s_arg = NULL;

	if (once_entry_panic_count++) {
		pr_info("%s: panic already handled (ss=%d)\n", __func__, saved_nvmem_buf[0]);
		return 0;
	}

	/*regs->regs[0] holds format string on AArch64 */
	fmt = (const char *)regs->regs[0];
	if (!fmt)
		return 0;

	if (strlen(fmt) + 21 > 0x100) {
		pr_err("%s: panic format string too long\n", __func__);
		return 0;
	}

	args_count = count_format_args(fmt, &s_idx);

	if (s_idx != -1 && s_idx <= 6) {
		s_arg = (const char *)regs->regs[s_idx];
		if (!s_arg) {
			pr_err("%s: NULL argument for dynamic string parameter\n", __func__);
		} else {
			pr_info("%s: Panic argument string: %s\n", __func__, s_arg);
			if (strcmp(s_arg, "panicinpanic") == 0) {
				panic("panicinpanic %d", once_entry_panic_count);
			}
		}
	}

	saved_nvmem_buf[3] = 80; // 'P'
	fill_nvmem_buf(s_arg, fmt, saved_nvmem_buf, 4, 12);

	pr_info("%s: panic captured: ss=%d, w=%d\n", __func__, saved_nvmem_buf[0], saved_nvmem_buf[1]);
	return 0;
}

static struct kretprobe panic_probe = {
	.handler = entry_panic,
	.kp = {
		.symbol_name = "panic",
	},
};

static int zte_reboot_ext_panic(struct notifier_block *nb, unsigned long action, void *data)
{
	struct zte_reboot_ext_data *private_data;

	private_data = container_of(nb, struct zte_reboot_ext_data, panic_nb);
	saved_nvmem_buf[0] = get_ss_panic_buf_byte();
	save_panic_buf_data_to_nvmem(private_data);

	return NOTIFY_DONE;
}

/* ======================================================================
 * Platform Driver Probe and Remove
 * ====================================================================== */

static int zte_reboot_ext_probe(struct platform_device *pdev)
{
	struct zte_reboot_ext_data *data;
	int ret;
	size_t len;
	u8 *cell_val;

	data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->dev = &pdev->dev;

	/* Setup sysfs kobject "/sys/kernel/bootreason" */
	ret = kobject_init_and_add(&data->kobj, &bootreason_nvmem_kobj_type, kernel_kobj, "bootreason");
	if (ret) {
		dev_err(&pdev->dev, "%s: Failed to create sysfs bootreason node: %d\n", __func__, ret);
		kobject_put(&data->kobj);
		return ret;
	}

	ret = sysfs_create_group(&data->kobj, &qcom_boot_nvmem_attr_group);
	if (ret) {
		dev_err(&pdev->dev, "%s: Failed to create sysfs attributes group: %d\n", __func__, ret);
		kobject_del(&data->kobj);
		return ret;
	}

	/* Grab NVMEM cells */
	data->zlog_ss_cell = nvmem_cell_get(&pdev->dev, "vendor_zlog_ss");
	if (!IS_ERR_OR_NULL(data->zlog_ss_cell)) {
		cell_val = nvmem_cell_read(data->zlog_ss_cell, &len);
		if (!IS_ERR_OR_NULL(cell_val)) {
			read_nvmem_buf[0] = *cell_val;
			kfree(cell_val);
		}
	}

	data->zlog_w_cell = nvmem_cell_get(&pdev->dev, "vendor_zlog_w");
	if (!IS_ERR_OR_NULL(data->zlog_w_cell)) {
		cell_val = nvmem_cell_read(data->zlog_w_cell, &len);
		if (!IS_ERR_OR_NULL(cell_val)) {
			read_nvmem_buf[1] = *cell_val;
			kfree(cell_val);
		}
	}

	data->zlog_p_cell = nvmem_cell_get(&pdev->dev, "vendor_zlog_p");
	if (!IS_ERR_OR_NULL(data->zlog_p_cell)) {
		cell_val = nvmem_cell_read(data->zlog_p_cell, &len);
		if (!IS_ERR_OR_NULL(cell_val)) {
			read_nvmem_buf[3] = *cell_val;
			kfree(cell_val);
		}
	}

	data->zlog_panic_ext_cell = nvmem_cell_get(&pdev->dev, "vendor_zlog_panic_ext");
	if (!IS_ERR_OR_NULL(data->zlog_panic_ext_cell)) {
		cell_val = nvmem_cell_read(data->zlog_panic_ext_cell, &len);
		if (!IS_ERR_OR_NULL(cell_val)) {
			memcpy(read_nvmem_buf + 4, cell_val, len > 14 ? 14 : len);
			kfree(cell_val);
		}
	}

	/* Recover previous boot reason and save default configs */
	save_panic_buf_data_to_nvmem(data);

	/* Register kretprobe */
	ret = register_kretprobe(&panic_probe);
	if (ret) {
		dev_err(&pdev->dev, "ztedbg failed to register panic hook kprobe: %d\n", ret);
	} else {
		dev_info(&pdev->dev, "ztedbg registered panic hook successfully\n");
	}

	/* Register notifier block */
	data->panic_nb.notifier_call = zte_reboot_ext_panic;
	data->panic_nb.priority = 0x7FFFFFFF;
	atomic_notifier_chain_register(&panic_notifier_list, &data->panic_nb);

	platform_set_drvdata(pdev, data);
	return 0;
}

static void zte_reboot_ext_remove(struct platform_device *pdev)
{
	struct zte_reboot_ext_data *data = platform_get_drvdata(pdev);

	if (data) {
		atomic_notifier_chain_unregister(&panic_notifier_list, &data->panic_nb);
		unregister_kretprobe(&panic_probe);
		sysfs_remove_group(&data->kobj, &qcom_boot_nvmem_attr_group);
		kobject_del(&data->kobj);
	}

	dev_info(&pdev->dev, "ztedbg reboot ext module removed\n");
}

static const struct of_device_id zte_reboot_ext_match[] = {
	{ .compatible = "zte,reboot-ext" },
	{ },
};
MODULE_DEVICE_TABLE(of, zte_reboot_ext_match);

static struct platform_driver zte_reboot_ext_driver = {
	.probe = zte_reboot_ext_probe,
	.remove = zte_reboot_ext_remove,
	.driver = {
		.name = DRIVER_NAME,
		.of_match_table = zte_reboot_ext_match,
	},
};

module_platform_driver(zte_reboot_ext_driver);

MODULE_DESCRIPTION("ZTE Custom Reboot Extension Driver");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZTE Corporation (reconstructed)");
