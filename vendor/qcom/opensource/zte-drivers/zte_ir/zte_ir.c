// SPDX-License-Identifier: GPL-2.0-only
/*
 * zte_ir.c - ZTE Custom SPI IR Blaster (Infrared) Driver
 *
 * Modulates IR pulses by writing patterns to a virtual SPI character device.
 *
 * Reconstructed from binary analysis of zte_ir.ko
 * extracted from NX809J (Red Magic 11 Pro) production firmware.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/mutex.h>
#include <linux/spi/spi.h>
#include <linux/uaccess.h>
#include <linux/list.h>

#define DRIVER_NAME "zte_ir"
#define ZTE_IR_IOC_SET_FREQ _IOW('k', 0x31, unsigned int)

/* Globals matching ROM binary */
static int spidev_major;
static struct class *zte_ir_class;
static unsigned long minors = 0;

static LIST_HEAD(device_list);
static DEFINE_MUTEX(device_list_lock);

/* Private data structure matching Ghidra analysis (80104 bytes) */
struct zte_ir_data {
	dev_t devt;                     // 0
	u16 tx_buf[40000];              // 4 -> 80004
	u16 pattern_high;               // 80004
	u16 pattern_low;                // 80006
	u32 speed_hz;                   // 80008
	struct spi_device *spi;         // 80016
	u32 state;                      // 80032
	struct mutex buf_lock;          // 80040
	struct list_head device_entry;  // 80088
};

/* ======================================================================
 * File Operations Callbacks
 * ====================================================================== */

static int zte_ir_open(struct inode *inode, struct file *file)
{
	struct zte_ir_data *data;
	struct list_head *pos;
	int ret = -ENXIO;

	mutex_lock(&device_list_lock);

	list_for_each(pos, &device_list) {
		data = list_entry(pos, struct zte_ir_data, device_entry);
		if (data->devt == inode->i_rdev) {
			pr_info("%s: device opened successfully\n", __func__);
			file->private_data = data;
			nonseekable_open(inode, file);
			ret = 0;
			goto out;
		}
	}

	pr_err("%s: device minor %d not found\n", __func__, iminor(inode));

out:
	mutex_unlock(&device_list_lock);
	return ret;
}

static int zte_ir_release(struct inode *inode, struct file *file)
{
	mutex_lock(&device_list_lock);
	file->private_data = NULL;
	pr_info("%s: device released\n", __func__);
	mutex_unlock(&device_list_lock);
	return 0;
}

static long zte_ir_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	struct zte_ir_data *data = file->private_data;
	unsigned int freq;

	if (!data)
		return -EINVAL;

	if (cmd == ZTE_IR_IOC_SET_FREQ) {
		pr_info("%s: received ZTE_IR_IOC_SET_FREQ ioctl\n", __func__);

		if (copy_from_user(&freq, (void __user *)arg, sizeof(freq)))
			return -EFAULT;

		if (freq == 0)
			return -EINVAL;

		/* speed_hz matches 16 * freq to modulate carrier wave correctly */
		data->speed_hz = 16 * freq;
		return 0;
	}

	return -ENOTTY;
}

static ssize_t zte_ir_write(struct file *file, const char __user *buf, size_t count, loff_t *ppos)
{
	struct zte_ir_data *data = file->private_data;
	u32 *user_pulses = NULL;
	size_t num_pulses;
	int i, pulse_idx, ret = 0;
	u32 tx_words_count = 0;

	if (!data)
		return -EINVAL;

	pr_info("%s: entry\n", __func__);

	mutex_lock(&data->buf_lock);

	user_pulses = memdup_user(buf, count);
	if (IS_ERR(user_pulses)) {
		ret = PTR_ERR(user_pulses);
		goto out_unlock;
	}

	if (count < sizeof(u32)) {
		/* Zero length pulse or malformed request, trigger empty sync */
		goto trigger_spi;
	}

	num_pulses = count / sizeof(u32);

	for (pulse_idx = 0; pulse_idx < num_pulses; pulse_idx++) {
		u32 pulse_val = user_pulses[pulse_idx];
		u64 temp;
		u32 spi_word_count;
		u16 modulation_pattern;

		/* Mathematical conversion of microseconds to SPI words based on speed_hz */
		temp = (u64)pulse_val * (data->speed_hz >> 4) + 500000;
		spi_word_count = (u32)(temp / 1000000);

		if (tx_words_count + spi_word_count >= 40000) {
			pr_err("%s: transmission buffer size exceeded! (limit 40000, requested=%d)\n",
				__func__, tx_words_count + spi_word_count);
			ret = -EINVAL;
			goto out_free;
		}

		/* Even pulses are HIGH carrier waves, odd pulses are LOW carrier waves */
		modulation_pattern = (pulse_idx & 1) ? data->pattern_low : data->pattern_high;

		if (spi_word_count > 0) {
			for (i = 0; i < spi_word_count; i++) {
				data->tx_buf[tx_words_count++] = modulation_pattern;
			}
		}
	}

trigger_spi:
	pr_info("%s: triggering SPI transmission of %d words\n", __func__, tx_words_count);

	if (data->spi) {
		struct spi_transfer transfer = {
			.tx_buf = data->tx_buf,
			.len = tx_words_count * sizeof(u16),
			.speed_hz = data->speed_hz,
			.bits_per_word = 16,
		};
		struct spi_message msg;

		spi_message_init(&msg);
		spi_message_add_tail(&transfer, &msg);

		ret = spi_sync(data->spi, &msg);
		if (ret) {
			dev_err(&data->spi->dev, "unable to deliver the signal, ret = %d\n", ret);
		}
	}

	pr_info("%s: exit\n", __func__);

out_free:
	kfree(user_pulses);
out_unlock:
	mutex_unlock(&data->buf_lock);
	return ret ? ret : count;
}

