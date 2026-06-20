// SPDX-License-Identifier: GPL-2.0-only
/*
 * zte_fingerprint.c - ZTE Custom Goodix Fingerprint Bridge Driver
 *
 * Provides userspace char-dev node interface, inputs keys, and routes display state notifications via Netlink.
 *
 * Reconstructed from binary analysis of zte_fingerprint.ko
 * extracted from NX809J (Red Magic 11 Pro) production firmware.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/fs.h>
#include <linux/slab.h>
#include <linux/mutex.h>
#include <linux/platform_device.h>
#include <linux/uaccess.h>
#include <linux/list.h>
#include <linux/input.h>
#include <linux/interrupt.h>
#include <linux/gpio.h>
#include <linux/of_gpio.h>
#include <linux/regulator/consumer.h>
#include <linux/delay.h>
#include <linux/netlink.h>
#include <linux/skbuff.h>
#include <linux/pm_wakeup.h>
#include <linux/pinctrl/consumer.h>
#include <net/netlink.h>
#include <net/net_namespace.h>
#include <drm/drm_panel.h>
#include <linux/soc/qcom/panel_event_notifier.h>

#define DRIVER_NAME "goodix_fp"
#define GF_NETLINK_PROTO 25

/* Netlink State */
static struct sock *nl_sk;
static u32 pid;

/* Globals matching ROM binary */
static int SPIDEV_MAJOR;
static struct class *gf_class;
static struct wakeup_source *fp_wakelock;
static void *cookie;
static void *goodixfp_active_panel;
static unsigned long minors = 0;

static LIST_HEAD(device_list);
static DEFINE_MUTEX(device_list_lock);

/* Private data structure matching Ghidra analysis & layout offsets */
struct gf_device {
	struct list_head device_entry;        // 0
	struct platform_device *pdev;         // 16
	dev_t devt;                           // 24 (gf)
	struct input_dev *input_dev;          // 40
	u32 ref_count;                        // 56
	int irq_gpio;                         // 60
	int reset_gpio;                       // 64
	u32 irq_num;                          // 72
	u32 irq_enabled;                      // 76
	struct workqueue_struct *screen_state_wq; // 80 (qword_8408)
	struct delayed_work screen_state_work; // 88 (qword_8410)
	u8 screen_state;                      // 113 (opened + 1)
	struct pinctrl *pinctrl;              // 120
	struct pinctrl_state *pins_active;         // 128
	struct pinctrl_state *pins_suspend;        // 136
	struct regulator *vdd_reg;            // 144
	u8 opened;                            // 112
};

/* Global static device reference (since original uses a fixed instance layout) */
static struct gf_device gf_dev_static;

/* ======================================================================
 * Netlink Functions
 * ====================================================================== */

static void nl_data_ready(struct sk_buff *skb)
{
	struct nlmsghdr *nlh;

	if (skb->len >= nlmsg_total_size(0)) {
		nlh = nlmsg_hdr(skb);
		pid = NETLINK_CB(skb).portid;
		pr_info("%s: received message from userspace, registered pid=%d\n", __func__, pid);
	}
	kfree_skb(skb);
}

static int sendnlmsg(const char *msg)
{
	struct sk_buff *skb;
	struct nlmsghdr *nlh;
	int ret;

	if (!nl_sk || !pid)
		return -EINVAL;

	skb = alloc_skb(NLMSG_SPACE(1), GFP_ATOMIC);
	if (!skb)
		return -ENOMEM;

	nlh = nlmsg_put(skb, 0, 0, 0, 1, 0);
	if (!nlh) {
		kfree_skb(skb);
		return -EMSGSIZE;
	}

	*(char *)nlmsg_data(nlh) = *msg;

	ret = netlink_unicast(nl_sk, skb, pid, MSG_DONTWAIT);
	if (ret < 0) {
		pr_err("%s: failed to send netlink unicast, ret=%d\n", __func__, ret);
		return ret;
	}

	return 0;
}

