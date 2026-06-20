// SPDX-License-Identifier: GPL-2.0-only
/*
 * zte_led.c - ZTE Smart RGB LED Controller (Awinic AW22XXX) Driver
 *
 * Reconstructed from binary analysis of zte_led.ko
 * extracted from NX809J (Red Magic 11 Pro) production firmware.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/slab.h>
#include <linux/i2c.h>
#include <linux/leds.h>
#include <linux/gpio/consumer.h>
#include <linux/of_gpio.h>
#include <linux/of.h>
#include <linux/proc_fs.h>
#include <linux/uaccess.h>
#include <linux/mutex.h>
#include <linux/pinctrl/consumer.h>
#include <linux/firmware.h>
#include <linux/delay.h>
#include <linux/workqueue.h>
#include <linux/kthread.h>
#include <linux/hrtimer.h>
#include <linux/string.h>

#define DRIVER_NAME "zte_led"

struct aw22xxx {
	struct i2c_client *i2c;           // offset 0
	struct device *dev;               // offset 8
	struct led_classdev cdev;         // offset 16
	// brightness_work e task_work estão no offset 464 e 496 respectivamente.
	// O offset de cdev no GKI kernel pode variar, garantimos o alinhamento
	// definindo um padding explícito se necessário, ou acessando via container_of.
	struct work_struct brightness_work;
	struct work_struct task_work;
	struct work_struct fw_work;
	struct work_struct cfg_work;
	struct work_struct recover_work;
	struct hrtimer timer;
	struct mutex cfg_lock;
	u32 reset_gpio;
	u32 irq_gpio;
	u32 nubia_ver_gpio;
	u8 no_interrupt;
	u8 chip_type;                     // offset 749 (1=aw22118, 2=aw22127)
	u8 init_flag;                     // offset 750
	u8 container_update_state;        // offset 751
	u32 imax;                         // offset 752
	u32 task_irq;                     // offset 760
	u8 task0;                         // offset 764
	u8 task1;                         // offset 765
	u32 effect;                       // offset 768
	u8 cfg_custom_en;                 // offset 772
	u32 rgb_val[9];                   // offset 780
	struct pinctrl *pinctrl;          // offset 816
	struct pinctrl_state *pinctrl_default;
	struct pinctrl_state *pinctrl_sleep;
	u8 need_update;                   // offset 840
};

/* Globals matching ROM binary */
static char aw22xxx_fw_name[64] = "aw22xxx_fw.bin";
static char aw22xxx_dyn_name[64];
static u32 multicolor_led = 0;
static u32 g_ver_var = 11;
static u32 g_custom_en = 0;
static u32 g_cfgarray_count = 4500;
static u8 init_flag = 0;
static u8 g_init_flg = 0;
static u8 g_cfg_cur_state = 0;
static uint64_t g_chip_id = 0;

static int write_idx = 0;
static int read_idx = 0;
static int user_para_data[25000];
static u8 duration = 0;
static struct task_struct *cfg_update_kthread = NULL;
static int kthread_status = 0;
static char **aw22xxx_cfg_name = NULL;

static const u8 aw22xxx_imax_code[13] = {
	0x08, 0x00, 0x09, 0x01, 0x02, 0x0b, 0x03, 0x0c, 0x04, 0x0e, 0x05, 0x06, 0x07
};

static const char * const aw22xxx_imax_name[] = {
	"AW22XXX_IMAX_2mA", "AW22XXX_IMAX_3mA", "AW22XXX_IMAX_4mA",
	"AW22XXX_IMAX_6mA", "AW22XXX_IMAX_9mA", "AW22XXX_IMAX_10mA",
	"AW22XXX_IMAX_15mA", "AW22XXX_IMAX_20mA", "AW22XXX_IMAX_30mA",
	"AW22XXX_IMAX_40mA", "AW22XXX_IMAX_45mA", "AW22XXX_IMAX_60mA",
	"AW22XXX_IMAX_75mA"
};

static const u8 aw22xxx_reg_access[256] = {
	[0x00] = 0x01, [0x01] = 0x03, [0x02] = 0x03, [0x03] = 0x03, [0x04] = 0x03, [0x05] = 0x03, [0x06] = 0x03, [0x07] = 0x01,
	[0x08] = 0x03, [0x09] = 0x03, [0x0A] = 0x03, [0x0B] = 0x03, [0x0C] = 0x03, [0x0D] = 0x03, [0x0E] = 0x01, [0x0F] = 0x03,
	[0x10] = 0x03,
	[0x20] = 0x03, [0x21] = 0x03, [0x22] = 0x03, [0x23] = 0x03, [0x24] = 0x03, [0x25] = 0x01, [0x26] = 0x01,
	[0x30] = 0x03, [0x31] = 0x03, [0x32] = 0x03, [0x33] = 0x03, [0x34] = 0x03, [0x35] = 0x03, [0x36] = 0x03, [0x37] = 0x03,
	[0x38] = 0x03, [0x39] = 0x03,
	[0xFF] = 0x03
};

static u8 aw22xxx_blink_cfg[] = {
	0xFF, 0x00, 0x0C, 0x00, 0x05, 0x00, 0x06, 0xFF, 0x04, 0x07, 0x05, 0x00,
	0x06, 0x00, 0x04, 0x07, 0x05, 0x00, 0x06, 0x00, 0x04, 0x07, 0x05, 0x00,
	0x06, 0x00, 0x04, 0x07, 0x05, 0x00, 0x06, 0xFF, 0x04, 0x07, 0x05, 0x00,
	0x06, 0x00, 0x04, 0x07, 0x05, 0x00, 0x06, 0x00, 0x04, 0x07, 0x05, 0x00,
	0x06, 0x00, 0x04, 0x07, 0x05, 0x00, 0x06, 0xFF, 0x04, 0x07, 0x05, 0x00,
	0x06, 0xFF, 0x04, 0x07, 0x05, 0x00, 0x06, 0xFF, 0x04, 0x07, 0x05, 0x00,
	0x06, 0xFF, 0x04, 0x07, 0x05, 0x00, 0x06, 0xFF, 0x04, 0x07, 0x05, 0x00,
	0x06, 0xFF, 0x04, 0x07, 0x05, 0x00, 0x06, 0xFF, 0x04, 0x07, 0x05, 0x00,
	0x06, 0xFF, 0x04, 0x07, 0x05, 0x00, 0x06, 0xFF, 0x04, 0x07, 0x05, 0x00,
	0x06, 0xFF, 0x04, 0x07, 0x05, 0x00, 0x06, 0xFF, 0x04, 0x07, 0x05, 0x00,
	0x06, 0xFF, 0x04, 0x07, 0x05, 0x00, 0x06, 0xFF, 0x04, 0x07, 0x05, 0x00,
	0x06, 0xFF, 0x04, 0x07, 0x05, 0x00, 0x06, 0xFF, 0x04, 0x07, 0x05, 0x00,
	0x06, 0xFF, 0x04, 0x07, 0x05, 0x00, 0x06, 0xFF, 0x04, 0x07
};

/* Prototypes */
static int aw22xxx_i2c_write(struct aw22xxx *aw22xxx, u8 reg, u8 val);
static int aw22xxx_i2c_read(struct aw22xxx *aw22xxx, u8 reg, u8 *val);
static int aw22xxx_hw_reset(struct aw22xxx *aw22xxx);
static int aw22xxx_led_init(struct aw22xxx *aw22xxx);
static int aw22xxx_init_cfg_update_array(struct aw22xxx *aw22xxx);
static void aw22xxx_cfg_loaded(const struct firmware *fw, void *context);
static void aw22xxx_fw_loaded(const struct firmware *fw, void *context);
static int aw22xxx_cfg_update_wait_from_dyn_name(struct aw22xxx *aw22xxx);
static int aw22xxx_set_cfg_run_state(u32 effect);

