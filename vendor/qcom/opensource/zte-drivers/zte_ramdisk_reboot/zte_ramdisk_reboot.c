// SPDX-License-Identifier: GPL-2.0-only
/*
 * zte_ramdisk_reboot.c - ZTE Custom Ramdisk Reboot Driver
 *
 * Maps the XBL log memory region from device tree, scans it for Serial Number
 * and OCP (Overcurrent Protection) telemetry, and exposes watchdog reboot
 * flag interface to NVMEM cell (bootflag).
 *
 * Reconstructed from binary analysis of zte_ramdisk_reboot.ko
 * extracted from NX809J (Red Magic 11 Pro) production firmware.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/platform_device.h>
#include <linux/slab.h>
#include <linux/nvmem-consumer.h>
#include <linux/sysfs.h>
#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/of.h>
#include <linux/of_reserved_mem.h>
#include <linux/io.h>

#define DRIVER_NAME "zte_ramdisk_reboot"

/* Custom data structure matching binary offsets (136 bytes) */
struct zte_ramdisk_reboot_data {
	struct device *dev;               // 0
	struct kobject kobj;             // 8
	struct nvmem_cell *cell;         // 104
	phys_addr_t base;                // 112
	size_t size;                     // 120
	void __iomem *vaddr;             // 128
};

static struct zte_ramdisk_reboot_data *ramdisk_rb = NULL;
static char saved_ramdisk_buf = 0;
static char extract_buffer[256] = {0};

/* ======================================================================
 * Helper Functions
 * ====================================================================== */

static int extract_ocp_info(struct device *dev, char *haystack, char *dest, size_t dest_len)
{
	char *v8;
	char *v9;
	const char *v10;
	size_t v12;
	size_t v13;

	if (!haystack) {
		dev_err(dev, "ztedbg null input ocp line\n");
		return -EINVAL;
	}

	v8 = strstr(haystack, "OCP Occured: ");
	v9 = strstr(haystack, "Status: ");
	if (v8 && v9) {
		v10 = v8 + 13;
		if (v9 >= v10) {
			v12 = v9 - v10;
			if (v12) {
				v13 = strlen(haystack);
				if (v12 < dest_len && v12 < v13) {
					strncpy(dest, v10, v12);
					dest[v12] = 0;
					return 0;
				}
			}
			dev_err(dev, "ztedbg invalid ocp extract with input: %s\n", haystack);
		} else {
			dev_err(dev, "ztedbg invalid ocp input %s\n", haystack);
		}
	} else {
		dev_err(dev, "ztedbg invalid ocp input %s\n", haystack);
	}
	return -EINVAL;
}

static int extract_sn_info(struct device *dev, char *haystack, char *dest, size_t dest_len)
{
	char *v8;
	char *v9;
	size_t v10;
	size_t v11;
	size_t v12;

	if (!haystack) {
		dev_err(dev, "ztedbg null input sn line\n");
		return -EINVAL;
	}

	v8 = strstr(haystack, " = ");
	if (!v8) {
		dev_err(dev, "ztedbg invalid sn input %s\n", haystack);
		return -EINVAL;
	}

	v9 = v8;
	v10 = strlen(haystack);
	v11 = (v9 - haystack) + 3;
	if (v10 < v11) {
		dev_err(dev, "ztedbg invalid sn input %s\n", haystack);
		return -EINVAL;
	}

	v12 = v10 - v11;
	if (v12 >= dest_len || v10 == v11 || v12 >= v10) {
		dev_err(dev, "ztedbg invalid sn extract with input: %s\n", haystack);
		return -EINVAL;
	}

	strncpy(dest, v9 + 3, v12);
	dest[v12] = 0;
	return 0;
}