static int netlink_init(void)
{
	struct netlink_kernel_cfg cfg = {
		.input = nl_data_ready,
	};

	nl_sk = netlink_kernel_create(&init_net, GF_NETLINK_PROTO, &cfg);
	if (!nl_sk) {
		pr_err("%s: failed to create netlink socket\n", __func__);
		return -ENOMEM;
	}

	pr_info("%s: netlink socket initialized successfully\n", __func__);
	return 0;
}

static void netlink_exit(void)
{
	if (nl_sk) {
		netlink_kernel_release(nl_sk);
		nl_sk = NULL;
	}
	pr_info("%s: netlink socket released\n", __func__);
}

/* ======================================================================
 * Display Notifier Callbacks
 * ====================================================================== */

static void goodix_fb_state_chg_callback(enum panel_event_notifier_tag tag,
					 struct panel_event_notification *notification,
					 void *client_data)
{
	struct gf_device *gf_dev = client_data;
	char msg;

	if (!gf_dev)
		return;

	pr_info("%s: event received\n", __func__);

	if (tag == PANEL_EVENT_NOTIFICATION_PRIMARY) {
		if (notification->notif_type == DRM_PANEL_EVENT_UNBLANK) {
			pr_info("%s: screen turned ON\n", __func__);
			gf_dev->screen_state = 1;
			msg = 2;
			sendnlmsg(&msg);
		} else if (notification->notif_type == DRM_PANEL_EVENT_BLANK) {
			pr_info("%s: screen turned OFF\n", __func__);
			gf_dev->screen_state = 0;
			msg = 3;
			sendnlmsg(&msg);
		}
	}
}

static int goodixfp_drm_get_panel(struct gf_device *gf_dev)
{
	struct device_node *np;
	struct drm_panel *panel = NULL;
	int count, i;

	if (!gf_dev || !gf_dev->pdev)
		return -EINVAL;

	np = gf_dev->pdev->dev.of_node;
	if (!np) {
		pr_err("%s: of_node is NULL\n", __func__);
		return -ENODEV;
	}

	count = of_count_phandle_with_args(np, "panel", NULL);
	if (count < 1) {
		pr_err("%s: panel phandle not found\n", __func__);
		return -ENODEV;
	}

	for (i = 0; i < count; i++) {
		struct device_node *panel_np;

		panel_np = of_parse_phandle(np, "panel", i);
		if (!panel_np)
			continue;

		panel = of_drm_find_panel(panel_np);
		of_node_put(panel_np);

		if (panel && !IS_ERR(panel)) {
			goodixfp_active_panel = panel;
			pr_info("%s: found panel successfully\n", __func__);
			return 0;
		}
	}

	pr_err("%s: active panel find failed\n", __func__);
	return -ENODEV;
}

static void goodixfp_init_drm_notifier_work(struct work_struct *work)
{
	struct gf_device *gf_dev = container_of(work, struct gf_device, screen_state_work.work);
	int ret, i;

	pr_info("%s: entry\n", __func__);

	/* Try to acquire panel up to 25 times */
	for (i = 0; i < 25; i++) {
		ret = goodixfp_drm_get_panel(gf_dev);
		if (ret == 0)
			break;
		pr_info("%s: panel not ready yet, retrying...\n", __func__);
		usleep_range(1000000, 1001000);
	}

	if (goodixfp_active_panel) {
		pr_info("%s: registering panel event notifier\n", __func__);
		cookie = panel_event_notifier_register(PANEL_EVENT_NOTIFICATION_PRIMARY,
						       PANEL_EVENT_NOTIFIER_CLIENT_OTHER,
						       goodixfp_active_panel,
						       goodix_fb_state_chg_callback,
						       gf_dev);
		if (!cookie) {
			pr_err("%s: failed to register panel event notifier\n", __func__);
		}
	} else {
		pr_err("%s: active panel remains NULL\n", __func__);
	}
}

/* ======================================================================
 * Hardware Controls
 * ====================================================================== */