static const struct file_operations zte_ir_fops = {
	.owner          = THIS_MODULE,
	.write          = zte_ir_write,
	.unlocked_ioctl = zte_ir_ioctl,
	.open           = zte_ir_open,
	.release        = zte_ir_release,
	.llseek         = noop_llseek,
};

/* ======================================================================
 * SPI Driver Probe & Remove
 * ====================================================================== */

static int zte_ir_probe(struct spi_device *spi)
{
	struct zte_ir_data *data;
	struct device *dev_node;
	int ret = 0;

	data = kzalloc(sizeof(*data), GFP_KERNEL);
	if (!data)
		return -ENOMEM;

	data->spi = spi;
	data->state = 0;
	mutex_init(&data->buf_lock);

	/* Initialize lists head */
	INIT_LIST_HEAD(&data->device_entry);

	mutex_lock(&device_list_lock);

	/* Check if minor is already occupied (only 1 minor/instance supported) */
	if (minors & 1) {
		dev_err(&spi->dev, "no minor number available!\n");
		ret = -EBUSY;
		goto err_free_data;
	}

	data->devt = MKDEV(spidev_major, 0);

	/* Create device entry */
	dev_node = device_create(zte_ir_class, &spi->dev, data->devt, data, "zte_ir");
	if (IS_ERR(dev_node)) {
		dev_err(&spi->dev, "failed to create device node!\n");
		ret = PTR_ERR(dev_node);
		goto err_free_data;
	}

	/* Claim minor */
	minors |= 1;

	/* Add to global list */
	list_add_tail(&data->device_entry, &device_list);
	mutex_unlock(&device_list_lock);

	/* Set default carrier frequency parameters matching 38kHz (608000 Hz / 16) */
	data->speed_hz = 608000;
	data->pattern_high = 31;
	data->pattern_low = 0;

	dev_info(&spi->dev, "zte_ir->speed_hz=%d\n", data->speed_hz);

	spi_set_drvdata(spi, data);
	return 0;

err_free_data:
	mutex_unlock(&device_list_lock);
	kfree(data);
	return ret;
}

static void zte_ir_remove(struct spi_device *spi)
{
	struct zte_ir_data *data = spi_get_drvdata(spi);

	if (data) {
		/* Clear reference to prevent panic on concurrent writes */
		mutex_lock(&data->buf_lock);
		data->spi = NULL;
		mutex_unlock(&data->buf_lock);

		mutex_lock(&device_list_lock);
		list_del(&data->device_entry);
		device_destroy(zte_ir_class, data->devt);

		/* Release minor */
		minors &= ~1;
		mutex_unlock(&device_list_lock);

		kfree(data);
	}
	dev_info(&spi->dev, "zte_ir module removed\n");
}

static const struct of_device_id zte_ir_match[] = {
	{ .compatible = "zte,ir" },
	{ .compatible = "zte,ir-spi" },
	{ },
};
MODULE_DEVICE_TABLE(of, zte_ir_match);

static struct spi_driver zte_ir_spi_driver = {
	.driver = {
		.name           = DRIVER_NAME,
		.of_match_table = zte_ir_match,
	},
	.probe  = zte_ir_probe,
	.remove = zte_ir_remove,
};

/* ======================================================================
 * Module Initialization & Cleanup
 * ====================================================================== */

static int __init zte_ir_init(void)
{
	int ret;

	pr_info("%s: initializing zte_ir module\n", __func__);

	/* Register character device dynamically with 1 minor */
	spidev_major = register_chrdev(0, "spi", &zte_ir_fops);
	if (spidev_major < 0) {
		pr_err("%s: failed to register character device\n", __func__);
		return spidev_major;
	}

	pr_info("%s: registered with major %d\n", __func__, spidev_major);

	zte_ir_class = class_create("zte_ir_class");
	if (IS_ERR(zte_ir_class)) {
		pr_err("%s: failed to create class\n", __func__);
		ret = PTR_ERR(zte_ir_class);
		goto err_unregister_chrdev;
	}

	ret = spi_register_driver(&zte_ir_spi_driver);
	if (ret) {
		pr_err("%s: failed to register SPI driver\n", __func__);
		goto err_destroy_class;
	}

	return 0;

err_destroy_class:
	class_destroy(zte_ir_class);
err_unregister_chrdev:
	unregister_chrdev(spidev_major, "spi");
	return ret;
}

static void __exit zte_ir_exit(void)
{
	spi_unregister_driver(&zte_ir_spi_driver);
	class_destroy(zte_ir_class);
	unregister_chrdev(spidev_major, "spi");
}

module_init(zte_ir_init);
module_exit(zte_ir_exit);

MODULE_DESCRIPTION("ZTE Custom SPI IR Blaster Driver");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZTE Corporation (reconstructed)");