static int zte_check_xbl_log_lines(struct zte_ramdisk_reboot_data *data,
				   const char **search_patterns,
				   int num_patterns,
				   int *search_limits,
				   char *output_buffers)
{
	char *v5 = (char *)data->vaddr;
	size_t v6 = 12288;
	size_t v21;
	char *v7;
	size_t v11;
	char *v12;
	size_t v13;
	char *v14;
	char *v15;
	int v16;
	int *v17;
	int v18;
	int v19;

	if (data->size < 0x3000)
		v6 = data->size;
	v21 = v6;
	v7 = &v5[v6];

	if (v5 >= v7)
		return 0;

	while (1) {
		v11 = v7 - v5;
		v12 = memchr(v5, '\n', v11);
		if (!v12) {
			dev_info(data->dev, "ztedbg xbl in the end of log\n");
			return 0;
		}

		v13 = v12 - v5;
		v14 = v12;
		if (v13 < 2) {
			break;
		}

		if (!num_patterns) {
LABEL_19:
			dev_info(data->dev, "ztedbg xbl all searched\n");
			return 0;
		}

		v15 = output_buffers;
		v16 = 0;
		do {
			if (search_limits[v16] >= 1 && strnstr(v5, search_patterns[v16], v13)) {
				if (v13 > 128) {
					dev_info(data->dev, "ztedbg ignored matched long line for idx %d / left %zu\n", v16, v11);
				} else {
					memcpy(v15, v5, v13 - 1);
					v15[v13 - 1] = 0;
					search_limits[v16]--;
				}
			}
			v16++;
			v15 += 128;
		} while (num_patterns != v16);

		v5 = v14 + 1;
		v17 = search_limits;
		v18 = num_patterns;
		while (1) {
			v19 = *v17++;
			if (v19 > 0)
				break;
			if (!--v18)
				goto LABEL_19;
		}

		v7 = (char *)(data->vaddr + v21);
		if (v5 >= v7)
			return 0;
	}

	dev_err(data->dev, "ztedbg unexpected matched len %zu : now offset %zu\n", (size_t)(v12 - v5), v11);
	return -EINVAL;
}

static int zte_get_xbl_log_memory_region(struct zte_ramdisk_reboot_data *data)
{
	struct device_node *np;
	struct of_phandle_args args;
	struct reserved_mem *rmem;
	int ret;

	np = data->dev->of_node;
	memset(&args, 0, sizeof(args));

	ret = of_parse_phandle_with_args(np, "memory-region", NULL, 0, &args);
	if (ret || !args.np) {
		dev_err(data->dev, "ztedbg no xbl log memory-region specified\n");
		return -EINVAL;
	}

	rmem = of_reserved_mem_lookup(args.np);
	if (!rmem) {
		dev_err(data->dev, "ztedbg unable to resolve xbl log memory-region\n");
		return -EINVAL;
	}

	data->base = rmem->base;
	data->size = rmem->size;
	data->vaddr = devm_ioremap_wc(data->dev, data->base, data->size);
	if (!data->vaddr) {
		dev_err(data->dev, "ztedbg unable to map xbl log memory region: %pa+%zx\n",
			&data->base, data->size);
		return -EBUSY;
	}

	return 0;
}

/* ======================================================================
 * External API - called by watchdog
 * ====================================================================== */

int zte_ramdisk_reboot_write(unsigned char *val, int len)
{
	if (len != 1 || !val)
		return -EINVAL;

	if (!ramdisk_rb)
		return -ENODEV;

	if (!ramdisk_rb->cell || IS_ERR(ramdisk_rb->cell)) {
		pr_err("ztedbg cell error: %px\n", ramdisk_rb->cell);
		return -EINVAL;
	}

	saved_ramdisk_buf = *val;
	pr_info("ztedbg write wdt cell: 0x%02x\n", saved_ramdisk_buf);

	return nvmem_cell_write(ramdisk_rb->cell, &saved_ramdisk_buf, 1);
}
EXPORT_SYMBOL_GPL(zte_ramdisk_reboot_write);

/* ======================================================================
 * sysfs Interface
 * ====================================================================== */

struct ramdisk_reboot_attribute {
	struct attribute attr;
	ssize_t (*show)(struct kobject *kobj, struct ramdisk_reboot_attribute *attr, char *buf);
	ssize_t (*store)(struct kobject *kobj, struct ramdisk_reboot_attribute *attr, const char *buf, size_t count);
};

static ssize_t ramdisk_nvmem_show(struct kobject *kobj, struct ramdisk_reboot_attribute *attr, char *buf)
{
	return scnprintf(buf, PAGE_SIZE, "%s\n", extract_buffer);
}

static ssize_t ramdisk_nvmem_store(struct kobject *kobj, struct ramdisk_reboot_attribute *attr, const char *buf, size_t count)
{
	pr_err("ztedbg write ramdisk_nvmem not allowed\n");
	return -EINVAL;
}

static struct ramdisk_reboot_attribute ramdisk_nvmem_attr = {
	.attr = { .name = "ramdisk_nvmem", .mode = 0644 },
	.show = ramdisk_nvmem_show,
	.store = ramdisk_nvmem_store,
};

static ssize_t attr_show(struct kobject *kobj, struct attribute *attr, char *buf)
{
	struct ramdisk_reboot_attribute *rattr = container_of(attr, struct ramdisk_reboot_attribute, attr);
	if (!rattr->show)
		return -EIO;
	return rattr->show(kobj, rattr, buf);
}