static int gf_power_on(struct gf_device *gf_dev)
{
	int ret;

	if (!gf_dev || IS_ERR_OR_NULL(gf_dev->vdd_reg)) {
		pr_err("%s: regulator is invalid\n", __func__);
		return -EINVAL;
	}

	pr_info("%s: turning on regulator\n", __func__);

	if (regulator_is_enabled(gf_dev->vdd_reg)) {
		pr_info("%s: regulator is already enabled\n", __func__);
		return 0;
	}

	ret = regulator_enable(gf_dev->vdd_reg);
	if (ret) {
		pr_err("%s: failed to enable regulator, ret=%d\n", __func__, ret);
		return ret;
	}

	return 0;
}

static int gf_power_off(struct gf_device *gf_dev)
{
	int ret;

	if (!gf_dev || IS_ERR_OR_NULL(gf_dev->vdd_reg)) {
		pr_err("%s: regulator is invalid\n", __func__);
		return -EINVAL;
	}

	pr_info("%s: turning off regulator\n", __func__);

	if (regulator_is_enabled(gf_dev->vdd_reg)) {
		ret = regulator_disable(gf_dev->vdd_reg);
		if (ret) {
			pr_err("%s: failed to disable regulator, ret=%d\n", __func__, ret);
			return ret;
		}
	} else {
		pr_info("%s: regulator is already disabled\n", __func__);
	}

	return 0;
}

static int gf_hw_reset(struct gf_device *gf_dev, int delay_ms)
{
	if (!gf_dev) {
		pr_err("%s: invalid gf_dev\n", __func__);
		return -EINVAL;
	}

	if (!gpio_is_valid(gf_dev->reset_gpio)) {
		pr_info("%s: reset gpio not defined\n", __func__);
		return 0;
	}

	pr_info("%s: triggering hardware reset\n", __func__);

	gpio_set_value(gf_dev->reset_gpio, 0);
	udelay(10000);
	gpio_set_value(gf_dev->reset_gpio, 1);

	if (delay_ms > 0)
		udelay(delay_ms * 1000);

	return 0;
}

static int gf_enable_irq(struct gf_device *gf_dev)
{
	if (!gf_dev)
		return -EINVAL;

	if (gf_dev->irq_enabled) {
		pr_info("%s: IRQ is already enabled\n", __func__);
		return 0;
	}

	enable_irq(gf_dev->irq_num);
	gf_dev->irq_enabled = 1;
	pr_info("%s: IRQ enabled\n", __func__);
	return 0;
}

static int gf_disable_irq(struct gf_device *gf_dev)
{
	if (!gf_dev)
		return -EINVAL;

	if (!gf_dev->irq_enabled) {
		pr_info("%s: IRQ is already disabled\n", __func__);
		return 0;
	}

	gf_dev->irq_enabled = 0;
	disable_irq(gf_dev->irq_num);
	pr_info("%s: IRQ disabled\n", __func__);
	return 0;
}

static int gf_cleanup(struct gf_device *gf_dev)
{
	if (!gf_dev)
		return -EINVAL;

	pr_info("%s: entry\n", __func__);

	if (gpio_is_valid(gf_dev->irq_gpio)) {
		gpio_free(gf_dev->irq_gpio);
		pr_info("%s: freed irq gpio\n", __func__);
	}

	if (gpio_is_valid(gf_dev->reset_gpio)) {
		gpio_free(gf_dev->reset_gpio);
		pr_info("%s: freed reset gpio\n", __func__);
	}

	if (!IS_ERR_OR_NULL(gf_dev->vdd_reg)) {
		if (regulator_is_enabled(gf_dev->vdd_reg)) {
			regulator_disable(gf_dev->vdd_reg);
			pr_info("%s: disabled vdd regulator\n", __func__);
		}
	}

	return 0;
}

