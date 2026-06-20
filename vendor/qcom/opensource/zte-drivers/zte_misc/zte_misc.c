// SPDX-License-Identifier: GPL-2.0-only
/*
 * zte_misc.c - ZTE Miscellaneous and Common Callback Driver
 *
 * Implements a central property registry/bus where other ZTE drivers can
 * register callbacks for power, charging, and platform features. Also
 * parses chosen boot arguments for power-off charging and handles ZTE timezone setups.
 *
 * Reconstructed from binary analysis of zte_misc.ko
 * extracted from NX809J (Red Magic 11 Pro) production firmware.
 */

#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/of.h>
#include <linux/of_gpio.h>
#include <linux/slab.h>
#include <linux/power_supply.h>
#include <linux/string.h>

#define DRV_NAME "zte-misc"

/* Control flow integrity signature / hash value matching original binary checks */
#define ZTE_CFI_GET_SIG 697349865
#define ZTE_CFI_SET_SIG 1291426251

/* ======================================================================
 * Structures and Globals
 * ====================================================================== */

struct zte_node_ops {
	const char *name;
	int (*set)(const char *buf, void *priv);
	int (*get)(char *buf, void *priv);
	int (*show)(char *buf, void *priv);
	void *priv;
};

struct zte_gpio_entry {
	int gpio;
	const char *label;
};

/* 16 entries max per probe logic limits */
static struct zte_gpio_entry zte_gpios[16];

static bool zte_poweroff_charging;
static bool zte_poweroff_charging_param;
static long zte_timezone;

/* Static table of ZTE node properties (callbacks registered dynamically) */
static struct zte_node_ops node_ops_list[] = {
	{ "enable_to_shutdown" },
	{ "enable_to_dump_reg" },
	{ "demo_charging_policy" },
	{ "expired_charging_policy" },
	{ "charging_time_sec" },
	{ "force_disching_sec" },
	{ "policy_cap_min" },
	{ "policy_cap_max" },
	{ "policy_enable" },
	{ "bcl_demon_switch" },
	{ "qc3dp_sleep_mode" },
	{ "screen_on" },
	{ "wireless_charging_signal_good" },
	{ "wireless_efficiency" },
	{ "wireless_signal_strength" },
	{ "wireless_tx_rx" },
	{ "wireless_debug" },
	{ "pe1_debug" },
	{ "pd_debug" },
	{ "super_charge_mode" },
	{ "charge_remain_time" },
	{ "batt_temp_debug" },
	{ "cap_debug" },
	{ "charger_power" },
	{ "thermal_control_en" },
	{ "charge_type_oem" },
	{ "wls_nu_cep" },
	{ "wls_nu_iout" },
	{ "wls_nu_usbtype" },
	{ "wls_nu_vout" },
	{ "wls_nu_vrect" },
	{ "wls_boost_en" },
	{ "wls_nu_fw_update" },
	{ "wls_nu_ver" },
	{ "wls_nu_sleep" },
	{ "zlog_enable_test" },
};

#define NODE_OPS_COUNT ARRAY_SIZE(node_ops_list)

/* ======================================================================
 * Registered Callbacks & Node Values API
 * ====================================================================== */

int zte_misc_register_callback(const void *cb_struct, void *priv)
{
	const char *name;
	size_t name_len;
	int i;

	if (!cb_struct)
		return -EINVAL;

	name = *(const char **)cb_struct;
	if (!name)
		return -EINVAL;

	name_len = strlen(name);

	for (i = 0; i < NODE_OPS_COUNT; i++) {
		if (strncmp(node_ops_list[i].name, name, name_len) == 0) {
			if (strlen(node_ops_list[i].name) == name_len)
				break;
		}
	}

	if (i == NODE_OPS_COUNT)
		return -EINVAL;

	pr_info("%s: %s index %d\n", __func__, name, i);

	/* Check if already registered */
	if (node_ops_list[i].set || node_ops_list[i].get || node_ops_list[i].show) {
		pr_info("%s: %s already registered at index %d\n", __func__, name, i);
		return -EBUSY;
	}

	node_ops_list[i].set = *(int (**)(const char *, void *))((char *)cb_struct + 8);
	node_ops_list[i].get = *(int (**)(char *, void *))((char *)cb_struct + 16);
	node_ops_list[i].show = *(int (**)(char *, void *))((char *)cb_struct + 24);
	node_ops_list[i].priv = priv ? priv : *(void **)((char *)cb_struct + 32);

	return 0;
}
EXPORT_SYMBOL(zte_misc_register_callback);