/* ======================================================================
 * I2C and Hardware Operations
 * ====================================================================== */

static int aw22xxx_i2c_write(struct aw22xxx *aw22xxx, u8 reg, u8 val)
{
	struct i2c_client *client = aw22xxx->i2c;
	u8 buf[2] = { reg, val };
	int ret;

	ret = i2c_master_send(client, buf, 2);
	if (ret < 0) {
		gpiod_get_value(gpio_to_desc(aw22xxx->reset_gpio));
		pr_err("aw22xxx: %s: i2c master send error retry 1\n", __func__);
		msleep(1);
		ret = i2c_master_send(client, buf, 2);
		if (ret < 0) {
			gpiod_get_value(gpio_to_desc(aw22xxx->reset_gpio));
			pr_err("aw22xxx: %s: i2c master send error retry 2, hw reset\n", __func__);
			gpiod_direction_output(gpio_to_desc(aw22xxx->reset_gpio), 1);
			msleep(1);
		}
	}
	return ret >= 0 ? 0 : ret;
}

static int aw22xxx_i2c_read(struct aw22xxx *aw22xxx, u8 reg, u8 *val)
{
	struct i2c_client *client = aw22xxx->i2c;
	int ret;

	ret = i2c_master_send(client, &reg, 1);
	if (ret < 0) {
		pr_err("aw22xxx: %s: i2c read reg send failed\n", __func__);
		msleep(1);
		ret = i2c_master_send(client, &reg, 1);
		if (ret < 0)
			return ret;
	}

	ret = i2c_master_recv(client, val, 1);
	if (ret < 0) {
		*val = ret;
		pr_err("aw22xxx: %s: i2c read recv failed\n", __func__);
		msleep(1);
		ret = i2c_master_recv(client, val, 1);
	}
	return ret >= 0 ? 0 : ret;
}

static int aw22xxx_hw_reset(struct aw22xxx *aw22xxx)
{
	struct gpio_desc *desc;
	pr_info("aw22xxx: %s\n", __func__);
	if (!aw22xxx || (aw22xxx->reset_gpio & 0x80000000)) {
		dev_err(aw22xxx->dev, "%s: reset_gpio invalid\n", __func__);
		return -EINVAL;
	}

	desc = gpio_to_desc(aw22xxx->reset_gpio);
	gpiod_set_value_cansleep(desc, 0);
	usleep_range(1000, 1500);
	gpiod_set_value_cansleep(desc, 1);
	usleep_range(1000, 1500);
	return 0;
}

static int aw22xxx_read_chipid(struct aw22xxx *aw22xxx)
{
	u8 val = 0;
	int ret;

	aw22xxx_i2c_write(aw22xxx, 255, 0);
	aw22xxx_i2c_write(aw22xxx, 1, 85);
	usleep_range(2000, 3000);

	ret = aw22xxx_i2c_read(aw22xxx, 1, &val);
	if (ret < 0)
		goto err;

	if (val != 118) {
		pr_info("aw22xxx: chip_id != 118, retrying\n");
		msleep(1);
		ret = aw22xxx_i2c_read(aw22xxx, 1, &val);
		if (ret < 0 || val != 118) {
			pr_err("aw22xxx: read chipid check failed: %d\n", val);
			return -ENODEV;
		}
	}

	aw22xxx_i2c_read(aw22xxx, 0, &val);
	if (val == 24) {
		aw22xxx->chip_type = 1;
		g_chip_id = 0x38313132327761ULL; // "aw22118"
		pr_info("aw22xxx: detected aw22118 chip\n");
		return 0;
	} else if (val == 39) {
		aw22xxx->chip_type = 2;
		g_chip_id = 0x37323132327761ULL; // "aw22127"
		pr_info("aw22xxx: detected aw22127 chip\n");
		return 0;
	}

	pr_err("aw22xxx: unknown chip id register value: %d\n", val);
	return -ENODEV;

err:
	dev_err(aw22xxx->dev, "aw22xxx: failed to read AW22XXX_REG_ID: %d\n", ret);
	return ret;
}

static int aw22xxx_led_init(struct aw22xxx *aw22xxx)
{
	u8 val = 0;
	u8 imax_val;
	pr_info("aw22xxx: %s\n", __func__);

	aw22xxx_i2c_write(aw22xxx, 1, 85);
	usleep_range(2000, 3000);

	aw22xxx_i2c_read(aw22xxx, 2, &val);
	val |= 1;
	aw22xxx_i2c_write(aw22xxx, 2, val);
	usleep_range(2000, 3000);

	if (aw22xxx->imax >= 13)
		return -EINVAL;

	imax_val = aw22xxx_imax_code[aw22xxx->imax];
	if (imax_val >= 15)
		imax_val = 15;

	aw22xxx_i2c_write(aw22xxx, 255, 0);
	aw22xxx_i2c_write(aw22xxx, 11, imax_val);

	aw22xxx_i2c_read(aw22xxx, 2, &val);
	val &= ~1;
	aw22xxx_i2c_write(aw22xxx, 2, val);
	usleep_range(2000, 3000);

	return 0;
}

static int aw22xxx_init_cfg_update_array(struct aw22xxx *aw22xxx)
{
	u8 val = 0;
	pr_info("aw22xxx: %s\n", __func__);

	aw22xxx_i2c_read(aw22xxx, 2, &val);
	val |= 1;
	aw22xxx_i2c_write(aw22xxx, 2, val);
	usleep_range(2000, 3000);

	aw22xxx_i2c_write(aw22xxx, 255, 0);
	aw22xxx_i2c_write(aw22xxx, 2, 1);
	aw22xxx_i2c_write(aw22xxx, 12, 0);
	aw22xxx_i2c_write(aw22xxx, 11, 5);
	aw22xxx_i2c_write(aw22xxx, 5, 1);
	aw22xxx_i2c_write(aw22xxx, 4, 1);
	aw22xxx_i2c_write(aw22xxx, 9, 1);
	aw22xxx_i2c_write(aw22xxx, 4, 3);
	aw22xxx_i2c_write(aw22xxx, 5, 65);

	return 0;
}

/* ======================================================================
 * Firmware Loading & Configuration
 * ====================================================================== */

static int aw22xxx_get_fwname(u32 index)
{
	u8 mode = (index >> 24) & 0xFF;
	u32 v3 = (index >> 12) & 0xFFF;
	u32 v4 = index & 0xFFF;

	pr_info("aw22xxx: %s mode=%d, v3=%x, v4=%x\n", __func__, mode, v3, v4);

	if (mode == 1) {
		snprintf(aw22xxx_dyn_name, sizeof(aw22xxx_dyn_name), "aw_cfg%x_%x.bin", v3, v4);
		return 0;
	} else if (mode == 2) {
		snprintf(aw22xxx_dyn_name, sizeof(aw22xxx_dyn_name), "aw_touch%x_%x.bin", v3, v4);
		return 0;
	} else if (mode == 3) {
		snprintf(aw22xxx_dyn_name, sizeof(aw22xxx_dyn_name), "aw_fan%x_%x.bin", v3, v4);
		return 0;
	}

	if (v4 >= 12)
		return -EINVAL;

	strscpy(aw22xxx_dyn_name, aw22xxx_cfg_name[index], sizeof(aw22xxx_dyn_name));
	return 0;
}