static int zte_goodix_pinctrl_init(struct gf_device *gf_dev)
{
	if (!gf_dev || !gf_dev->pdev)
		return -EINVAL;

	pr_info("%s: loading pinctrl config\n", __func__);

	gf_dev->pinctrl = devm_pinctrl_get(&gf_dev->pdev->dev);
	if (IS_ERR(gf_dev->pinctrl)) {
		pr_err("%s: target does not use pinctrl\n", __func__);
		gf_dev->pinctrl = NULL;
		return -ENODEV;
	}

	gf_dev->pins_active = pinctrl_lookup_state(gf_dev->pinctrl, "goodix_active");
	if (IS_ERR(gf_dev->pins_active)) {
		pr_err("%s: cannot get goodix_active pinstate\n", __func__);
		gf_dev->pins_active = NULL;
	}

	gf_dev->pins_suspend = pinctrl_lookup_state(gf_dev->pinctrl, "goodix_suspend");
	if (IS_ERR(gf_dev->pins_suspend)) {
		pr_err("%s: cannot get goodix_suspend pinstate\n", __func__);
		gf_dev->pins_suspend = NULL;
	}

	return 0;
}

static int __maybe_unused zte_goodix_pinctrl_select(struct gf_device *gf_dev, bool active)
{
	struct pinctrl_state *state;
	int ret;

	if (!gf_dev || !gf_dev->pinctrl)
		return -EINVAL;

	state = active ? gf_dev->pins_active : gf_dev->pins_suspend;
	if (!state) {
		dev_err(&gf_dev->pdev->dev, "not a valid pinstate\n");
		return -EINVAL;
	}

	ret = pinctrl_select_state(gf_dev->pinctrl, state);
	if (ret) {
		dev_err(&gf_dev->pdev->dev, "cannot set pins, ret=%d\n", ret);
		return ret;
	}

	return 0;
}

static int gf_parse_dts(struct gf_device *gf_dev)
{
	struct device_node *np;
	int ret;

	if (!gf_dev || !gf_dev->pdev)
		return -EINVAL;

	np = gf_dev->pdev->dev.of_node;
	if (!np)
		return -ENODEV;

	ret = zte_goodix_pinctrl_init(gf_dev);
	if (ret)
		pr_info("%s: pinctrl init returned %d\n", __func__, ret);

	if (gf_dev->pinctrl && gf_dev->pins_suspend) {
		ret = pinctrl_select_state(gf_dev->pinctrl, gf_dev->pins_suspend);
		if (ret) {
			dev_err(&gf_dev->pdev->dev, "can not set goodix_suspend pins\n");
			return ret;
		}
	}

	usleep_range(10000, 10100);

	gf_dev->vdd_reg = devm_regulator_get(&gf_dev->pdev->dev, "vdd");
	if (IS_ERR(gf_dev->vdd_reg)) {
		pr_err("%s: cannot get vdd regulator\n", __func__);
		return PTR_ERR(gf_dev->vdd_reg);
	}

	ret = regulator_enable(gf_dev->vdd_reg);
	if (ret) {
		pr_err("%s: failed to enable regulator\n", __func__);
		return ret;
	}

	gf_dev->reset_gpio = of_get_named_gpio(np, "fp-gpio-reset", 0);
	if (!gpio_is_valid(gf_dev->reset_gpio)) {
		pr_err("%s: invalid reset gpio\n", __func__);
		return -EINVAL;
	}

	ret = devm_gpio_request(&gf_dev->pdev->dev, gf_dev->reset_gpio, "goodix_reset");
	if (ret) {
		pr_err("%s: failed to request reset gpio\n", __func__);
		return ret;
	}

	gf_dev->irq_gpio = of_get_named_gpio(np, "fp-gpio-irq", 0);
	if (!gpio_is_valid(gf_dev->irq_gpio)) {
		pr_err("%s: invalid irq gpio\n", __func__);
		return -EINVAL;
	}

	ret = devm_gpio_request(&gf_dev->pdev->dev, gf_dev->irq_gpio, "goodix_irq");
	if (ret) {
		pr_err("%s: failed to request irq gpio\n", __func__);
		return ret;
	}

	gpio_direction_input(gf_dev->irq_gpio);
	pr_info("%s: parse dts complete successfully\n", __func__);
	return 0;
}