long long zte_misc_get_node_val(const char *name)
{
	char buf[64];
	size_t len;
	int i;
	int val = 0;

	if (!name || !*name)
		return -EINVAL;

	memset(buf, 0, sizeof(buf));
	len = strlen(name);

	for (i = 0; i < NODE_OPS_COUNT; i++) {
		if (strncmp(node_ops_list[i].name, name, len) == 0) {
			if (strlen(node_ops_list[i].name) == len) {
				if (node_ops_list[i].get)
					break;
			}
		}
	}

	if (i == NODE_OPS_COUNT) {
		pr_err("%s: node %s not found or no get callback\n", __func__, name);
		return -EINVAL;
	}

	/* Invoke get callback with security signature check (represented here by type verification) */
	if (node_ops_list[i].get(buf, node_ops_list[i].priv) >= 0) {
		if (sscanf(buf, "%d", &val) == 1)
			return val;
		pr_err("%s: failed to parse val from '%s'\n", __func__, buf);
	}

	return -EINVAL;
}
EXPORT_SYMBOL(zte_misc_get_node_val);

/* ======================================================================
 * Common Callbacks interfaces (exposed to other subsystems)
 * ====================================================================== */

int zte_misc_common_callback_get(void *a1, const char **val_ptr)
{
	char name_buf[64];
	const char *val_str = *val_ptr;
	int i;

	memset(name_buf, 0, sizeof(name_buf));
	if (sscanf(val_str, "%63s", name_buf) != 1) {
		pr_err("%s: sscanf failed\n", __func__);
		return -EINVAL;
	}

	for (i = 0; i < NODE_OPS_COUNT; i++) {
		size_t key_len = strlen(node_ops_list[i].name);
		if (strncmp(node_ops_list[i].name, name_buf, key_len) == 0) {
			if (key_len == strlen(name_buf)) {
				if (node_ops_list[i].get) {
					return node_ops_list[i].get(a1, node_ops_list[i].priv);
				}
			}
		}
	}

	return -EINVAL;
}
EXPORT_SYMBOL(zte_misc_common_callback_get);

int zte_misc_common_callback_set(void *a1, const char **val_ptr)
{
	char name_buf[64];
	const char *val_str = *val_ptr;
	int i;

	memset(name_buf, 0, sizeof(name_buf));
	if (sscanf(val_str, "%63s", name_buf) != 1) {
		pr_err("%s: sscanf failed\n", __func__);
		return -EINVAL;
	}

	for (i = 0; i < NODE_OPS_COUNT; i++) {
		size_t key_len = strlen(node_ops_list[i].name);
		if (strncmp(node_ops_list[i].name, name_buf, key_len) == 0) {
			if (key_len == strlen(name_buf)) {
				if (node_ops_list[i].set) {
					return node_ops_list[i].set(a1, node_ops_list[i].priv);
				}
			}
		}
	}

	return -EINVAL;
}
EXPORT_SYMBOL(zte_misc_common_callback_set);

/* ======================================================================
 * Battery Capacity & OEM Pack Helpers
 * ====================================================================== */

static const int battery_vendor_id[] = { 0, 1, 2, 3, 4, 5, 6, 7 };
static int resistance_kohm[] = { 10, 20, 30, 40, 50, 60, 70, 80 };