static void aw22xxx_cfg_loaded(const struct firmware *fw, void *context)
{
	struct aw22xxx *aw22xxx = context;
	size_t offset = 0;
	u8 w22 = 0;
	pr_info("aw22xxx: %s\n", __func__);

	if (!fw) {
		pr_err("aw22xxx: cfg firmware NULL\n");
		return;
	}

	if (fw->size == 0) {
		release_firmware(fw);
		if (aw22xxx->imax < 13) {
			u8 imax_code = aw22xxx_imax_code[aw22xxx->imax];
			aw22xxx_i2c_write(aw22xxx, 255, 0);
			aw22xxx_i2c_write(aw22xxx, 11, imax_code >= 15 ? 15 : imax_code);
		}
		return;
	}

	while (offset < fw->size) {
		const u8 *ptr = fw->data + offset;
		u8 reg = ptr[0];
		u8 val = ptr[1];

		if (reg == 255)
			w22 = val;

		if (aw22xxx->cfg_custom_en && w22 == 1 && reg >= 16 && reg <= 43) {
			int reg_offset = reg - 16;
			int led_index = reg_offset / 3;
			int color_channel = reg_offset % 3;
			int shift = 16 - (color_channel * 8);
			val = (aw22xxx->rgb_val[led_index] >> shift) & 0xFF;
		}

		aw22xxx_i2c_write(aw22xxx, reg, val);

		if (w22 != 0 && reg == 2 && (val & 1)) {
			usleep_range(2000, 2500);
		}
		offset += 2;
	}

	release_firmware(fw);
}

static void aw22xxx_fw_loaded(const struct firmware *fw, void *context)
{
	struct aw22xxx *aw22xxx = context;
	size_t size;
	const u16 *fw_words;
	u16 checksum = 0;
	size_t i;
	u32 *fw_buf;
	size_t fw_buf_size;
	u8 val = 0;

	pr_info("aw22xxx: %s\n", __func__);
	if (!fw) {
		pr_err("aw22xxx: fw firmware NULL\n");
		return;
	}

	size = fw->size;
	fw_words = (const u16 *)fw->data;

	if (size < 3) {
		checksum = 0;
	} else {
		for (i = 1; i < size / 2; i++) {
			checksum += be16_to_cpu(fw_words[i]);
		}
	}

	if (checksum != be16_to_cpu(fw_words[0])) {
		pr_err("aw22xxx: fw checksum mismatch\n");
		release_firmware(fw);
		return;
	}

	pr_info("aw22xxx: fw checksum valid\n");
	fw_buf_size = size + 16;
	fw_buf = kzalloc(fw_buf_size, GFP_KERNEL);
	if (!fw_buf) {
		release_firmware(fw);
		return;
	}

	fw_buf[1] = be32_to_cpup((const __be32 *)(fw->data + 27));
	fw_buf[2] = swab16(*(u16 *)(fw->data + 34));
	fw_buf[3] = *(u8 *)(fw->data + 36);
	fw_buf[0] = swab16(*(u16 *)(fw->data + 38));

	memcpy(fw_buf + 4, fw->data + 40, fw_buf[0]);
	release_firmware(fw);

	aw22xxx_i2c_write(aw22xxx, 1, 85);
	usleep_range(2000, 3000);

	aw22xxx_i2c_read(aw22xxx, 2, &val);
	val |= 1;
	aw22xxx_i2c_write(aw22xxx, 2, val);
	usleep_range(2000, 3000);

	aw22xxx_i2c_read(aw22xxx, 4, &val);
	val |= 1;
	aw22xxx_i2c_write(aw22xxx, 4, val);

	aw22xxx_i2c_write(aw22xxx, 34, ((fw_buf[0] - 1) >> 8) & 0xFF);
	aw22xxx_i2c_write(aw22xxx, 33, (fw_buf[0] - 1) & 0xFF);
	aw22xxx_i2c_write(aw22xxx, 36, 7);
	usleep_range(5000, 6500);

	aw22xxx_i2c_read(aw22xxx, 36, &val);
	if (val == 5) {
		u8 check_val1 = 0, check_val2 = 0;
		aw22xxx_i2c_read(aw22xxx, 37, &check_val1);
		aw22xxx_i2c_read(aw22xxx, 38, &check_val2);
		if ((check_val1 | (check_val2 << 8)) == fw_buf[2]) {
			pr_info("aw22xxx: fw boot loaded ok\n");
			if (!aw22xxx->init_flag) {
				kfree(fw_buf);
				aw22xxx_i2c_write(aw22xxx, 36, 0);
				aw22xxx_led_init(aw22xxx);
				aw22xxx->container_update_state = 2;
				return;
			}
		} else {
			pr_err("aw22xxx: boot loading check error\n");
		}
	} else {
		pr_err("aw22xxx: boot loader status error: %d\n", val);
	}

	aw22xxx_i2c_write(aw22xxx, 36, 0);
	aw22xxx_i2c_write(aw22xxx, 255, 0);
	aw22xxx_i2c_write(aw22xxx, 1, 85);
	usleep_range(2000, 3000);

	aw22xxx_i2c_read(aw22xxx, 2, &val);
	val |= 1;
	aw22xxx_i2c_write(aw22xxx, 2, val);
	usleep_range(2000, 3000);

	aw22xxx_i2c_read(aw22xxx, 4, &val);
	val |= 1;
	aw22xxx_i2c_write(aw22xxx, 4, val);

	aw22xxx_i2c_write(aw22xxx, 128, 236);
	aw22xxx_i2c_write(aw22xxx, 53, 41);
	aw22xxx_i2c_write(aw22xxx, 56, fw_buf[3]);
	aw22xxx_i2c_write(aw22xxx, 34, 0);
	aw22xxx_i2c_write(aw22xxx, 33, 0);
	aw22xxx_i2c_write(aw22xxx, 32, 3);
	aw22xxx_i2c_write(aw22xxx, 48, 3);
	aw22xxx_i2c_write(aw22xxx, 35, 0);

	if (g_ver_var < 12)
		msleep(40);
	else
		usleep_range(4000, 4500);

	aw22xxx_i2c_write(aw22xxx, 48, 0);
	aw22xxx_i2c_write(aw22xxx, 34, 64);
	aw22xxx_i2c_write(aw22xxx, 33, 0);
	aw22xxx_i2c_write(aw22xxx, 48, 2);
	aw22xxx_i2c_write(aw22xxx, 35, 0);
	usleep_range(6000, 6500);

	aw22xxx_i2c_write(aw22xxx, 48, 0);
	aw22xxx_i2c_write(aw22xxx, 34, 66);
	aw22xxx_i2c_write(aw22xxx, 33, 0);
	aw22xxx_i2c_write(aw22xxx, 48, 2);
	aw22xxx_i2c_write(aw22xxx, 35, 0);
	usleep_range(6000, 6500);

	aw22xxx_i2c_write(aw22xxx, 48, 0);
	aw22xxx_i2c_write(aw22xxx, 34, 68);
	aw22xxx_i2c_write(aw22xxx, 33, 0);
	aw22xxx_i2c_write(aw22xxx, 48, 2);
	aw22xxx_i2c_write(aw22xxx, 35, 0);
	usleep_range(6000, 6500);

	aw22xxx_i2c_write(aw22xxx, 48, 0);
	aw22xxx_i2c_write(aw22xxx, 32, 0);
	aw22xxx_i2c_write(aw22xxx, 32, 3);

	if (fw_buf[0]) {
		u32 written = 0;
		do {
			u32 chunk;
			u8 *send_buf;
			aw22xxx_i2c_write(aw22xxx, 34, (written >> 8) & 0xFF);
			aw22xxx_i2c_write(aw22xxx, 33, written & 0xFF);
			aw22xxx_i2c_write(aw22xxx, 17, 1);
			aw22xxx_i2c_write(aw22xxx, 48, 4);

			chunk = fw_buf[0] - written;
			if (chunk >= 128)
				chunk = 128;

			send_buf = kmalloc(chunk + 1, GFP_KERNEL);
			if (send_buf) {
				send_buf[0] = 35; // register 35
				memcpy(send_buf + 1, (u8 *)(fw_buf + 4) + written, chunk);
				if (i2c_master_send(aw22xxx->i2c, send_buf, chunk + 1) < 0) {
					pr_err("aw22xxx: firmware writes block send error\n");
				}
				kfree(send_buf);
			}
			aw22xxx_i2c_write(aw22xxx, 17, 0);
			aw22xxx_i2c_write(aw22xxx, 48, 0);
			written += chunk;
		} while (written < fw_buf[0]);
	}

	aw22xxx_i2c_write(aw22xxx, 32, 0);
	aw22xxx_i2c_write(aw22xxx, 1, 85);
	usleep_range(2000, 3000);

	aw22xxx_i2c_read(aw22xxx, 2, &val);
	val |= 1;
	aw22xxx_i2c_write(aw22xxx, 2, val);
	usleep_range(2000, 3000);

	aw22xxx_i2c_read(aw22xxx, 4, &val);
	val |= 1;
	aw22xxx_i2c_write(aw22xxx, 4, val);

	aw22xxx_i2c_write(aw22xxx, 34, ((fw_buf[0] - 1) >> 8) & 0xFF);
	aw22xxx_i2c_write(aw22xxx, 33, (fw_buf[0] - 1) & 0xFF);
	aw22xxx_i2c_write(aw22xxx, 36, 7);
	usleep_range(5000, 6500);

	aw22xxx_i2c_read(aw22xxx, 36, &val);
	if (val == 5) {
		u8 check_val1 = 0, check_val2 = 0;
		aw22xxx_i2c_read(aw22xxx, 37, &check_val1);
		aw22xxx_i2c_read(aw22xxx, 38, &check_val2);
		if ((check_val1 | (check_val2 << 8)) != fw_buf[2]) {
			pr_err("aw22xxx: container boot verify error\n");
			aw22xxx->container_update_state = 3;
		} else {
			pr_info("aw22xxx: container boot verify success\n");
			aw22xxx->container_update_state = 2;
		}
	} else {
		pr_err("aw22xxx: container boot verify failed state: %d\n", val);
		aw22xxx->container_update_state = 3;
	}

	aw22xxx_i2c_write(aw22xxx, 36, 0);
	kfree(fw_buf);
	aw22xxx->init_flag = 0;
	aw22xxx_led_init(aw22xxx);
}