static irqreturn_t gf_irq(int irq, void *dev_id)
{
	char msg = 1;

	__pm_wakeup_event(fp_wakelock, 2500);
	pr_info("%s: fingerprint IRQ triggered\n", __func__);
	sendnlmsg(&msg);

	return IRQ_HANDLED;
}

/* ======================================================================
 * File Operations Callbacks
 * ====================================================================== */

static int gf_open(struct inode *inode, struct file *file)
{
	struct gf_device *gf_dev;
	struct list_head *pos;
	int ret = -ENXIO;

	pr_info("%s: entry\n", __func__);

	mutex_lock(&device_list_lock);

	list_for_each(pos, &device_list) {
		gf_dev = list_entry(pos, struct gf_device, device_entry);
		if (gf_dev->devt == inode->i_rdev) {
			pr_info("%s: device match found\n", __func__);
			gf_dev->opened = 1;
			gf_dev->ref_count++;
			file->private_data = gf_dev;
			nonseekable_open(inode, file);
			ret = 0;
			break;
		}
	}

	if (ret) {
		pr_err("%s: device minor %d not found\n", __func__, iminor(inode));
		goto out_unlock;
	}

	if (gf_dev->ref_count == 1) {
		ret = gf_parse_dts(gf_dev);
		if (ret) {
			gf_cleanup(gf_dev);
			gf_dev->ref_count = 0;
			goto out_unlock;
		}

		gf_dev->irq_num = gpio_to_irq(gf_dev->irq_gpio);
		ret = request_threaded_irq(gf_dev->irq_num, NULL, gf_irq,
					   IRQF_TRIGGER_RISING | IRQF_ONESHOT, "goodix_fp", gf_dev);
		if (ret) {
			pr_err("%s: request irq failed\n", __func__);
			gf_cleanup(gf_dev);
			gf_dev->ref_count = 0;
			goto out_unlock;
		}

		irq_set_irq_wake(gf_dev->irq_num, 1);
		gf_dev->irq_enabled = 1;
	}

	gf_hw_reset(gf_dev, 5);

out_unlock:
	mutex_unlock(&device_list_lock);
	pr_info("%s: exit, ret=%d\n", __func__, ret);
	return ret;
}

static int gf_release(struct inode *inode, struct file *file)
{
	struct gf_device *gf_dev = file->private_data;

	if (!gf_dev)
		return -EINVAL;

	pr_info("%s: entry\n", __func__);

	mutex_lock(&device_list_lock);
	file->private_data = NULL;
	gf_dev->ref_count--;

	if (gf_dev->ref_count == 0) {
		pr_info("%s: freeing resources\n", __func__);
		irq_set_irq_wake(gf_dev->irq_num, 0);

		if (gf_dev->irq_enabled) {
			gf_dev->irq_enabled = 0;
			disable_irq(gf_dev->irq_num);
		}

		free_irq(gf_dev->irq_num, gf_dev);
		gf_cleanup(gf_dev);
		gf_dev->opened = 0;
	}

	mutex_unlock(&device_list_lock);
	return 0;
}

static int nav_event_input(int action)
{
	u32 key_code = 0;

	switch (action) {
	case 3:
		key_code = KEY_UP;
		break;
	case 4:
		key_code = KEY_DOWN;
		break;
	case 5:
		key_code = KEY_LEFT;
		break;
	case 6:
		key_code = KEY_RIGHT;
		break;
	case 7:
		key_code = KEY_VOLUMEDOWN;
		break;
	case 8:
		key_code = KEY_CHAT;
		break;
	case 9:
		key_code = KEY_ASSISTANT;
		break;
	case 10:
		key_code = KEY_VOLUMEUP;
		break;
	default:
		pr_warn("%s: unknown nav action %d\n", __func__, action);
		return -EINVAL;
	}

	pr_info("%s: reporting key event %d\n", __func__, key_code);
	input_report_key(gf_dev_static.input_dev, key_code, 1);
	input_sync(gf_dev_static.input_dev);
	input_report_key(gf_dev_static.input_dev, key_code, 0);
	input_sync(gf_dev_static.input_dev);

	return 0;
}