ssize_t battery_module_pack_vendor_get(char *buf)
{
	struct power_supply *psy;
	union power_supply_propval val;
	int temp_resistance = 0;
	int vendor_idx = 0;
	int i;

	psy = power_supply_get_by_name("battery");
	if (!psy) {
		pr_err("%s: battery power supply not found\n", __func__);
		return -ENODEV;
	}

	/* Read resistance property (assuming property index 36 matches ZTE customization) */
	if (power_supply_get_property(psy, 36, &val) == 0) {
		temp_resistance = val.intval;
	}
	power_supply_put(psy);

	pr_info("%s: battery resistance = %d\n", __func__, temp_resistance);

	/* Determine vendor based on closest resistance bracket */
	for (i = 0; i < ARRAY_SIZE(resistance_kohm); i++) {
		if (temp_resistance < resistance_kohm[i]) {
			vendor_idx = i;
			break;
		}
	}
	if (i == ARRAY_SIZE(resistance_kohm))
		vendor_idx = ARRAY_SIZE(resistance_kohm) - 1;

	int vendor = battery_vendor_id[vendor_idx];
	pr_info("%s: vendor_idx = %d, vendor = %d\n", __func__, vendor_idx, vendor);

	return snprintf(buf, PAGE_SIZE, "%2d", vendor);
}

int zte_misc_get_design_capacity(char *buf)
{
	struct power_supply *psy;
	union power_supply_propval val;
	int cap = 0;

	psy = power_supply_get_by_name("battery");
	if (psy) {
		/* Read design capacity (assuming property index 22 matches ZTE customization) */
		if (power_supply_get_property(psy, 22, &val) != 0) {
			pr_err("%s: failed to get design capacity property\n", __func__);
		} else {
			cap = val.intval;
		}
		power_supply_put(psy);

		if (cap > 999999)
			cap = cap / 1000;
	} else {
		pr_err("%s: battery power supply not found\n", __func__);
	}

	pr_info("%s: capacity = %d\n", __func__, cap);
	return snprintf(buf, PAGE_SIZE, "%d", cap);
}
EXPORT_SYMBOL(zte_misc_get_design_capacity);

/* ======================================================================
 * Timezone, Power-off Charging and GPIO Helpers
 * ====================================================================== */

int zte_timezone_setup(const char *val)
{
	long tz;
	int ret;

	ret = kstrtol(val, 10, &tz);
	if (!ret) {
		zte_timezone = tz;
		return 1;
	}
	return ret;
}
EXPORT_SYMBOL(zte_timezone_setup);

int zte_poweroff_charging_handle(const char *val)
{
	zte_poweroff_charging = (strncmp(val, "charger", 7) == 0);
	pr_info("%s: charger option = %d\n", __func__, zte_poweroff_charging);
	return 0;
}
EXPORT_SYMBOL(zte_poweroff_charging_handle);

int zte_poweroff_charging_status(void)
{
	pr_info("%s: active status = %d, param = %d\n", __func__,
		zte_poweroff_charging, zte_poweroff_charging_param);
	return zte_poweroff_charging || zte_poweroff_charging_param;
}
EXPORT_SYMBOL(zte_poweroff_charging_status);

unsigned int get_sysnumber_byname(const char *name)
{
	int i;

	for (i = 0; i < 16; i++) {
		if (zte_gpios[i].label && strcmp(zte_gpios[i].label, name) == 0) {
			return zte_gpios[i].gpio;
		}
	}
	return 0;
}
EXPORT_SYMBOL(get_sysnumber_byname);

/* ======================================================================
 * Module Parameters
 * ====================================================================== */

static int param_get_battery_vendor(char *buffer, const struct kernel_param *kp)
{
	return battery_module_pack_vendor_get(buffer);
}

static const struct kernel_param_ops battery_vendor_param_ops = {
	.get = param_get_battery_vendor,
};
module_param_cb(battery_module_pack_vendor, &battery_vendor_param_ops, NULL, 0444);