static int aw22xxx_cfg_update_wait_from_dyn_name(struct aw22xxx *aw22xxx)
{
	const struct firmware *fw = NULL;
	int ret;

	pr_info("aw22xxx: %s\n", __func__);
	if (aw22xxx->container_update_state != 2) {
		pr_err("aw22xxx: %s: container update state incorrect\n", __func__);
		return -EINVAL;
	}

	if (aw22xxx->effect != 2) {
		aw22xxx->need_update = 1;
		if (!g_init_flg) {
			g_init_flg = 1;
			aw22xxx_init_cfg_update_array(aw22xxx);
		}
	} else {
		aw22xxx->need_update = 0;
		if (!g_init_flg) {
			g_init_flg = 1;
			aw22xxx_init_cfg_update_array(aw22xxx);
		}
	}

	ret = request_firmware(&fw, aw22xxx_dyn_name, aw22xxx->dev);
	if (ret) {
		pr_err("aw22xxx: failed to request cfg firmware: %d\n", ret);
		return ret;
	}

	aw22xxx_cfg_loaded(fw, aw22xxx);
	msleep(20);
	return 0;
}

static int aw22xxx_set_cfg_run_state(u32 effect)
{
	u8 mode = (effect >> 24) & 0xFF;
	u32 sub_mode = (effect >> 12) & 0xFFF;
	int next_state;

	pr_info("aw22xxx: %s: effect=0x%x\n", __func__, effect);

	if (mode == 1 && sub_mode == 0) {
		next_state = g_cfg_cur_state & ~2;
	} else if (mode == 3 && sub_mode == 0) {
		next_state = g_cfg_cur_state & ~1;
	} else if (mode == 3 && sub_mode == 2) {
		next_state = g_cfg_cur_state | 1;
	} else if (mode == 2 && sub_mode == 0) {
		next_state = g_cfg_cur_state & ~4;
	} else if (mode == 2 && sub_mode >= 257 && sub_mode <= 260) {
		next_state = g_cfg_cur_state | 4;
	} else {
		next_state = g_cfg_cur_state | (mode == 3 ? 1 : 2);
	}

	g_cfg_cur_state = next_state;
	return 0;
}

/* ======================================================================
 * Workqueues & Timers & Kthreads
 * ====================================================================== */

static void aw22xxx_brightness_work(struct work_struct *work)
{
	struct aw22xxx *aw22xxx = container_of(work, struct aw22xxx, brightness_work);
	u8 val = 0;
	pr_info("aw22xxx: %s\n", __func__);

	aw22xxx_i2c_write(aw22xxx, 5, 255);
	aw22xxx_i2c_read(aw22xxx, 4, &val);
	val &= ~2;
	aw22xxx_i2c_write(aw22xxx, 4, val);

	aw22xxx_i2c_read(aw22xxx, 2, &val);
	val &= ~1;
	aw22xxx_i2c_write(aw22xxx, 2, val);
	usleep_range(2000, 3000);

	if (aw22xxx->cdev.brightness) {
		u8 imax_val;
		aw22xxx_i2c_read(aw22xxx, 2, &val);
		val |= 1;
		aw22xxx_i2c_write(aw22xxx, 2, val);
		usleep_range(2000, 3000);

		aw22xxx_i2c_read(aw22xxx, 4, &val);
		val |= 1;
		aw22xxx_i2c_write(aw22xxx, 4, val);

		imax_val = aw22xxx->imax >= 15 ? 15 : aw22xxx->imax;
		aw22xxx_i2c_write(aw22xxx, 255, 0);
		aw22xxx_i2c_write(aw22xxx, 11, imax_val);
		aw22xxx_i2c_write(aw22xxx, 33, 225);
		aw22xxx_i2c_write(aw22xxx, 34, 0);
		aw22xxx_i2c_write(aw22xxx, 32, 2);
		aw22xxx_i2c_write(aw22xxx, 35, 61);
		aw22xxx_i2c_write(aw22xxx, 32, 0);
		aw22xxx_i2c_write(aw22xxx, 5, 130);

		aw22xxx_i2c_read(aw22xxx, 4, &val);
		val |= 2;
		aw22xxx_i2c_write(aw22xxx, 4, val);
	}
}