static long gf_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
	struct gf_device *gf_dev = file->private_data;
	int ret = 0;

	if (!gf_dev)
		return -EINVAL;

	if ((cmd & 0xFF00) != 0x6700)
		return -ENOTTY;

	switch (cmd) {
	case 0x80046700: { // -2147391744
		char ver = 25;
		pr_info("%s: ZTE_FP_IOCTL_GET_VERSION\n", __func__);
		if (copy_to_user((void __user *)arg, &ver, sizeof(ver)))
			return -EFAULT;
		break;
	}
	case 0x6701: // 26369
		pr_info("%s: ZTE_FP_IOCTL_CMD_01\n", __func__);
		break;
	case 0x6702: // 26370
		pr_info("%s: ZTE_FP_IOCTL_RESET\n", __func__);
		gf_hw_reset(gf_dev, 5);
		break;
	case 0x6703: // 26371
		pr_info("%s: ZTE_FP_IOCTL_ENABLE_IRQ\n", __func__);
		gf_enable_irq(gf_dev);
		break;
	case 0x6704: // 26372
		pr_info("%s: ZTE_FP_IOCTL_DISABLE_IRQ\n", __func__);
		gf_disable_irq(gf_dev);
		break;
	case 0x6707: // 26375
		pr_info("%s: ZTE_FP_IOCTL_POWER_ON\n", __func__);
		if (gf_dev->opened) {
			ret = gf_power_on(gf_dev);
		}
		break;
	case 0x6708: // 26376
		pr_info("%s: ZTE_FP_IOCTL_POWER_OFF\n", __func__);
		if (gf_dev->opened) {
			ret = gf_power_off(gf_dev);
		}
		break;
	case 0x670c: // 26380
		pr_info("%s: ZTE_FP_IOCTL_CLEANUP\n", __func__);
		gf_cleanup(gf_dev);
		break;
	case 0x4004670e: { // 1074030350
		u32 action;
		pr_info("%s: ZTE_FP_IOCTL_NAV_EVENT\n", __func__);
		if (copy_from_user(&action, (void __user *)arg, sizeof(action)))
			return -EFAULT;
		ret = nav_event_input(action);
		break;
	}
	case 0x400c6709: { // 1074292489
		u64 event_data;
		u32 key_code;
		bool pressed;

		pr_info("%s: ZTE_FP_IOCTL_REPORT_KEY\n", __func__);
		if (copy_from_user(&event_data, (void __user *)arg, sizeof(event_data)))
			return -EFAULT;

		key_code = (u32)(event_data & 0xFFFFFFFF);
		pressed = (bool)((event_data >> 32) & 0xFFFFFFFF);

		switch (key_code) {
		case 1:
			key_code = KEY_HOME;
			break;
		case 5:
			key_code = KEY_CAMERA;
			break;
		case 2:
			key_code = KEY_POWER;
			break;
		}

		if (key_code == KEY_CAMERA || key_code == KEY_POWER) {
			input_report_key(gf_dev->input_dev, key_code, 1);
			input_sync(gf_dev->input_dev);
			input_report_key(gf_dev->input_dev, key_code, 0);
			input_sync(gf_dev->input_dev);
		} else {
			input_report_key(gf_dev->input_dev, key_code, pressed);
			input_sync(gf_dev->input_dev);
		}
		break;
	}
	case 0x400c670d: // 1074292493
		pr_info("%s: ZTE_FP_IOCTL_CMD_0D\n", __func__);
		break;
	default:
		pr_warn("%s: unknown command 0x%x\n", __func__, cmd);
		return -EINVAL;
	}

	return ret;
}

static const struct file_operations gf_fops = {
	.owner          = THIS_MODULE,
	.unlocked_ioctl = gf_ioctl,
	.open           = gf_open,
	.release        = gf_release,
};