static ssize_t attr_store(struct kobject *kobj, struct attribute *attr, const char *buf, size_t count)
{
	struct ramdisk_reboot_attribute *rattr = container_of(attr, struct ramdisk_reboot_attribute, attr);
	if (!rattr->store)
		return -EIO;
	return rattr->store(kobj, rattr, buf, count);
}

static const struct sysfs_ops ramdisk_reboot_sysfs_ops = {
	.show = attr_show,
	.store = attr_store,
};

static struct kobj_type ramdisk_reboot_ktype = {
	.sysfs_ops = &ramdisk_reboot_sysfs_ops,
};

static struct attribute *ramdisk_reboot_attrs[] = {
	&ramdisk_nvmem_attr.attr,
	NULL,
};

static const struct attribute_group ramdisk_reboot_attr_group = {
	.attrs = ramdisk_reboot_attrs,
};

/* ======================================================================
 * Platform Driver Probe & Remove
 * ====================================================================== */

static int zte_ramdisk_reboot_probe(struct platform_device *pdev)
{
	struct zte_ramdisk_reboot_data *data;
	int ret;
	const char *search_patterns[] = {
		"OCP Occured: ",
		"serialno"
	};
	int search_limits[] = { 1, 1 };
	char matched_lines[2][128];
	char sn_val[64] = {0};
	char ocp_val[64] = {0};

	data = devm_kzalloc(&pdev->dev, sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->dev = &pdev->dev;
	ramdisk_rb = data;

	/* Grab NVMEM cell */
	data->cell = devm_nvmem_cell_get(&pdev->dev, "ramdisk-rb");
	if (IS_ERR(data->cell)) {
		dev_warn(&pdev->dev, "ztedbg failed to get ramdisk-rb cell: %ld\n", PTR_ERR(data->cell));
		data->cell = NULL;
	}

	/* Map XBL log memory region and parse */
	ret = zte_get_xbl_log_memory_region(data);
	if (ret == 0) {
		memset(matched_lines, 0, sizeof(matched_lines));
		ret = zte_check_xbl_log_lines(data, search_patterns, 2, search_limits, (char *)matched_lines);
		if (ret == 0) {
			extract_ocp_info(&pdev->dev, matched_lines[0], ocp_val, sizeof(ocp_val));
			extract_sn_info(&pdev->dev, matched_lines[1], sn_val, sizeof(sn_val));
			snprintf(extract_buffer, sizeof(extract_buffer), "SN: %s, OCP: %s", sn_val, ocp_val);
		} else {
			snprintf(extract_buffer, sizeof(extract_buffer), "Log scan failed");
		}
	} else {
		snprintf(extract_buffer, sizeof(extract_buffer), "Memory map failed");
	}

	/* Setup sysfs kobject "ramdiskboot" under kernel_kobj */
	ret = kobject_init_and_add(&data->kobj, &ramdisk_reboot_ktype, kernel_kobj, "ramdiskboot");
	if (ret) {
		dev_err(&pdev->dev, "ztedbg failed to create sysfs ramdisk_reboot node: %d\n", ret);
		kobject_put(&data->kobj);
		return ret;
	}

	ret = sysfs_create_group(&data->kobj, &ramdisk_reboot_attr_group);
	if (ret) {
		dev_err(&pdev->dev, "ztedbg failed to create sysfs attributes group: %d\n", ret);
		kobject_del(&data->kobj);
		return ret;
	}

	platform_set_drvdata(pdev, data);
	dev_info(&pdev->dev, "ztedbg ramdisk reboot driver probed successfully\n");
	return 0;
}

static void zte_ramdisk_reboot_remove(struct platform_device *pdev)
{
	struct zte_ramdisk_reboot_data *data = platform_get_drvdata(pdev);

	if (data) {
		sysfs_remove_group(&data->kobj, &ramdisk_reboot_attr_group);
		kobject_del(&data->kobj);
	}
	ramdisk_rb = NULL;
	dev_info(&pdev->dev, "ztedbg ramdisk reboot driver removed\n");
}

static const struct of_device_id zte_ramdisk_reboot_match[] = {
	{ .compatible = "zte,ramdisk-reboot" },
	{ },
};
MODULE_DEVICE_TABLE(of, zte_ramdisk_reboot_match);

static struct platform_driver zte_ramdisk_reboot_driver = {
	.probe = zte_ramdisk_reboot_probe,
	.remove = zte_ramdisk_reboot_remove,
	.driver = {
		.name = DRIVER_NAME,
		.of_match_table = zte_ramdisk_reboot_match,
	},
};

module_platform_driver(zte_ramdisk_reboot_driver);

MODULE_DESCRIPTION("ZTE Custom Ramdisk Reboot Driver");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZTE Corporation (reconstructed)");