static void aw22xxx_task_work(struct work_struct *work)
{
	struct aw22xxx *aw22xxx = container_of(work, struct aw22xxx, task_work);
	u8 val = 0;
	pr_info("aw22xxx: %s\n", __func__);

	aw22xxx_i2c_write(aw22xxx, 5, 255);
	aw22xxx_i2c_read(aw22xxx, 4, &val);
	val &= ~2;
	aw22xxx_i2c_write(aw22xxx, 4, val);

	aw22xxx_i2c_read(aw22xxx, 2, &val);
	val &= ~1;
	aw22xxx_i2c_write(aw22xxx, 2, val);
	usleep_range(2000, 3000);

	if (aw22xxx->task0) {
		u8 imax_val;
		aw22xxx_i2c_read(aw22xxx, 2, &val);
		val |= 1;
		aw22xxx_i2c_write(aw22xxx, 2, val);
		usleep_range(2000, 3000);

		aw22xxx_i2c_read(aw22xxx, 4, &val);
		val |= 1;
		aw22xxx_i2c_write(aw22xxx, 4, val);

		imax_val = aw22xxx->imax >= 15 ? 15 : aw22xxx->imax;
		aw22xxx_i2c_write(aw22xxx, 255, 0);
		aw22xxx_i2c_write(aw22xxx, 11, imax_val);
		aw22xxx_i2c_write(aw22xxx, 33, 225);
		aw22xxx_i2c_write(aw22xxx, 34, 0);
		aw22xxx_i2c_write(aw22xxx, 32, 2);
		aw22xxx_i2c_write(aw22xxx, 35, 61);
		aw22xxx_i2c_write(aw22xxx, 32, 0);
		aw22xxx_i2c_write(aw22xxx, 5, aw22xxx->task0);
		aw22xxx_i2c_write(aw22xxx, 6, aw22xxx->task1);

		aw22xxx_i2c_read(aw22xxx, 4, &val);
		val |= 2;
		aw22xxx_i2c_write(aw22xxx, 4, val);
	}
}

static void aw22xxx_fw_work_routine(struct work_struct *work)
{
	struct aw22xxx *aw22xxx = container_of(work, struct aw22xxx, fw_work);
	pr_info("aw22xxx: %s\n", __func__);
	aw22xxx->container_update_state = 1;
	request_firmware_nowait(THIS_MODULE, 1, aw22xxx_fw_name, aw22xxx->dev,
				GFP_KERNEL, aw22xxx, aw22xxx_fw_loaded);
}

static void aw22xxx_cfg_work_routine(struct work_struct *work)
{
	struct aw22xxx *aw22xxx = container_of(work, struct aw22xxx, cfg_work);
	pr_info("aw22xxx: %s\n", __func__);

	if (aw22xxx->container_update_state != 2)
		return;

	if (aw22xxx->effect == 2) {
		aw22xxx->need_update = 0;
	} else {
		aw22xxx->need_update = 1;
	}

	if (!g_init_flg) {
		g_init_flg = 1;
		aw22xxx_init_cfg_update_array(aw22xxx);
	}

	request_firmware_nowait(THIS_MODULE, 1, aw22xxx_dyn_name, aw22xxx->dev,
				GFP_KERNEL, aw22xxx, aw22xxx_cfg_loaded);
}

static void aw22xxx_recover_work_routine(struct work_struct *work)
{
	struct aw22xxx *aw22xxx = container_of(work, struct aw22xxx, recover_work);
	pr_info("aw22xxx: %s\n", __func__);
	(void)aw22xxx;
}

static enum hrtimer_restart aw22xxx_fw_timer_func(struct hrtimer *timer)
{
	struct aw22xxx *aw22xxx = container_of(timer, struct aw22xxx, timer);
	pr_info("aw22xxx: %s\n", __func__);
	schedule_work(&aw22xxx->fw_work);
	return HRTIMER_NORESTART;
}

static void aw22xxx_fw_init(struct aw22xxx *aw22xxx)
{
	hrtimer_init(&aw22xxx->timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
	aw22xxx->timer.function = aw22xxx_fw_timer_func;

	INIT_WORK(&aw22xxx->fw_work, aw22xxx_fw_work_routine);
	INIT_WORK(&aw22xxx->cfg_work, aw22xxx_cfg_work_routine);

	if (g_ver_var == 11) {
		INIT_WORK(&aw22xxx->recover_work, aw22xxx_recover_work_routine);
	}

	pr_info("aw22xxx: %s starting timer\n", __func__);
	hrtimer_start(&aw22xxx->timer, ktime_set(1, 0), HRTIMER_MODE_REL);
}

static int aw22xxx_alloc_name_array(void)
{
	int i;
	aw22xxx_cfg_name = kmalloc_array(11, sizeof(char *), GFP_KERNEL);
	if (!aw22xxx_cfg_name)
		return -ENOMEM;

	for (i = 0; i < 11; i++) {
		aw22xxx_cfg_name[i] = kmalloc(64, GFP_KERNEL);
		if (!aw22xxx_cfg_name[i])
			goto err;
	}

	strcpy(aw22xxx_cfg_name[0], "m_led_off.bin");
	strcpy(aw22xxx_cfg_name[1], "fan_led_on.bin");
	strcpy(aw22xxx_cfg_name[2], "fan_led_off.bin");
	strcpy(aw22xxx_cfg_name[3], "touch_led_off.bin");
	strcpy(aw22xxx_cfg_name[4], "lamps_init.bin");
	strcpy(aw22xxx_cfg_name[5], "nubia_all_rgb_red.bin");
	strcpy(aw22xxx_cfg_name[6], "nubia_all_rgb_green.bin");
	strcpy(aw22xxx_cfg_name[7], "nubia_all_rgb_blue.bin");
	strcpy(aw22xxx_cfg_name[8], "nubia_all_rgb_red.bin");
	strcpy(aw22xxx_cfg_name[9], "nubia_all_rgb_green.bin");
	strcpy(aw22xxx_cfg_name[10], "nubia_all_rgb_blue.bin");
	return 0;

err:
	while (--i >= 0)
		kfree(aw22xxx_cfg_name[i]);
	kfree(aw22xxx_cfg_name);
	aw22xxx_cfg_name = NULL;
	return -ENOMEM;
}

static ssize_t aw22xxx_set_breath_data(struct aw22xxx *aw22xxx, const u8 *a2)
{
	int i;

	aw22xxx_blink_cfg[5]   = a2[8];
	aw22xxx_blink_cfg[11]  = a2[9];
	aw22xxx_blink_cfg[17]  = a2[10];
	aw22xxx_blink_cfg[23]  = a2[11];
	aw22xxx_blink_cfg[29]  = a2[12];
	aw22xxx_blink_cfg[35]  = a2[13];
	aw22xxx_blink_cfg[41]  = a2[14];
	aw22xxx_blink_cfg[47]  = a2[15];
	aw22xxx_blink_cfg[53]  = a2[16];
	aw22xxx_blink_cfg[59]  = a2[17];
	aw22xxx_blink_cfg[65]  = a2[18];
	aw22xxx_blink_cfg[71]  = a2[19];

	aw22xxx_blink_cfg[77]  = a2[20];
	aw22xxx_blink_cfg[83]  = a2[20];
	aw22xxx_blink_cfg[89]  = a2[20];

	aw22xxx_blink_cfg[95]  = a2[21];
	aw22xxx_blink_cfg[101] = a2[21];
	aw22xxx_blink_cfg[107] = a2[21];

	aw22xxx_blink_cfg[113] = a2[22];
	aw22xxx_blink_cfg[119] = a2[22];
	aw22xxx_blink_cfg[125] = a2[22];

	aw22xxx_blink_cfg[131] = a2[23];
	aw22xxx_blink_cfg[137] = a2[23];
	aw22xxx_blink_cfg[143] = a2[23];

	duration = a2[24];

	for (i = 0; i < ARRAY_SIZE(aw22xxx_blink_cfg); i += 2) {
		aw22xxx_i2c_write(aw22xxx, aw22xxx_blink_cfg[i], aw22xxx_blink_cfg[i + 1]);
	}
	return 0;
}

static int aw22xxx_play(void *data)
{
	struct aw22xxx *aw22xxx = data;
	pr_info("aw22xxx: %s start\n", __func__);
	aw22xxx_init_cfg_update_array(aw22xxx);
	aw22xxx_set_breath_data(aw22xxx, (const u8 *)user_para_data);

	while (!kthread_should_stop() && kthread_status) {
		msleep(duration / 30);
		if (read_idx == write_idx) {
			kthread_status = 0;
			read_idx = 0;
			write_idx = 0;
			schedule_work(&aw22xxx->cfg_work);
			pr_info("aw22xxx: %s finished playing patterns\n", __func__);
			break;
		}

		if (read_idx * 25 >= 25000)
			break;

		aw22xxx_set_breath_data(aw22xxx, (const u8 *)&user_para_data[25 * read_idx]);
		read_idx++;
	}

	if (!kthread_status) {
		aw22xxx_i2c_write(aw22xxx, 255, 0);
		aw22xxx_i2c_write(aw22xxx, 5, 0);
		aw22xxx_i2c_write(aw22xxx, 4, 1);
		aw22xxx_i2c_write(aw22xxx, 2, 0);
	}

	return 0;
}

/* ======================================================================
 * Sysfs Callbacks
 * ====================================================================== */

static ssize_t cfg_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	u32 effect = aw22xxx->effect;

	if (effect > 10) {
		pr_err("aw22xxx: invalid effect index in cfg_show: %d\n", effect);
		return -EINVAL;
	}
	return snprintf(buf, PAGE_SIZE, "current cfg = %s\n", aw22xxx_cfg_name[effect]);
}