/* ======================================================================
 * Platform Driver Probe & Remove
 * ====================================================================== */

static int gf_probe(struct platform_device *pdev)
{
	struct gf_device *gf_dev = &gf_dev_static;
	struct device *dev_node;
	int ret = 0;

	pr_info("%s: entry\n", __func__);

	memset(gf_dev, 0, sizeof(*gf_dev));
	gf_dev->pdev = pdev;

	/* Setup delayed workqueue for screen notifier */
	gf_dev->screen_state_wq = alloc_workqueue("screen_state_wq", WQ_UNBOUND | WQ_MEM_RECLAIM, 1);
	if (gf_dev->screen_state_wq) {
		INIT_DELAYED_WORK(&gf_dev->screen_state_work, goodixfp_init_drm_notifier_work);
		queue_delayed_work(gf_dev->screen_state_wq, &gf_dev->screen_state_work, msecs_to_jiffies(1250));
	}

	mutex_lock(&device_list_lock);

	/* Find first free minor */
	if (minors & 1) {
		mutex_unlock(&device_list_lock);
		dev_err(&pdev->dev, "no minor number available!\n");
		ret = -EBUSY;
		goto err_destroy_wq;
	}

	gf_dev->devt = MKDEV(SPIDEV_MAJOR, 0);

	/* Create device node /dev/goodix_fp */
	dev_node = device_create(gf_class, &pdev->dev, gf_dev->devt, gf_dev, "goodix_fp");
	if (IS_ERR(dev_node)) {
		mutex_unlock(&device_list_lock);
		dev_err(&pdev->dev, "failed to create device node!\n");
		ret = PTR_ERR(dev_node);
		goto err_destroy_wq;
	}

	/* Claim minor */
	minors |= 1;

	/* Add to list */
	list_add_tail(&gf_dev->device_entry, &device_list);
	mutex_unlock(&device_list_lock);

	/* Allocate Input Device */
	gf_dev->input_dev = input_allocate_device();
	if (!gf_dev->input_dev) {
		pr_err("%s: failed to allocate input device\n", __func__);
		ret = -ENOMEM;
		goto err_destroy_device;
	}

	/* Capabilities */
	gf_dev->input_dev->name = "goodix_fp";
	input_set_capability(gf_dev->input_dev, EV_KEY, KEY_HOME);
	input_set_capability(gf_dev->input_dev, EV_KEY, KEY_MENU);
	input_set_capability(gf_dev->input_dev, EV_KEY, KEY_BACK);
	input_set_capability(gf_dev->input_dev, EV_KEY, KEY_POWER);
	input_set_capability(gf_dev->input_dev, EV_KEY, KEY_UP);
	input_set_capability(gf_dev->input_dev, EV_KEY, KEY_DOWN);
	input_set_capability(gf_dev->input_dev, EV_KEY, KEY_LEFT);
	input_set_capability(gf_dev->input_dev, EV_KEY, KEY_RIGHT);
	input_set_capability(gf_dev->input_dev, EV_KEY, KEY_CAMERA);
	input_set_capability(gf_dev->input_dev, EV_KEY, KEY_VOLUMEDOWN);
	input_set_capability(gf_dev->input_dev, EV_KEY, KEY_VOLUMEUP);
	input_set_capability(gf_dev->input_dev, EV_KEY, KEY_ASSISTANT);
	input_set_capability(gf_dev->input_dev, EV_KEY, KEY_CHAT);

	ret = input_register_device(gf_dev->input_dev);
	if (ret) {
		pr_err("%s: failed to register input device\n", __func__);
		goto err_free_input;
	}

	fp_wakelock = wakeup_source_create("fp_wakelock");
	if (fp_wakelock)
		wakeup_source_add(fp_wakelock);
	pr_info("%s: probe successful\n", __func__);
	platform_set_drvdata(pdev, gf_dev);
	return 0;

err_free_input:
	input_free_device(gf_dev->input_dev);
	gf_dev->input_dev = NULL;
err_destroy_device:
	mutex_lock(&device_list_lock);
	list_del(&gf_dev->device_entry);
	device_destroy(gf_class, gf_dev->devt);
	minors &= ~1;
	mutex_unlock(&device_list_lock);
err_destroy_wq:
	if (gf_dev->screen_state_wq) {
		cancel_delayed_work_sync(&gf_dev->screen_state_work);
		destroy_workqueue(gf_dev->screen_state_wq);
	}
	return ret;
}