/* Timezone param */
module_param(zte_timezone, long, 0644);

static int param_get_design_capacity(char *buffer, const struct kernel_param *kp)
{
	return zte_misc_get_design_capacity(buffer);
}

static const struct kernel_param_ops design_capacity_param_ops = {
	.get = param_get_design_capacity,
};
module_param_cb(design_capacity, &design_capacity_param_ops, NULL, 0444);

/* Remaining parameters mapped to the node_ops get/set mechanisms */
static int param_node_ops_set(const char *val, const struct kernel_param *kp)
{
	int i;
	for (i = 0; i < NODE_OPS_COUNT; i++) {
		if (strcmp(node_ops_list[i].name, kp->name) == 0) {
			if (node_ops_list[i].set)
				return node_ops_list[i].set(val, node_ops_list[i].priv);
			break;
		}
	}
	return -EPERM;
}

static int param_node_ops_get(char *buffer, const struct kernel_param *kp)
{
	int i;
	for (i = 0; i < NODE_OPS_COUNT; i++) {
		if (strcmp(node_ops_list[i].name, kp->name) == 0) {
			if (node_ops_list[i].get)
				return node_ops_list[i].get(buffer, node_ops_list[i].priv);
			break;
		}
	}
	return -EPERM;
}

static const struct kernel_param_ops node_ops_param_ops = {
	.set = param_node_ops_set,
	.get = param_node_ops_get,
};

/* Register each node property as a module parameter dynamic callback */
#define DEFINE_NODE_PARAM(node_name) \
	module_param_cb(node_name, &node_ops_param_ops, NULL, 0664)

DEFINE_NODE_PARAM(enable_to_shutdown);
DEFINE_NODE_PARAM(enable_to_dump_reg);
DEFINE_NODE_PARAM(demo_charging_policy);
DEFINE_NODE_PARAM(expired_charging_policy);
DEFINE_NODE_PARAM(charging_time_sec);
DEFINE_NODE_PARAM(force_disching_sec);
DEFINE_NODE_PARAM(policy_cap_min);
DEFINE_NODE_PARAM(policy_cap_max);
DEFINE_NODE_PARAM(policy_enable);
DEFINE_NODE_PARAM(bcl_demon_switch);
DEFINE_NODE_PARAM(qc3dp_sleep_mode);
DEFINE_NODE_PARAM(screen_on);
DEFINE_NODE_PARAM(wireless_charging_signal_good);
DEFINE_NODE_PARAM(wireless_efficiency);
DEFINE_NODE_PARAM(wireless_signal_strength);
DEFINE_NODE_PARAM(wireless_tx_rx);
DEFINE_NODE_PARAM(wireless_debug);
DEFINE_NODE_PARAM(pe1_debug);
DEFINE_NODE_PARAM(pd_debug);
DEFINE_NODE_PARAM(super_charge_mode);
DEFINE_NODE_PARAM(charge_remain_time);
DEFINE_NODE_PARAM(batt_temp_debug);
DEFINE_NODE_PARAM(cap_debug);
DEFINE_NODE_PARAM(charger_power);
DEFINE_NODE_PARAM(thermal_control_en);
DEFINE_NODE_PARAM(charge_type_oem);
DEFINE_NODE_PARAM(wls_nu_cep);
DEFINE_NODE_PARAM(wls_nu_iout);
DEFINE_NODE_PARAM(wls_nu_usbtype);
DEFINE_NODE_PARAM(wls_nu_vout);
DEFINE_NODE_PARAM(wls_nu_vrect);
DEFINE_NODE_PARAM(wls_boost_en);
DEFINE_NODE_PARAM(wls_nu_fw_update);
DEFINE_NODE_PARAM(wls_nu_ver);
DEFINE_NODE_PARAM(wls_nu_sleep);
DEFINE_NODE_PARAM(zlog_enable_test);

/* ======================================================================
 * Platform Driver Probe & Remove
 * ====================================================================== */