static ssize_t cfg_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	u32 val = 0;

	if (sscanf(buf, "%x", &val) != 1)
		return -EINVAL;

	mutex_lock(&aw22xxx->cfg_lock);
	aw22xxx->effect = val;
	aw22xxx_get_fwname(val);
	aw22xxx_cfg_update_wait_from_dyn_name(aw22xxx);
	mutex_unlock(&aw22xxx->cfg_lock);
	return count;
}

static ssize_t effect_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	return snprintf(buf, PAGE_SIZE, "effect = 0x%02x\n", aw22xxx->effect);
}

static ssize_t effect_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	u32 val = 0;
	u8 reg_val = 0;

	if (sscanf(buf, "%x", &val) != 1)
		return -EINVAL;

	mutex_lock(&aw22xxx->cfg_lock);
	if ((val - 8) <= 2 && init_flag == 1) {
		aw22xxx->effect = 4;
		aw22xxx_get_fwname(4);
		aw22xxx_cfg_update_wait_from_dyn_name(aw22xxx);
		aw22xxx_set_cfg_run_state(aw22xxx->effect);
		if (!g_cfg_cur_state) {
			aw22xxx_i2c_read(aw22xxx, 2, &reg_val);
			reg_val &= ~1;
			aw22xxx_i2c_write(aw22xxx, 2, reg_val);
			usleep_range(2000, 3000);
			g_init_flg = 0;
		}
		init_flag = 0;
	}

	aw22xxx->effect = val;
	if (val <= 3 && val != 1 && !init_flag) {
		init_flag = 1;
	}

	aw22xxx_get_fwname(aw22xxx->effect);
	aw22xxx_cfg_update_wait_from_dyn_name(aw22xxx);

	if (aw22xxx->effect == 0)
		msleep(100);

	aw22xxx_set_cfg_run_state(aw22xxx->effect);

	if (!g_cfg_cur_state) {
		aw22xxx_i2c_read(aw22xxx, 2, &reg_val);
		reg_val &= ~1;
		aw22xxx_i2c_write(aw22xxx, 2, reg_val);
		usleep_range(2000, 3000);
		g_init_flg = 0;
	}
	mutex_unlock(&aw22xxx->cfg_lock);
	return count;
}

static ssize_t fw_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	return snprintf(buf, PAGE_SIZE, "firmware name = %s\n", aw22xxx_fw_name);
}

static ssize_t fw_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	char name[64];

	if (sscanf(buf, "%63s", name) != 1)
		return -EINVAL;

	mutex_lock(&aw22xxx->cfg_lock);
	strscpy(aw22xxx_fw_name, name, sizeof(aw22xxx_fw_name));
	schedule_work(&aw22xxx->fw_work);
	mutex_unlock(&aw22xxx->cfg_lock);
	return count;
}

static ssize_t hwen_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	int val = gpiod_get_value(gpio_to_desc(aw22xxx->reset_gpio));
	return snprintf(buf, PAGE_SIZE, "hwen=%d\n", val);
}

static ssize_t hwen_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	u32 val = 0;

	if (sscanf(buf, "%x", &val) != 1 || val >= 2)
		return -EINVAL;

	if (val == 1) {
		aw22xxx_hw_reset(aw22xxx);
	} else {
		pr_info("aw22xxx: hw off\n");
		if (aw22xxx->reset_gpio & 0x80000000) {
			dev_err(aw22xxx->dev, "aw22xxx_hw_off failed\n");
		} else {
			gpiod_set_value_cansleep(gpio_to_desc(aw22xxx->reset_gpio), 0);
			usleep_range(1000, 1500);
		}
	}
	return count;
}

static ssize_t imax_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	size_t len = 0;
	int i;

	for (i = 0; i < 13; i++) {
		len += snprintf(buf + len, PAGE_SIZE - len, "imax[%x] = %s\n", i, aw22xxx_imax_name[i]);
	}

	if (aw22xxx->imax < 13) {
		len += snprintf(buf + len, PAGE_SIZE - len, "current id = 0x%02x, imax = %s\n",
				aw22xxx->imax, aw22xxx_imax_name[aw22xxx->imax]);
	}
	return len;
}

static ssize_t imax_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	u32 val = 0;
	u8 code;

	if (sscanf(buf, "%x", &val) != 1 || val >= 13)
		return -EINVAL;

	aw22xxx->imax = val;
	code = aw22xxx_imax_code[val];
	if (code >= 15)
		code = 15;

	aw22xxx_i2c_write(aw22xxx, 255, 0);
	aw22xxx_i2c_write(aw22xxx, 11, code);
	return count;
}

static ssize_t para_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	size_t len = 0;
	int i;

	if (!write_idx)
		return 0;

	for (i = 0; i < 25 * write_idx; i++) {
		if (i > 0 && (i % 25) == 0) {
			len += snprintf(buf + len, PAGE_SIZE - len, "\r\n");
		}
		len += snprintf(buf + len, PAGE_SIZE - len, "%d  ", user_para_data[i]);
	}
	len += snprintf(buf + len, PAGE_SIZE - len, "\r\n");
	return len;
}

static ssize_t para_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	int vals[25];
	int i;

	if (sscanf(buf, "%d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d %d",
		   &vals[0], &vals[1], &vals[2], &vals[3], &vals[4], &vals[5],
		   &vals[6], &vals[7], &vals[8], &vals[9], &vals[10], &vals[11],
		   &vals[12], &vals[13], &vals[14], &vals[15], &vals[16], &vals[17],
		   &vals[18], &vals[19], &vals[20], &vals[21], &vals[22], &vals[23],
		   &vals[24]) != 25) {
		pr_err("aw22xxx: %s: invalid input format\n", __func__);
		return -EINVAL;
	}

	if (write_idx >= 1000) {
		pr_err("aw22xxx: %s: parameter capacity exceeded\n", __func__);
		return -ENOSPC;
	}

	for (i = 0; i < 25; i++) {
		user_para_data[write_idx * 25 + i] = vals[i];
	}
	write_idx++;
	return count;
}

static ssize_t reg_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	u8 reg_255 = 0;
	u8 val = 0;
	int i;
	size_t len = 0;

	aw22xxx_i2c_read(aw22xxx, 255, &reg_255);

	for (i = 0; i < 256; i++) {
		if (!reg_255 && !(aw22xxx_reg_access[i] & 1))
			continue;

		aw22xxx_i2c_read(aw22xxx, i, &val);
		if (PAGE_SIZE - len <= 32)
			break;

		len += snprintf(buf + len, PAGE_SIZE - len, "reg:0x%02x=0x%02x \n", i, val);
	}
	return len;
}