static void gf_remove(struct platform_device *pdev)
{
	struct gf_device *gf_dev = platform_get_drvdata(pdev);

	pr_info("%s: entry\n", __func__);

	if (fp_wakelock) {
		wakeup_source_remove(fp_wakelock);
		wakeup_source_destroy(fp_wakelock);
		fp_wakelock = NULL;
	}

	if (gf_dev) {
		if (gf_dev->input_dev) {
			input_unregister_device(gf_dev->input_dev);
			gf_dev->input_dev = NULL;
		}

		mutex_lock(&device_list_lock);
		list_del(&gf_dev->device_entry);
		device_destroy(gf_class, gf_dev->devt);
		minors &= ~1;
		mutex_unlock(&device_list_lock);

		if (gf_dev->screen_state_wq) {
			if (cookie) {
				panel_event_notifier_unregister(cookie);
				cookie = NULL;
			}
			cancel_delayed_work_sync(&gf_dev->screen_state_work);
			destroy_workqueue(gf_dev->screen_state_wq);
		}
	}

	pr_info("%s: remove complete\n", __func__);
}

static const struct of_device_id gf_of_match[] = {
	{ .compatible = "goodix,fingerprint" },
	{ .compatible = "goodix,fp" },
	{ .compatible = "goodix,fp-spi" },
	{ .compatible = "zte,goodix-fp" },
	{ },
};
MODULE_DEVICE_TABLE(of, gf_of_match);

static struct platform_driver gf_driver = {
	.probe  = gf_probe,
	.remove = gf_remove,
	.driver = {
		.name           = "goodix_fp",
		.of_match_table = gf_of_match,
	},
};

/* ======================================================================
 * Module Initialization & Cleanup
 * ====================================================================== */

static int __init zte_fp_init(void)
{
	int ret;

	pr_info("%s: initializing fingerprint bridge\n", __func__);

	SPIDEV_MAJOR = register_chrdev(0, "goodix_fp_spi", &gf_fops);
	if (SPIDEV_MAJOR < 0) {
		pr_err("%s: failed to register char device\n", __func__);
		return SPIDEV_MAJOR;
	}

	gf_class = class_create("goodix_fp");
	if (IS_ERR(gf_class)) {
		pr_err("%s: failed to create goodix_fp class\n", __func__);
		ret = PTR_ERR(gf_class);
		goto err_unregister_chrdev;
	}

	ret = platform_driver_register(&gf_driver);
	if (ret) {
		pr_err("%s: failed to register platform driver\n", __func__);
		goto err_destroy_class;
	}

	ret = netlink_init();
	if (ret) {
		pr_err("%s: netlink init failed\n", __func__);
		goto err_unregister_driver;
	}

	return 0;

err_unregister_driver:
	platform_driver_unregister(&gf_driver);
err_destroy_class:
	class_destroy(gf_class);
err_unregister_chrdev:
	unregister_chrdev(SPIDEV_MAJOR, "goodix_fp_spi");
	return ret;
}

static void __exit zte_fp_exit(void)
{
	netlink_exit();
	platform_driver_unregister(&gf_driver);
	class_destroy(gf_class);
	unregister_chrdev(SPIDEV_MAJOR, "goodix_fp_spi");
}

module_init(zte_fp_init);
module_exit(zte_fp_exit);

MODULE_DESCRIPTION("ZTE Custom Goodix Fingerprint Bridge Driver");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZTE Corporation (reconstructed)");