static int zte_misc_probe(struct platform_device *pdev)
{
	struct device_node *np = pdev->dev.of_node;
	struct device_node *child;
	struct device_node *chosen;
	const char *bootargs = NULL;
	char mode_buf[32];
	int gpio_idx = 0;

	pr_info("%s: entering\n", __func__);

	/* Parse kmparam.mode from chosen node bootargs */
	chosen = of_find_node_opts_by_path("/chosen", NULL);
	if (chosen) {
		if (of_property_read_string(chosen, "bootargs", &bootargs) == 0) {
			const char *p = strstr(bootargs, "kmparam.mode=");
			if (p) {
				memset(mode_buf, 0, sizeof(mode_buf));
				if (sscanf(p, "kmparam.mode=%31s", mode_buf) == 1) {
					/* "charger" is 0x63686172676572, represented as hex checks in orig */
					if (strcmp(mode_buf, "charger") == 0) {
						zte_poweroff_charging_param = true;
					}
					pr_info("%s: parsed kmparam.mode=%s (%d)\n",
						__func__, mode_buf, zte_poweroff_charging_param);
				}
			} else {
				pr_info("%s: kmparam.mode not found in bootargs\n", __func__);
			}
		} else {
			pr_warn("%s: failed to read bootargs from chosen\n", __func__);
		}
		of_node_put(chosen);
	} else {
		pr_warn("%s: /chosen node not found\n", __func__);
	}

	if (!np) {
		pr_err("%s: no device tree node found\n", __func__);
		return -ENODEV;
	}

	/* Parse child nodes for GPIO mappings */
	for_each_child_of_node(np, child) {
		const char *label;

		if (!of_find_property(child, "label", NULL)) {
			dev_warn(&pdev->dev, "Found node without label\n");
			continue;
		}

		if (gpio_idx >= 16) {
			pr_warn("%s: reached maximum limit of 16 GPIO entries\n", __func__);
			of_node_put(child);
			break;
		}

		if (of_property_read_string(child, "label", &label) == 0) {
			int gpio = of_get_named_gpio(child, "zte-misc", 0);
			if (gpio_is_valid(gpio)) {
				zte_gpios[gpio_idx].gpio = gpio;
				zte_gpios[gpio_idx].label = kstrdup(label, GFP_KERNEL);
				pr_info("%s: index %d, label '%s' mapped to GPIO %d\n",
					__func__, gpio_idx, label, gpio);
				gpio_idx++;
			}
		}
	}

	pr_info("%s: probe completed successfully\n", __func__);
	return 0;
}

static void zte_misc_remove(struct platform_device *pdev)
{
	int i;

	for (i = 0; i < 16; i++) {
		if (zte_gpios[i].label) {
			kfree(zte_gpios[i].label);
			zte_gpios[i].label = NULL;
		}
	}
	pr_info("%s: removed\n", __func__);
}

static const struct of_device_id zte_misc_match_table[] = {
	{ .compatible = "zte,zte-misc", },
	{ },
};
MODULE_DEVICE_TABLE(of, zte_misc_match_table);

static struct platform_driver zte_misc_device_driver = {
	.probe = zte_misc_probe,
	.remove = zte_misc_remove,
	.driver = {
		.name = DRV_NAME,
		.of_match_table = zte_misc_match_table,
	},
};

static int __init zte_misc_driver_init(void)
{
	pr_info("%s: registering platform driver\n", __func__);
	return platform_driver_register(&zte_misc_device_driver);
}

static void __exit zte_misc_driver_exit(void)
{
	platform_driver_unregister(&zte_misc_device_driver);
}

module_init(zte_misc_driver_init);
module_exit(zte_misc_driver_exit);

MODULE_DESCRIPTION("ZTE Miscellaneous and Common Callback Driver");
MODULE_LICENSE("GPL");
MODULE_AUTHOR("ZTE Corporation (reconstructed)");