static ssize_t reg_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	u32 reg = 0, val = 0;

	if (sscanf(buf, "%x %x", &reg, &val) != 2 || reg >= 256)
		return -EINVAL;

	aw22xxx_i2c_write(aw22xxx, reg, val);
	return count;
}

static ssize_t rgb_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	size_t len = 0;
	int i;

	for (i = 0; i < 9; i++) {
		len += snprintf(buf + len, PAGE_SIZE - len, "rgb[%d] = 0x%06x\n", i, aw22xxx->rgb_val[i]);
	}
	return len;
}

static ssize_t rgb_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	u32 index = 0, val = 0;

	if (sscanf(buf, "%x %x", &index, &val) != 2 || index > 8)
		return -EINVAL;

	aw22xxx->rgb_val[index] = val;
	pr_info("aw22xxx: rgb[%d] set to 0x%06x\n", index, val);
	return count;
}

static ssize_t task0_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	return snprintf(buf, PAGE_SIZE, "task0 = 0x%02x\n", aw22xxx->task0);
}

static ssize_t task0_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	u32 val = 0;

	if (sscanf(buf, "%x", &val) != 1)
		return -EINVAL;

	aw22xxx->task0 = val;
	schedule_work(&aw22xxx->task_work);
	return count;
}

static ssize_t task1_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	return snprintf(buf, PAGE_SIZE, "task1 = 0x%02x\n", aw22xxx->task1);
}

static ssize_t task1_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	u32 val = 0;

	if (sscanf(buf, "%x", &val) != 1)
		return -EINVAL;

	aw22xxx->task1 = val;
	return count;
}

static ssize_t task_irq_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	return snprintf(buf, PAGE_SIZE, "task_irq = %u\n", aw22xxx->task_irq);
}

static ssize_t task_irq_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	u32 val = 0;

	if (sscanf(buf, "%u", &val) != 1)
		return -EINVAL;

	aw22xxx->task_irq = val;
	return count;
}

static ssize_t aw22xxx_multi_breath_pattern_show(struct device *dev, struct device_attribute *attr, char *buf)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	return snprintf(buf, PAGE_SIZE, " pattern_status = %d\n", aw22xxx->task_irq); // matches task_irq mapping in ROM!
}

static ssize_t aw22xxx_multi_breath_pattern_store(struct device *dev, struct device_attribute *attr, const char *buf, size_t count)
{
	struct led_classdev *cdev = dev_get_drvdata(dev);
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	u32 val = 0;

	if (sscanf(buf, "%x", &val) != 1)
		return -EINVAL;

	aw22xxx->task_irq = val; // Matches the register task_irq / pattern_status in ROM

	if (val) {
		if (val == 1) {
			read_idx = 0;
			if (!kthread_status && write_idx) {
				cfg_update_kthread = kthread_create(aw22xxx_play, aw22xxx, "aw22xxx_play");
				if (!IS_ERR(cfg_update_kthread)) {
					wake_up_process(cfg_update_kthread);
					kthread_status = 1;
					pr_info("aw22xxx: kthread_create done\n");
				} else {
					kthread_status = 0;
					pr_err("aw22xxx: kthread_create error\n");
				}
			}
		}
	} else {
		read_idx = 0;
		write_idx = 0;
		if (kthread_status == 1) {
			kthread_status = 0;
			if (cfg_update_kthread) {
				kthread_stop(cfg_update_kthread);
				cfg_update_kthread = NULL;
			}
		}
		aw22xxx_i2c_write(aw22xxx, 255, 0);
		aw22xxx_i2c_write(aw22xxx, 5, 0);
		aw22xxx_i2c_write(aw22xxx, 4, 1);
		aw22xxx_i2c_write(aw22xxx, 2, 0);
	}
	return count;
}

static DEVICE_ATTR_RW(cfg);
static DEVICE_ATTR_RW(effect);
static DEVICE_ATTR_RW(fw);
static DEVICE_ATTR_RW(hwen);
static DEVICE_ATTR_RW(imax);
static DEVICE_ATTR_RW(para);
static struct device_attribute dev_attr_pattern =
	__ATTR(pattern, 0660, aw22xxx_multi_breath_pattern_show, aw22xxx_multi_breath_pattern_store);
static DEVICE_ATTR_RW(reg);
static DEVICE_ATTR_RW(rgb);
static DEVICE_ATTR_RW(task0);
static DEVICE_ATTR_RW(task1);
static DEVICE_ATTR_RW(task_irq);

static struct attribute *aw22xxx_attrs[] = {
	&dev_attr_cfg.attr,
	&dev_attr_effect.attr,
	&dev_attr_fw.attr,
	&dev_attr_hwen.attr,
	&dev_attr_imax.attr,
	&dev_attr_para.attr,
	&dev_attr_pattern.attr,
	&dev_attr_reg.attr,
	&dev_attr_rgb.attr,
	&dev_attr_task0.attr,
	&dev_attr_task1.attr,
	&dev_attr_task_irq.attr,
	NULL
};

static const struct attribute_group aw22xxx_attribute_group = {
	.attrs = aw22xxx_attrs,
};

/* ======================================================================
 * LED Classdev Operations
 * ====================================================================== */

static void aw22xxx_set_brightness(struct led_classdev *cdev, enum led_brightness value)
{
	struct aw22xxx *aw22xxx = container_of(cdev, struct aw22xxx, cdev);
	cdev->brightness = value;
	schedule_work(&aw22xxx->brightness_work);
}

static int aw22xxx_parse_led_cdev(struct aw22xxx *aw22xxx, struct device_node *np)
{
	struct device_node *child;
	int ret;

	pr_info("aw22xxx: %s\n", __func__);
	child = of_get_next_child(np, NULL);
	if (!child) {
		dev_err(aw22xxx->dev, "no child nodes found\n");
		return -EINVAL;
	}

	ret = of_property_read_string(child, "aw22xxx,name", &aw22xxx->cdev.name);
	if (ret < 0) {
		dev_err(aw22xxx->dev, "failure reading led name: %d\n", ret);
		return ret;
	}

	ret = of_property_read_u32(child, "aw22xxx,imax", &aw22xxx->imax);
	if (ret < 0) {
		dev_err(aw22xxx->dev, "failure reading imax: %d\n", ret);
		return ret;
	}

	ret = of_property_read_u32(child, "aw22xxx,brightness", &aw22xxx->cdev.brightness);
	if (ret < 0) {
		dev_err(aw22xxx->dev, "failure reading brightness: %d\n", ret);
		return ret;
	}

	ret = of_property_read_u32(child, "aw22xxx,max_brightness", &aw22xxx->cdev.max_brightness);
	if (ret < 0) {
		dev_err(aw22xxx->dev, "failure reading max brightness: %d\n", ret);
		return ret;
	}

	INIT_WORK(&aw22xxx->brightness_work, aw22xxx_brightness_work);
	INIT_WORK(&aw22xxx->task_work, aw22xxx_task_work);

	aw22xxx->cdev.brightness_set = aw22xxx_set_brightness;

	ret = led_classdev_register_ext(aw22xxx->dev, &aw22xxx->cdev, NULL);
	if (ret) {
		dev_err(aw22xxx->dev, "unable to register led classdev: %d\n", ret);
		return ret;
	}

	ret = sysfs_create_group(&aw22xxx->cdev.dev->kobj, &aw22xxx_attribute_group);
	if (ret) {
		dev_err(aw22xxx->dev, "led sysfs creation failed: %d\n", ret);
		led_classdev_unregister(&aw22xxx->cdev);
		return ret;
	}

	return 0;
}

/* ======================================================================
 * Procfs Entry Callbacks
 * ====================================================================== */

static ssize_t colorleds_id_read(struct file *file, char __user *user_buf, size_t count, loff_t *ppos)
{
	char id_str[32];
	size_t len;

	pr_info("aw22xxx: %s\n", __func__);
	// Decode uint64_t g_chip_id back to ascii string
	snprintf(id_str, sizeof(id_str), "%s", (char *)&g_chip_id);
	len = strnlen(id_str, sizeof(id_str));

	return simple_read_from_buffer(user_buf, count, ppos, id_str, len);
}

static const struct proc_ops proc_ops_awid = {
	.proc_read = colorleds_id_read,
};

static int aw22xxx_create_proc_entry(void)
{
	if (proc_create("driver/colorleds_id", 0444, NULL, &proc_ops_awid)) {
		pr_info("aw22xxx: proc entry driver/colorleds_id created\n");
		return 0;
	}
	pr_err("aw22xxx: failed to create proc entry\n");
	return -ENOMEM;
}

/* ======================================================================
 * Probe & Remove
 * ====================================================================== */

static int aw22xxx_i2c_probe(struct i2c_client *client)
{
	struct device *dev = &client->dev;
	struct device_node *np = dev->of_node;
	struct aw22xxx *aw22xxx;
	int ret;

	pr_info("aw22xxx: %s entering\n", __func__);

	if (!i2c_check_functionality(client->adapter, I2C_FUNC_I2C)) {
		dev_err(dev, "i2c functionality check failed\n");
		return -ENODEV;
	}

	aw22xxx = devm_kzalloc(dev, sizeof(struct aw22xxx), GFP_KERNEL);
	if (!aw22xxx)
		return -ENOMEM;

	aw22xxx->i2c = client;
	aw22xxx->dev = dev;
	i2c_set_clientdata(client, aw22xxx);

	mutex_init(&aw22xxx->cfg_lock);
	aw22xxx->init_flag = 1;

	/* Pinctrl setup */
	aw22xxx->pinctrl = devm_pinctrl_get(dev);
	if (IS_ERR_OR_NULL(aw22xxx->pinctrl)) {
		pr_err("aw22xxx: failed to get pinctrl\n");
	} else {
		aw22xxx->pinctrl_default = pinctrl_lookup_state(aw22xxx->pinctrl, "aw22xxx_led_default");
		aw22xxx->pinctrl_sleep = pinctrl_lookup_state(aw22xxx->pinctrl, "aw22xxx_led_sleep");
		if (!IS_ERR_OR_NULL(aw22xxx->pinctrl_default)) {
			ret = pinctrl_select_state(aw22xxx->pinctrl, aw22xxx->pinctrl_default);
			if (ret)
				pr_err("aw22xxx: failed to select pinctrl default\n");
		}
	}

	if (!np) {
		dev_err(dev, "no device tree node found\n");
		return -EINVAL;
	}

	if (of_property_read_u32(np, "aw_drv_ver", &g_ver_var)) {
		g_ver_var = 11;
	}
	dev_info(dev, "aw drv ver=%d\n", g_ver_var);

	aw22xxx->reset_gpio = of_get_named_gpio(np, "reset-gpio", 0);
	if (gpio_is_valid(aw22xxx->reset_gpio)) {
		ret = devm_gpio_request_one(dev, aw22xxx->reset_gpio, GPIOF_OUT_INIT_HIGH, "aw22xxx_rst");
		if (ret) {
			dev_err(dev, "failed to request reset-gpio: %d\n", ret);
			return ret;
		}
	} else {
		dev_err(dev, "reset-gpio missing or invalid\n");
		return -EINVAL;
	}

	aw22xxx->irq_gpio = of_get_named_gpio(np, "irq-gpio", 0);
	if (gpio_is_valid(aw22xxx->irq_gpio)) {
		ret = devm_gpio_request_one(dev, aw22xxx->irq_gpio, GPIOF_IN, "aw22xxx_int");
		if (ret) {
			dev_err(dev, "failed to request irq-gpio: %d\n", ret);
			return ret;
		}
	}

	aw22xxx->nubia_ver_gpio = of_get_named_gpio(np, "nubia_ver-gpio", 0);

	if (of_property_read_u32(np, "cfg_custom_en", &g_custom_en)) {
		g_custom_en = 0;
	}
	aw22xxx->cfg_custom_en = g_custom_en;

	aw22xxx_hw_reset(aw22xxx);

	if (multicolor_led == 1 || multicolor_led == 2) {
		gpiod_set_value_cansleep(gpio_to_desc(aw22xxx->reset_gpio), 0);
		multicolor_led = 0;
		g_cfgarray_count = g_custom_en ? 11 : 4500;
		return 0;
	}

	ret = aw22xxx_read_chipid(aw22xxx);
	if (ret < 0) {
		dev_err(dev, "read_chipid failed\n");
		return ret;
	}

	ret = aw22xxx_parse_led_cdev(aw22xxx, np);
	if (ret < 0)
		return ret;

	ret = aw22xxx_alloc_name_array();
	if (ret < 0)
		return ret;

	strcpy(aw22xxx_fw_name, "aw22xxx_fw.bin");
	aw22xxx_fw_init(aw22xxx);

	gpiod_direction_output(gpio_to_desc(aw22xxx->reset_gpio), 0);
	aw22xxx_create_proc_entry();

	return 0;
}

static void aw22xxx_i2c_remove(struct i2c_client *client)
{
	struct aw22xxx *aw22xxx = i2c_get_clientdata(client);
	int i;

	pr_info("aw22xxx: removing driver\n");
	if (aw22xxx) {
		hrtimer_cancel(&aw22xxx->timer);
		cancel_work_sync(&aw22xxx->fw_work);
		cancel_work_sync(&aw22xxx->cfg_work);
		cancel_work_sync(&aw22xxx->brightness_work);
		cancel_work_sync(&aw22xxx->task_work);

		if (g_ver_var == 11) {
			cancel_work_sync(&aw22xxx->recover_work);
		}

		if (kthread_status && cfg_update_kthread) {
			kthread_status = 0;
			kthread_stop(cfg_update_kthread);
			cfg_update_kthread = NULL;
		}

		sysfs_remove_group(&aw22xxx->cdev.dev->kobj, &aw22xxx_attribute_group);
		led_classdev_unregister(&aw22xxx->cdev);
		remove_proc_entry("driver/colorleds_id", NULL);
	}

	if (aw22xxx_cfg_name) {
		for (i = 0; i < 11; i++)
			kfree(aw22xxx_cfg_name[i]);
		kfree(aw22xxx_cfg_name);
		aw22xxx_cfg_name = NULL;
	}
}

static const struct of_device_id aw22xxx_dt_match[] = {
	{ .compatible = "awinic,aw22xxx_led" },
	{ },
};
MODULE_DEVICE_TABLE(of, aw22xxx_dt_match);

static const struct i2c_device_id aw22xxx_i2c_id[] = {
	{ "aw22xxx_led", 0 },
	{ }
};
MODULE_DEVICE_TABLE(i2c, aw22xxx_i2c_id);

static struct i2c_driver aw22xxx_i2c_driver = {
	.driver = {
		.name = DRIVER_NAME,
		.owner = THIS_MODULE,
		.of_match_table = aw22xxx_dt_match,
	},
	.probe = aw22xxx_i2c_probe,
	.remove = aw22xxx_i2c_remove,
	.id_table = aw22xxx_i2c_id,
};

module_i2c_driver(aw22xxx_i2c_driver);

MODULE_AUTHOR("Antigravity <google-deepmind>");
MODULE_DESCRIPTION("Awinic AW22XXX RGB LED smart controller driver reconstruction");
MODULE_LICENSE("GPL v2");
