#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/platform_device.h>
#include <linux/power_supply.h>
#include <linux/notifier.h>
#include <linux/alarmtimer.h>
#include <linux/workqueue.h>
#include <linux/timer.h>
#include <linux/of.h>
#include <linux/of_device.h>
#include <linux/slab.h>
#include <linux/ktime.h>
#include <linux/pm_wakeup.h>
#include <linux/delay.h>

/* Forward declarations */
struct charger_policy;
struct zte_power_supply;

/* Custom ZTE API declarations */
extern struct zte_power_supply *zte_power_supply_get_by_name(const char *name);
extern void zte_power_supply_put(struct zte_power_supply *psy);
extern int zte_power_supply_get_property(struct zte_power_supply *psy,
					 enum power_supply_property psp,
					 union power_supply_propval *val);
extern int zte_power_supply_set_property(struct zte_power_supply *psy,
					 enum power_supply_property psp,
					 const union power_supply_propval *val);
extern int zte_poweroff_charging_status(void);

struct zte_misc_cb {
	const char *name;
	int (*set)(const char *val, void *priv);
	int (*get)(char *val, void *priv);
	int (*show)(char *val, void *priv);
	void *priv;
};

extern int zte_misc_register_callback(const struct zte_misc_cb *cb, void *priv);

/* Layout of struct charger_policy aligned 1:1 with binary (544 bytes) */
struct charger_policy {
	union {
		struct {
			struct device *dev;                        /* 0x00 */
			struct power_supply *policy_psy;           /* 0x08 */
			struct notifier_block nb;                  /* 0x10 */
		};
		u8 pad1[40];
	};
	union {
		struct alarm timeout_alarm;                    /* 0x28 (40) */
		u8 pad2[120]; // 160 - 40 = 120
	};
	struct workqueue_struct *timeout_wq;               /* 0xA0 (160) */
	union {
		struct delayed_work timeout_work;              /* 0xA8 (168) */
		u8 pad3[104]; // 272 - 168 = 104
	};
	struct workqueue_struct *probe_wq;                 /* 0x110 (272) */
	union {
		struct delayed_work probe_work;                /* 0x118 (280) */
		u8 pad4[104]; // 384 - 280 = 104
	};

	/* DTS properties / configuration */
	u32 policy_enable;                                 /* 0x180 (384) */
	u32 expired_mode;                                  /* 0x184 (388) */
	u32 low_temp;                                      /* 0x188 (392) */
	u32 have_power_path;                               /* 0x18C (396) */
	u32 retry_times;                                   /* 0x190 (400) */
	u32 timeout_seconds;                               /* 0x194 (404) */
	u32 expired_max_cap;                               /* 0x198 (408) */
	u32 expired_min_cap;                               /* 0x19C (412) */
	u32 demo_max_cap;                                  /* 0x1A0 (416) */
	u32 demo_min_cap;                                  /* 0x1A4 (420) */
	u32 no_powerpath_delta;                            /* 0x1A8 (424) */

	u32 pad5;                                          /* 0x1AC (428) */

	/* String properties */
	const char *interface_phy_name;                    /* 0x1B0 (432) */
	const char *battery_phy_name;                      /* 0x1B8 (440) */
	const char *zte_battery_phy_name;                  /* 0x1C0 (448) */
	const char *zte_usb_phy_name;                      /* 0x1C8 (456) */
	const char *cas_phy_name;                          /* 0x1D0 (464) */

	u32 raw_field_472;                                 /* 0x1D8 (472) */
	u32 pad6;                                          /* 0x1DC (476) */

	struct wakeup_source *ws;                          /* 0x1E0 (480) */
	u32 policy_disabled;                               /* 0x1E8 (488) */
	u32 status;                                        /* 0x1EC (492) */
	u32 last_status;                                   /* 0x1F0 (496) */
	u32 timeout_seconds_runtime;                       /* 0x1F4 (500) */
	u32 force_discharging_sec;                         /* 0x1F8 (504) */
	u32 force_discharging_sec_set_val;                 /* 0x1FC (508) */
	u64 force_discharging_sec_nanoseconds;             /* 0x200 (512) */
	u64 force_discharging_start_time;                  /* 0x208 (520) */

	u8 pad7[8];                                        /* 0x210 (528) */

	/* Status booleans / bytes */
	u8 low_temp_status;                                /* 0x218 (536) */
	u8 demo_sts;                                       /* 0x219 (537) */
	u8 expired_sts;                                    /* 0x21A (538) */
	u8 running_discharging;                            /* 0x21B (539) */
	u8 force_discharging_enable;                       /* 0x21C (540) */
	u8 log_limit;                                      /* 0x21D (541) */
	u8 padding2[2];                                    /* 0x21E (542) */
};

/* Global logger limit tracker and probe count */
static u64 charger_policy_logger_limit_time_pre_0;
static u32 charger_policy_check_retry_probe_count;

/* Status functions */
static int charger_policy_status_disable(struct charger_policy *policy);
static int charger_policy_status_runchging(struct charger_policy *policy);
static int charger_policy_status_ide(struct charger_policy *policy);
static int charger_policy_status_rundischging(struct charger_policy *policy);
static int charger_policy_status_forcedischging(struct charger_policy *policy);

struct charger_policy_status_item {
	int id;
	const char *name;
	int (*handler)(struct charger_policy *policy);
};

static const struct charger_policy_status_item policy_status_list[] = {
	{ 0, "POLICY_DISABLE", charger_policy_status_disable },
	{ 1, "POLICY_RUNNING_CHARGING", charger_policy_status_runchging },
	{ 2, "POLICY_IDLE", charger_policy_status_ide },
	{ 3, "POLICY_RUNNING_DISCHARGING", charger_policy_status_rundischging },
	{ 4, "POLICY_STATUS_FORCE_DISCHARGING", charger_policy_status_forcedischging },
};

/* Helper function to get current real-time in seconds */
static u64 get_current_time_seconds(void)
{
	struct timespec64 ts;
	ts = ns_to_timespec64(ktime_to_ns(ktime_get_real()));
	return ts.tv_sec;
}

/* Get property by name (for standard Linux power supplies) */
static int charger_policy_get_prop_by_name(const char *name, unsigned int prop, u32 *val)
{
	struct power_supply *psy;
	union power_supply_propval pval;
	int ret;

	if (!name) {
		pr_info("policy: %s(): name is null\n", "charger_policy_get_prop_by_name");
		return -EINVAL;
	}

	psy = power_supply_get_by_name(name);
	if (!psy) {
		pr_info("policy: %s(): get %s power supply failed\n", "charger_policy_get_prop_by_name", name);
		return -ENODEV;
	}

	ret = power_supply_get_property(psy, prop, &pval);
	if (ret < 0) {
		pr_info("policy: %s(): get property %u failed from %s\n", "charger_policy_get_prop_by_name", prop, name);
		return ret;
	}

	*val = pval.intval;
	power_supply_put(psy);
	return 0;
}

/* Get property by name (for custom ZTE power supplies) */
static int zte_charger_policy_get_prop_by_name(const char *name, unsigned int prop, u32 *val)
{
	struct zte_power_supply *psy;
	union power_supply_propval pval;
	int ret;

	if (!name) {
		pr_info("policy: %s(): name is null\n", "zte_charger_policy_get_prop_by_name");
		return -EINVAL;
	}

	psy = zte_power_supply_get_by_name(name);
	if (!psy) {
		pr_info("policy: %s(): get %s power supply failed\n", "zte_charger_policy_get_prop_by_name", name);
		return -ENODEV;
	}

	ret = zte_power_supply_get_property(psy, prop, &pval);
	if (ret < 0) {
		pr_info("policy: %s(): get property %u failed from %s\n", "zte_charger_policy_get_prop_by_name", prop, name);
		return ret;
	}

	*val = pval.intval;
	zte_power_supply_put(psy);
	return 0;
}

/* Set property by name (for custom ZTE power supplies) */
static int zte_charger_policy_set_prop_by_name(const char *name, unsigned int prop, u32 val)
{
	struct zte_power_supply *psy;
	union power_supply_propval pval;
	int ret;

	if (!name) {
		pr_info("policy: %s(): name is null\n", "zte_charger_policy_set_prop_by_name");
		return -EINVAL;
	}

	psy = zte_power_supply_get_by_name(name);
	if (!psy) {
		pr_info("policy: %s(): get %s power supply failed\n", "zte_charger_policy_set_prop_by_name", name);
		return -ENODEV;
	}

	pval.intval = val;
	ret = zte_power_supply_set_property(psy, prop, &pval);
	if (ret < 0) {
		pr_info("policy: %s(): set property %u failed to %s\n", "zte_charger_policy_set_prop_by_name", prop, name);
	}

	zte_power_supply_put(psy);
	return ret;
}

/* Control charging state through ZTE battery power supply properties */
static int charger_policy_ctrl_charging_enable(struct charger_policy *policy, u32 batt_chg, u32 global_chg)
{
	u32 status_val = 0;
	u32 cur_chg_enabled = 0;
	u32 cur_batt_enabled = 0;
	bool is_charging;
	int ret;

	ret = charger_policy_get_prop_by_name(policy->battery_phy_name, POWER_SUPPLY_PROP_STATUS, &status_val);
	if (ret < 0) {
		pr_info("policy: %s(): Get charging status failed\n", "charger_policy_ctrl_charging_enable");
		is_charging = false;
	} else {
		is_charging = (status_val == POWER_SUPPLY_STATUS_CHARGING || status_val == POWER_SUPPLY_STATUS_FULL);
		pr_info("policy: %s(): is_charging: %d\n", "charger_policy_ctrl_charging_enable", is_charging);
	}

	pr_info("policy: %s(): charging_enabled: %d\n", "charger_policy_ctrl_charging_enable", is_charging);

	/* Property index 3 for ZTE battery is CHARGING_ENABLED */
	ret = zte_charger_policy_get_prop_by_name(policy->zte_battery_phy_name, 3, &cur_chg_enabled);
	if (ret < 0) {
		pr_info("policy: %s(): Failed to get POWER_SUPPLY_PROP_CHARGING_ENABLED!\n", "charger_policy_ctrl_charging_enable");
		return 0;
	}

	pr_info("policy: %s(): current charging enabled status: %u\n", "charger_policy_ctrl_charging_enable", cur_chg_enabled);

	/* Property index 4 for ZTE battery is BATTERY_CHARGING_ENABLED */
	ret = zte_charger_policy_get_prop_by_name(policy->zte_battery_phy_name, 4, &cur_batt_enabled);
	if (ret < 0) {
		pr_info("policy: %s(): Failed to get POWER_SUPPLY_PROP_BATTERY_CHARGING_ENABLED!\n", "charger_policy_ctrl_charging_enable");
		return 0;
	}

	pr_info("policy: %s(): current battery charging enabled status: %u\n", "charger_policy_ctrl_charging_enable", cur_batt_enabled);

	if (cur_chg_enabled != global_chg) {
		pr_info("policy: %s(): setting charging_enabled to %u\n", "charger_policy_ctrl_charging_enable", global_chg);
		ret = zte_charger_policy_set_prop_by_name(policy->zte_battery_phy_name, 3, global_chg);
		if (ret < 0) {
			pr_info("policy: %s(): Set CHARGING_ENABLED failed\n", "charger_policy_ctrl_charging_enable");
			return 0;
		}
	}

	if (cur_batt_enabled != batt_chg) {
		pr_info("policy: %s(): setting battery_charging_enabled to %u\n", "charger_policy_ctrl_charging_enable", batt_chg);
		ret = zte_charger_policy_set_prop_by_name(policy->zte_battery_phy_name, 4, batt_chg);
		if (ret < 0) {
			pr_info("policy: %s(): Set BATTERY_CHARGING_ENABLED failed\n", "charger_policy_ctrl_charging_enable");
			return 0;
		}
	}

	return 1;
}

/* Disable or enable CAS (Charge Arbitration System) */
static int charger_policy_disable_cas(struct charger_policy *policy, u32 disable)
{
	struct power_supply *psy;
	union power_supply_propval pval;
	int ret;

	pr_info("policy: %s(): disable cas %d\n", "charger_policy_disable_cas", disable);

	if (!policy->cas_phy_name) {
		pr_info("policy: %s(): cas_phy_name is null\n", "charger_policy_disable_cas");
		return -EINVAL;
	}

	psy = power_supply_get_by_name(policy->cas_phy_name);
	if (!psy) {
		pr_info("policy: %s(): get cas power supply failed\n", "charger_policy_disable_cas");
		return -ENODEV;
	}

	pval.intval = disable;
	/* Property index 5 for CAS is AUTHENTIC */
	ret = power_supply_set_property(psy, POWER_SUPPLY_PROP_AUTHENTIC, &pval);
	if (ret < 0) {
		pr_info("policy: %s(): Failed to disable cas rc=%d\n", "charger_policy_disable_cas", ret);
	}

	power_supply_put(psy);
	return ret;
}

/* Check USB presence and online status across interfaces */
static bool charger_policy_check_usb_present(struct charger_policy *policy)
{
	struct power_supply *psy;
	union power_supply_propval pval;
	u32 online = 0;
	u32 suspend = 0;
	u32 present = 0;
	bool wireless_online = false;
	int ret;

	psy = power_supply_get_by_name("usb");
	if (psy) {
		ret = power_supply_get_property(psy, POWER_SUPPLY_PROP_ONLINE, &pval);
		if (ret >= 0) {
			online = pval.intval;
		} else {
			pr_info("policy: %s(): Failed to get POWER_SUPPLY_PROP_ONLINE!\n", "charger_policy_check_usb_present");
		}
		power_supply_put(psy);
	} else {
		pr_info("policy: %s(): usb power supply not found\n", "charger_policy_check_usb_present");
	}

	pr_info("policy: %s(): usb_online: %u\n", "charger_policy_check_usb_present", online);

	/* Property index 17 for USB is USB_SUSPEND */
	ret = zte_charger_policy_get_prop_by_name(policy->zte_usb_phy_name, 17, &suspend);
	if (ret < 0) {
		pr_info("policy: %s(): Get POWER_SUPPLY_PROP_USB_SUSPEND failed\n", "charger_policy_check_usb_present");
	}

	pr_info("policy: %s(): usb_suspend: %u\n", "charger_policy_check_usb_present", suspend);

	/* Property index 18 for USB is USB_PRESENT */
	ret = zte_charger_policy_get_prop_by_name(policy->zte_usb_phy_name, 18, &present);
	if (ret < 0) {
		pr_info("policy: %s(): Get POWER_SUPPLY_PROP_USB_PRESENT failed\n", "charger_policy_check_usb_present");
	}

	pr_info("policy: %s(): usb_present: %u\n", "charger_policy_check_usb_present", present);

	psy = power_supply_get_by_name("wireless");
	if (psy) {
		ret = power_supply_get_property(psy, POWER_SUPPLY_PROP_ONLINE, &pval);
		if (ret >= 0) {
			wireless_online = (pval.intval != 0);
		} else {
			pr_info("policy: %s(): Failed to get POWER_SUPPLY_PROP_ONLINE for wireless!\n", "charger_policy_check_usb_present");
		}
		power_supply_put(psy);
	}

	return suspend || online || present || wireless_online;
}

/* Check if SOC/Capacity has reached configured lower thresholds */
static bool charger_policy_check_soc_reach_min(struct charger_policy *policy)
{
	u32 capacity = 0;
	int limit = 0;
	int ret;

	ret = charger_policy_get_prop_by_name(policy->battery_phy_name, POWER_SUPPLY_PROP_CAPACITY, &capacity);
	if (ret < 0) {
		pr_info("policy: %s(): Get battery capacity failed\n", "charger_policy_check_soc_reach_min");
		return false;
	}

	if (policy->log_limit) {
		pr_info("policy: %s(): demo_enable(%d), overtime_enable(%d, %d), powerpath(%d)\n",
			"charger_policy_check_soc_reach_min",
			policy->demo_sts, policy->expired_sts, policy->running_discharging, policy->force_discharging_enable);
	}

	if (policy->demo_sts) {
		limit = policy->demo_min_cap;
		if (!policy->force_discharging_enable)
			limit -= policy->no_powerpath_delta;

		if (policy->log_limit) {
			pr_info("policy: %s(): demo: cap_now(%u), cap_min(%d)\n", "charger_policy_check_soc_reach_min", capacity, limit);
		}

		if ((int)capacity <= limit) {
			pr_info("policy: %s(): capacity(%u) reach demo min(%d)\n", "charger_policy_check_soc_reach_min", capacity, limit);
			return true;
		}
	}

	if (policy->expired_sts && policy->running_discharging) {
		limit = policy->expired_min_cap;
		if (!policy->force_discharging_enable)
			limit -= policy->no_powerpath_delta;

		if (policy->log_limit) {
			pr_info("policy: %s(): overtime: cap_now(%u), cap_min(%d)\n", "charger_policy_check_soc_reach_min", capacity, limit);
		}

		if ((int)capacity <= limit) {
			pr_info("policy: %s(): capacity(%u) reach overtime min(%d)\n", "charger_policy_check_soc_reach_min", capacity, limit);
			return true;
		}
	}

	return false;
}

/* Handler: State 0 - POLICY_DISABLE */
static int charger_policy_status_disable(struct charger_policy *policy)
{
	charger_policy_ctrl_charging_enable(policy, 1, 1);
	policy->running_discharging = 0;
	policy->force_discharging_start_time = 0;
	policy->status = 0;
	policy->last_status = 0;
	return charger_policy_disable_cas(policy, 0);
}

/* Handler: State 1 - POLICY_RUNNING_CHARGING */
static int charger_policy_status_runchging(struct charger_policy *policy)
{
	u64 now_sec;
	u32 capacity = 0;
	int limit = 0;
	int ret;

	if (policy->force_discharging_enable) {
		now_sec = get_current_time_seconds();
		if (policy->log_limit) {
			pr_info("policy: %s(): force_discharging: (%llu - %llu = %llu) force_seconds: %u\n",
				"charger_policy_status_runchging",
				now_sec, policy->force_discharging_start_time,
				now_sec - policy->force_discharging_start_time,
				policy->force_discharging_sec);
		}

		if (now_sec - policy->force_discharging_start_time > policy->force_discharging_sec) {
			policy->last_status = policy->status;
			policy->status = 3; /* Transition to State 3: POLICY_RUNNING_DISCHARGING */
			pr_info("policy: %s(): time is too long, force discharging\n", "charger_policy_status_runchging");
			return 0;
		}
	}

	charger_policy_ctrl_charging_enable(policy, 1, 1);

	ret = charger_policy_get_prop_by_name(policy->battery_phy_name, POWER_SUPPLY_PROP_CAPACITY, &capacity);
	if (ret < 0) {
		pr_info("policy: %s(): Get battery capacity failed\n", "charger_policy_status_runchging");
		return 0;
	}

	if (policy->log_limit) {
		pr_info("policy: %s(): demo_enable(%d), overtime_enable(%d, %d), powerpath(%d)\n",
			"charger_policy_status_runchging",
			policy->demo_sts, policy->expired_sts, policy->running_discharging, policy->force_discharging_enable);
	}

	if (policy->demo_sts) {
		if (policy->force_discharging_enable) {
			limit = policy->demo_max_cap;
			if (policy->last_status != 0) {
				limit = (policy->demo_min_cap + limit) / 2;
			}
		} else {
			limit = policy->no_powerpath_delta + policy->demo_max_cap;
		}

		if (policy->log_limit) {
			pr_info("policy: %s(): demo: cap_now(%u), cap_max(%d)\n", "charger_policy_status_runchging", capacity, limit);
		}

		if ((int)capacity >= limit) {
			pr_info("policy: %s(): capacity(%u) reach demo max(%d)\n", "charger_policy_status_runchging", capacity, limit);
			policy->last_status = policy->status;
			policy->status = 2; /* Transition to State 2: POLICY_IDLE */
			charger_policy_ctrl_charging_enable(policy, 0, 0);
			charger_policy_disable_cas(policy, 1);
			return 0;
		}
	}

	if (policy->expired_sts && policy->running_discharging) {
		if (policy->force_discharging_enable) {
			limit = policy->expired_max_cap;
			if (policy->last_status != 0) {
				limit = (policy->expired_min_cap + limit) / 2;
			}
		} else {
			limit = policy->no_powerpath_delta + policy->expired_max_cap;
		}

		if (policy->log_limit) {
			pr_info("policy: %s(): overtime: cap_now(%u), cap_max(%d)\n", "charger_policy_status_runchging", capacity, limit);
		}

		if ((int)capacity >= limit) {
			pr_info("policy: %s(): capacity(%u) reach overtime max(%d)\n", "charger_policy_status_runchging", capacity, limit);
			policy->last_status = policy->status;
			policy->status = 2; /* Transition to State 2: POLICY_IDLE */
			charger_policy_ctrl_charging_enable(policy, 0, 0);
			charger_policy_disable_cas(policy, 1);
		}
	}

	return 0;
}

/* Handler: State 2 - POLICY_IDLE */
static int charger_policy_status_ide(struct charger_policy *policy)
{
	u64 now_sec;

	if (policy->log_limit) {
		pr_info("policy: %s(): demo_enable: %d overtime_enable: %d\n",
			"charger_policy_status_ide", policy->demo_sts, policy->expired_sts);
	}

	now_sec = get_current_time_seconds();

	if (policy->demo_sts) {
		pr_info("policy: %s(): demo enabled, policy enter into running\n", "charger_policy_status_ide");
		charger_policy_disable_cas(policy, 1);
		policy->last_status = policy->status;
		policy->status = 1; /* Transition to State 1: POLICY_RUNNING_CHARGING */
		policy->force_discharging_start_time = now_sec;
		pr_info("policy: %s(): demo_enable status changed!!!\n", "charger_policy_status_ide");
	} else {
		if (policy->force_discharging_start_time == 0) {
			policy->force_discharging_start_time = now_sec;
			pr_info("policy: %s(): overtime init begin %llu\n", "charger_policy_status_ide", now_sec);
		}

		if (policy->log_limit) {
			pr_info("policy: %s(): overtime_now: (%llu - %llu = %llu) overtime_seconds: %u\n",
				"charger_policy_status_ide",
				now_sec, policy->force_discharging_start_time,
				now_sec - policy->force_discharging_start_time,
				policy->timeout_seconds_runtime);
		}

		if (now_sec - policy->force_discharging_start_time >= policy->timeout_seconds_runtime) {
			pr_info("policy: %s(): overtime found, policy enter into running\n", "charger_policy_status_ide");
			charger_policy_disable_cas(policy, 1);
			policy->last_status = policy->status;
			policy->running_discharging = 1;
			policy->status = 1; /* Transition to State 1: POLICY_RUNNING_CHARGING */
		}
	}

	return 0;
}

/* Handler: State 3 - POLICY_RUNNING_DISCHARGING */
static int charger_policy_status_rundischging(struct charger_policy *policy)
{
	u64 now_sec;
	u32 capacity = 0;
	int cap_max = 0;
	int cap_mid = 0;
	int limit = 0;
	int ret;

	if (policy->force_discharging_enable) {
		now_sec = get_current_time_seconds();
		if (policy->log_limit) {
			pr_info("policy: %s(): force_discharging: (%llu - %llu = %llu) force_seconds: %u\n",
				"charger_policy_status_rundischging",
				now_sec, policy->force_discharging_start_time,
				now_sec - policy->force_discharging_start_time,
				policy->force_discharging_sec);
		}

		if (now_sec - policy->force_discharging_start_time > policy->force_discharging_sec) {
			policy->last_status = policy->status;
			policy->status = 3; /* Remain in State 3 */
			pr_info("policy: %s(): time is too long, force discharging\n", "charger_policy_status_rundischging");
			goto check_min;
		}
	}

	ret = charger_policy_get_prop_by_name(policy->battery_phy_name, POWER_SUPPLY_PROP_CAPACITY, &capacity);
	if (ret < 0) {
		pr_info("policy: %s(): Get battery capacity failed\n", "charger_policy_status_rundischging");
		goto check_min;
	}

	if (policy->expired_sts && policy->running_discharging) {
		cap_max = policy->expired_max_cap;
		if (!policy->force_discharging_enable)
			cap_max += policy->no_powerpath_delta;

		cap_mid = (policy->expired_min_cap + policy->expired_max_cap) / 2;

		if (policy->log_limit) {
			pr_info("policy: %s(): dischgmode(overtime): cap_now(%u), cap_max(%d), middle_cap(%d)\n",
				"charger_policy_status_rundischging", capacity, cap_max, cap_mid);
		}
	}

	if (policy->demo_sts) {
		limit = policy->demo_max_cap;
		if (!policy->force_discharging_enable)
			limit += policy->no_powerpath_delta;

		cap_mid = (policy->demo_min_cap + policy->demo_max_cap) / 2;

		if (policy->log_limit) {
			pr_info("policy: %s(): demo: cap_now(%u), cap_min(%d)\n", "charger_policy_status_rundischging", capacity, limit);
		}

		if ((int)capacity < limit) {
			if ((int)capacity <= cap_mid) {
				charger_policy_ctrl_charging_enable(policy, 0, 1);
			}
			goto check_min;
		}
	} else {
		if ((int)capacity < cap_max) {
			if ((int)capacity <= cap_mid) {
				charger_policy_ctrl_charging_enable(policy, 0, 1);
			}
			goto check_min;
		}
	}

	if (!charger_policy_ctrl_charging_enable(policy, 0, 0)) {
		pr_info("policy: %s(): disabling charger failed, cancel alarm timer\n", "charger_policy_status_rundischging");
		alarm_try_to_cancel(&policy->timeout_alarm);
	}

check_min:
	if (charger_policy_check_soc_reach_min(policy)) {
		now_sec = get_current_time_seconds();
		policy->last_status = policy->status;
		policy->status = 1; /* Transition back to State 1: POLICY_RUNNING_CHARGING */
		pr_info("policy: %s(): soc_reach_min, calling charger_policy_ctrl_charging_enable\n", "charger_policy_status_rundischging");
		charger_policy_ctrl_charging_enable(policy, 1, 1);
		policy->force_discharging_start_time = now_sec;
		pr_info("policy: %s(): soc reach min found, reinit charging_begin %llu\n", "charger_policy_status_rundischging", now_sec);
	}

	return 0;
}

/* Handler: State 4 - POLICY_STATUS_FORCE_DISCHARGING */
static int charger_policy_status_forcedischging(struct charger_policy *policy)
{
	u64 now_sec;

	if (!charger_policy_ctrl_charging_enable(policy, 0, 0)) {
		alarm_try_to_cancel(&policy->timeout_alarm);
	}

	if (charger_policy_check_soc_reach_min(policy)) {
		now_sec = get_current_time_seconds();
		policy->last_status = policy->status;
		policy->status = 1; /* Transition to State 1: POLICY_RUNNING_CHARGING */
		charger_policy_ctrl_charging_enable(policy, 1, 1);
		policy->force_discharging_start_time = now_sec;
		pr_info("policy: %s(): soc reach min found, reinit charging_begin %llu\n", "charger_policy_status_forcedischging", now_sec);
	}

	return 0;
}

/* Timeout handler work function (state machine scheduler) */
static void charger_policy_timeout_handler_work(struct work_struct *work)
{
	struct charger_policy *policy = container_of(work, struct charger_policy, timeout_work.work);
	u64 now_sec;
	u32 batt_temp = 0;
	int ret;

	now_sec = get_current_time_seconds();
	policy->log_limit = 0;

	if (now_sec - charger_policy_logger_limit_time_pre_0 >= 301) {
		charger_policy_logger_limit_time_pre_0 = now_sec;
		policy->log_limit = 1;
	}

	/* Get battery temperature */
	ret = charger_policy_get_prop_by_name(policy->battery_phy_name, POWER_SUPPLY_PROP_TEMP, &batt_temp);
	if (ret < 0) {
		pr_info("policy: %s(): Get battery temp failed\n", "charger_policy_timeout_handler_work");
	}

	if (policy->status != policy->last_status) {
		policy->log_limit = 1;
		if (policy->policy_psy) {
			power_supply_changed(policy->policy_psy);
		}
	}

	if (policy->log_limit) {
		if (policy->status < 5) {
			pr_info("policy: %s(): status=%s status=%s\n",
				"charger_policy_status_debug",
				policy_status_list[policy->status].name,
				(ret >= 0 && (batt_temp <= 150)) ? "discharging" : "charging");
		}
	}

	if (charger_policy_check_usb_present(policy)) {
		if (!policy->demo_sts && !policy->expired_sts) {
			pr_info("policy: %s(): demo_enable && overtime_enable is disable\n", "charger_policy_status_need_sleep");
			goto sleep_policy;
		}

		if (ret >= 0 && policy->low_temp_status && ((int)batt_temp <= 150)) {
			pr_info("policy: %s(): low temperature found.\n", "charger_policy_status_need_sleep");
			goto sleep_policy;
		}

		if (policy->policy_disabled) {
			pr_info("policy: %s(): policy force disabled\n", "charger_policy_status_need_sleep");
			goto sleep_policy;
		}

		if (policy->status < 5) {
			alarm_try_to_cancel(&policy->timeout_alarm);
			alarm_start_relative(&policy->timeout_alarm, ns_to_ktime(1000000LL * policy->force_discharging_sec_nanoseconds));
			if (policy->ws) {
				__pm_stay_awake(policy->ws);
			}

			switch (policy->status) {
			case 0:
				charger_policy_status_disable(policy);
				break;
			case 1:
				charger_policy_status_runchging(policy);
				break;
			case 2:
				charger_policy_status_ide(policy);
				break;
			case 3:
				charger_policy_status_rundischging(policy);
				break;
			case 4:
				charger_policy_status_forcedischging(policy);
				break;
			default:
				break;
			}

			if (policy->ws) {
				__pm_relax(policy->ws);
			}
			return;
		}

		/* Decompiler panic recreation */
		BUG();
	}

sleep_policy:
	if (policy->status != 0) {
		if (policy->ws) {
			__pm_stay_awake(policy->ws);
		}
		charger_policy_ctrl_charging_enable(policy, 1, 1);
		policy->expired_sts = 0;
		policy->force_discharging_start_time = 0;
		policy->status = 0;
		charger_policy_disable_cas(policy, 0);
		if (policy->ws) {
			__pm_relax(policy->ws);
		}
	} else {
		charger_policy_ctrl_charging_enable(policy, 1, 1);
		policy->expired_sts = 0;
		policy->force_discharging_start_time = 0;
		policy->status = 0;
		charger_policy_disable_cas(policy, 0);
	}

	alarm_try_to_cancel(&policy->timeout_alarm);
	if (policy->log_limit) {
		pr_info("policy: %s(): scheduler loop clean\n", "charger_policy_notifier_handler");
	}
}

/* Alarm timer callback */
static enum alarmtimer_restart charger_policy_timeout_alarm_cb(struct alarm *alarm, ktime_t now)
{
	struct charger_policy *policy = container_of(alarm, struct charger_policy, timeout_alarm);

	alarm_start_relative(alarm, ns_to_ktime(1000000LL * policy->force_discharging_sec_nanoseconds));
	if (!delayed_work_pending(&policy->timeout_work)) {
		queue_delayed_work(policy->timeout_wq, &policy->timeout_work, msecs_to_jiffies(25));
	}
	return ALARMTIMER_RESTART;
}

/* Power supply notifier switch callback */
static int charger_policy_notifier_switch(struct notifier_block *nb, unsigned long action, void *data)
{
	struct charger_policy *policy = container_of(nb, struct charger_policy, nb);
	struct power_supply *psy = data;

	if (action != 0) /* Only process property changes */
		return NOTIFY_OK;

	if (!delayed_work_pending(&policy->timeout_work)) {
		if (strcmp(psy->desc->name, policy->battery_phy_name) == 0 ||
		    strcmp(psy->desc->name, "usb") == 0) {
			queue_delayed_work(policy->timeout_wq, &policy->timeout_work, msecs_to_jiffies(50));
		}
	}

	return NOTIFY_OK;
}

/* Callback methods registered in zte_misc */
static int charger_policy_demo_sts_set(const char *val, void *priv)
{
	struct charger_policy *policy = priv;
	int val_int = 0;

	if (!policy) {
		pr_info("policy: %s(): priv is null\n", "charger_policy_demo_sts_set");
		return -EINVAL;
	}

	if (sscanf(val, "%d", &val_int) != 1)
		return -EINVAL;

	val_int = (val_int != 0);
	pr_info("policy: %s(): new demo status %d\n", "charger_policy_demo_sts_set", val_int);

	if (val_int != policy->demo_sts) {
		pr_info("policy: %s(): demo status changed, old=%d new=%d\n", "charger_policy_demo_sts_set", policy->demo_sts, val_int);
		policy->demo_sts = val_int;
		if (!policy->demo_sts) {
			if (policy->ws) {
				__pm_stay_awake(policy->ws);
			}
			charger_policy_status_disable(policy);
			if (policy->ws) {
				__pm_relax(policy->ws);
			}
		}
		queue_delayed_work(policy->timeout_wq, &policy->timeout_work, msecs_to_jiffies(25));
	}

	return 0;
}

static int charger_policy_demo_sts_get(char *buf, void *priv)
{
	struct charger_policy *policy = priv;

	if (!policy) {
		strcpy(buf, "arg is null");
		return 11;
	}

	pr_info("policy: %s(): Get demo_enable = 0x%x\n", "charger_policy_demo_sts_get", policy->demo_sts);
	buf[0] = policy->demo_sts ? '1' : '0';
	buf[1] = '\0';
	return 1;
}

static int charger_policy_expired_sts_get(char *buf, void *priv)
{
	struct charger_policy *policy = priv;

	if (!policy) {
		strcpy(buf, "arg is null");
		return 11;
	}

	buf[0] = policy->running_discharging ? '1' : '0';
	buf[1] = '\0';
	return 1;
}

static int charger_policy_expired_sec_set(const char *val, void *priv)
{
	struct charger_policy *policy = priv;
	int val_int = 0;

	if (!policy) {
		pr_info("policy: %s(): priv is null\n", "charger_policy_expired_sec_set");
		return -EINVAL;
	}

	if (sscanf(val, "%d", &val_int) != 1)
		return -EINVAL;

	policy->timeout_seconds_runtime = val_int;
	pr_info("policy: %s(): Set overtime_seconds = %d\n", "charger_policy_expired_sec_set", val_int);
	return 0;
}

static int charger_policy_expired_sec_get(char *buf, void *priv)
{
	struct charger_policy *policy = priv;

	if (!policy) {
		strcpy(buf, "arg is null");
		return 11;
	}

	pr_info("policy: %s(): Get overtime_seconds = %u\n", "charger_policy_expired_sec_get", policy->timeout_seconds_runtime);
	return snprintf(buf, PAGE_SIZE, "%u", policy->timeout_seconds_runtime);
}

static int charger_policy_force_disching_sec_set(const char *val, void *priv)
{
	struct charger_policy *policy = priv;
	int val_int = 0;

	if (!policy) {
		pr_info("policy: %s(): priv is null\n", "charger_policy_force_disching_sec_set");
		return -EINVAL;
	}

	if (sscanf(val, "%d", &val_int) != 1)
		return -EINVAL;

	policy->force_discharging_sec = val_int;
	pr_info("policy: %s(): Set force_disching_seconds = %d\n", "charger_policy_force_disching_sec_set", val_int);
	return 0;
}

static int charger_policy_force_disching_sec_get(char *buf, void *priv)
{
	struct charger_policy *policy = priv;

	if (!policy) {
		strcpy(buf, "arg is null");
		return 11;
	}

	pr_info("policy: %s(): Get force_disching_seconds = %u\n", "charger_policy_force_disching_sec_get", policy->force_discharging_sec);
	return snprintf(buf, PAGE_SIZE, "%u", policy->force_discharging_sec);
}

static int charger_policy_cap_min_set(const char *val, void *priv)
{
	struct charger_policy *policy = priv;
	int val_int = 0;

	if (!policy) {
		pr_info("policy: %s(): priv is null\n", "charger_policy_cap_min_set");
		return -EINVAL;
	}

	if (sscanf(val, "%d", &val_int) != 1)
		return -EINVAL;

	policy->demo_min_cap = val_int;
	policy->expired_min_cap = val_int;
	pr_info("policy: %s(): expired_capacity_min = %d\n", "charger_policy_cap_min_set", val_int);
	return 0;
}

static int charger_policy_cap_min_get(char *buf, void *priv)
{
	struct charger_policy *policy = priv;

	if (!policy) {
		strcpy(buf, "arg is null");
		return 11;
	}

	return snprintf(buf, PAGE_SIZE, "%u", policy->expired_min_cap);
}

static int charger_policy_cap_max_set(const char *val, void *priv)
{
	struct charger_policy *policy = priv;
	int val_int = 0;

	if (!policy) {
		pr_info("policy: %s(): priv is null\n", "charger_policy_cap_max_set");
		return -EINVAL;
	}

	if (sscanf(val, "%d", &val_int) != 1)
		return -EINVAL;

	policy->no_powerpath_delta = 0;
	policy->demo_max_cap = val_int;
	policy->expired_max_cap = val_int;
	pr_info("policy: %s(): expired_capacity_max = %d\n", "charger_policy_cap_max_set", val_int);
	return 0;
}

static int charger_policy_cap_max_get(char *buf, void *priv)
{
	struct charger_policy *policy = priv;

	if (!policy) {
		strcpy(buf, "arg is null");
		return 11;
	}

	return snprintf(buf, PAGE_SIZE, "%u", policy->expired_max_cap);
}

static int charger_policy_enable_status_set(const char *val, void *priv)
{
	struct charger_policy *policy = priv;
	int val_int = 0;

	if (!policy) {
		pr_info("policy: %s(): priv is null\n", "charger_policy_enable_status_set");
		return -EINVAL;
	}

	if (sscanf(val, "%d", &val_int) != 1)
		return -EINVAL;

	policy->policy_disabled = (val_int == 0);
	pr_info("policy: %s(): force_disable = %d\n", "charger_policy_enable_status_set", policy->policy_disabled);
	return 0;
}

static int charger_policy_enable_status_get(char *buf, void *priv)
{
	struct charger_policy *policy = priv;

	if (!policy) {
		strcpy(buf, "arg is null");
		return 11;
	}

	return snprintf(buf, PAGE_SIZE, "%u", policy->policy_disabled == 0);
}

/* zte_misc node structure registrations */
static const struct zte_misc_cb demo_charging_policy_node = {
	.name = "demo_charging_policy",
	.set = charger_policy_demo_sts_set,
	.get = charger_policy_demo_sts_get,
};

static const struct zte_misc_cb expired_charging_policy_node = {
	.name = "expired_charging_policy",
	.get = charger_policy_expired_sts_get,
};

static const struct zte_misc_cb charging_time_sec_node = {
	.name = "charging_time_sec",
	.set = charger_policy_expired_sec_set,
	.get = charger_policy_expired_sec_get,
};

static const struct zte_misc_cb force_disching_sec_node = {
	.name = "force_disching_sec",
	.set = charger_policy_force_disching_sec_set,
	.get = charger_policy_force_disching_sec_get,
};

static const struct zte_misc_cb policy_cap_min_node = {
	.name = "policy_cap_min",
	.set = charger_policy_cap_min_set,
	.get = charger_policy_cap_min_get,
};

static const struct zte_misc_cb policy_cap_max_node = {
	.name = "policy_cap_max",
	.set = charger_policy_cap_max_set,
	.get = charger_policy_cap_max_get,
};

static const struct zte_misc_cb policy_enable_node = {
	.name = "policy_enable",
	.set = charger_policy_enable_status_set,
	.get = charger_policy_enable_status_get,
};

/* Power supply properties and implementation of the standard driver interface */
static enum power_supply_property policy_psy_properties[] = {
	POWER_SUPPLY_PROP_PRESENT,
	POWER_SUPPLY_PROP_ONLINE,
	POWER_SUPPLY_PROP_AUTHENTIC,
};

static int policy_psy_get_property(struct power_supply *psy,
				   enum power_supply_property psp,
				   union power_supply_propval *val)
{
	struct charger_policy *policy = power_supply_get_drvdata(psy);

	if (!policy) {
		pr_info("policy: %s(): policy_info is null!!!\n", "policy_psy_get_property");
		return -ENODATA;
	}

	switch (psp) {
	case POWER_SUPPLY_PROP_ONLINE:
		val->intval = policy->status;
		break;
	case POWER_SUPPLY_PROP_AUTHENTIC:
		if (policy->demo_sts && charger_policy_check_usb_present(policy)) {
			val->intval = 1;
		} else if (policy->expired_sts && policy->running_discharging) {
			val->intval = 1;
		} else {
			val->intval = 0;
		}
		break;
	case POWER_SUPPLY_PROP_PRESENT:
		pr_info("policy: %s(): get policy enable %d\n", "policy_psy_get_property", !policy->policy_disabled);
		val->intval = (policy->policy_disabled == 0);
		break;
	default:
		return -EINVAL;
	}

	return 0;
}

static int policy_psy_set_property(struct power_supply *psy,
				   enum power_supply_property psp,
				   const union power_supply_propval *val)
{
	struct charger_policy *policy = power_supply_get_drvdata(psy);

	if (!policy) {
		pr_info("policy: %s(): policy_info is null!!!\n", "policy_psy_set_property");
		return -ENODATA;
	}

	switch (psp) {
	case POWER_SUPPLY_PROP_ONLINE:
		policy->status = val->intval;
		break;
	case POWER_SUPPLY_PROP_PRESENT:
		pr_info("policy: %s(): Set policy enable %d\n", "policy_psy_set_property", val->intval);
		policy->policy_disabled = (val->intval == 0);
		break;
	default:
		return -EINVAL;
	}

	queue_delayed_work(policy->timeout_wq, &policy->timeout_work, msecs_to_jiffies(25));
	return 0;
}

static int policy_property_is_writeable(struct power_supply *psy,
					enum power_supply_property psp)
{
	return (psp >= POWER_SUPPLY_PROP_PRESENT && psp <= POWER_SUPPLY_PROP_AUTHENTIC);
}

static void policy_external_power_changed(struct power_supply *psy)
{
	/* Unused, dummy implementation matching binary symbol */
}

static const struct power_supply_desc policy_psy_desc = {
	.name = "policy",
	.type = POWER_SUPPLY_TYPE_UNKNOWN,
	.properties = policy_psy_properties,
	.num_properties = ARRAY_SIZE(policy_psy_properties),
	.get_property = policy_psy_get_property,
	.set_property = policy_psy_set_property,
	.property_is_writeable = policy_property_is_writeable,
	.external_power_changed = policy_external_power_changed,
};

/* Externally exposed API for checking active policy status */
bool charger_policy_get_status(void)
{
	struct power_supply *psy;
	union power_supply_propval pval;
	int ret;

	psy = power_supply_get_by_name("policy");
	if (!psy) {
		pr_info("policy: %s(): get policy power supply failed\n", "charger_policy_get_status");
		return false;
	}

	ret = power_supply_get_property(psy, POWER_SUPPLY_PROP_AUTHENTIC, &pval);
	if (ret < 0) {
		pr_info("policy: %s(): get property %u failed from %s\n", "charger_policy_get_status", POWER_SUPPLY_PROP_AUTHENTIC, "policy");
		power_supply_put(psy);
		return false;
	}

	power_supply_put(psy);
	return pval.intval != 0;
}

/* Delayed Probe work */
static void charger_policy_probe_work(struct work_struct *work)
{
	struct charger_policy *policy = container_of(work, struct charger_policy, probe_work.work);
	struct power_supply_config psy_cfg = {};
	int ret;

	pr_info("policy: [ANTIGRAVITY_VERIFY] custom zte_charger_policy driver probe_work running!\n");
	pr_info("policy: %s(): begin execution\n", "charger_policy_probe_work");

	policy->raw_field_472 = 0;
	policy->status = 0;
	policy->last_status = 0;
	policy->demo_sts = 0;
	policy->timeout_seconds_runtime = policy->timeout_seconds;
	policy->force_discharging_sec = 2592000;
	policy->expired_sts = (policy->expired_mode != 0);
	policy->force_discharging_sec_nanoseconds = 30000;
	policy->force_discharging_start_time = 0;
	policy->running_discharging = 0;
	policy->force_discharging_enable = (policy->have_power_path != 0);
	policy->low_temp_status = (policy->low_temp != 0);

	alarm_init(&policy->timeout_alarm, ALARM_BOOTTIME, charger_policy_timeout_alarm_cb);

	policy->timeout_wq = alloc_workqueue("charger-policy-service", WQ_UNBOUND | WQ_FREEZABLE | WQ_MEM_RECLAIM, 1);
	if (!policy->timeout_wq) {
		pr_info("policy: %s(): timeout workqueue allocation failed\n", "charger_policy_probe_work");
		goto check_retry;
	}

	INIT_DELAYED_WORK(&policy->timeout_work, charger_policy_timeout_handler_work);

	policy->nb.notifier_call = charger_policy_notifier_switch;
	ret = power_supply_reg_notifier(&policy->nb);
	if (ret < 0) {
		pr_info("policy: %s(): Couldn't register psy notifier rc = %d\n", "charger_policy_probe_work", ret);
		goto destroy_wq;
	}

	psy_cfg.drv_data = policy;
	policy->policy_psy = devm_power_supply_register(policy->dev, &policy_psy_desc, &psy_cfg);
	if (IS_ERR(policy->policy_psy)) {
		pr_info("policy: %s(): failed to register policy_psy rc = %ld\n", "charger_policy_probe_work", PTR_ERR(policy->policy_psy));
		goto unreg_notifier;
	}

	/* Register node ops callbacks into zte_misc node manager */
	zte_misc_register_callback(&demo_charging_policy_node, policy);
	zte_misc_register_callback(&expired_charging_policy_node, policy);
	zte_misc_register_callback(&charging_time_sec_node, policy);
	zte_misc_register_callback(&force_disching_sec_node, policy);
	zte_misc_register_callback(&policy_cap_min_node, policy);
	zte_misc_register_callback(&policy_cap_max_node, policy);
	zte_misc_register_callback(&policy_enable_node, policy);

	policy->ws = wakeup_source_register(policy->dev, "charger_policy_service");
	if (policy->ws) {
		queue_delayed_work(policy->timeout_wq, &policy->timeout_work, msecs_to_jiffies(25));
		pr_info("policy: %s(): probe successfully completed\n", "charger_policy_probe_work");
		return;
	}

	pr_info("policy: %s(): charger_policy_service wakelock register failed\n", "charger_policy_probe_work");

unreg_notifier:
	power_supply_unreg_notifier(&policy->nb);
destroy_wq:
	;
check_retry:
	charger_policy_check_retry_probe_count++;
	if (charger_policy_check_retry_probe_count >= policy->retry_times) {
		pr_info("policy: %s(): Charge Arbitrate Driver Init Failed!!!\n", "charger_policy_probe_work");
		devm_kfree(policy->dev, policy);
		return;
	}

	pr_info("policy: %s(): charger policy driver retry[%d]!!!\n", "charger_policy_probe_work", charger_policy_check_retry_probe_count);
	queue_delayed_work(policy->probe_wq, &policy->probe_work, msecs_to_jiffies(1250));
}

/* Probe driver initialization */
static int charger_policy_probe(struct platform_device *pdev)
{
	struct device *dev = &pdev->dev;
	struct device_node *np = dev->of_node;
	struct charger_policy *policy;
	int ret;

	pr_info("policy: [ANTIGRAVITY_VERIFY] custom zte_charger_policy driver probe begin!\n");
	pr_info("policy: %s(): charge policy driver probe begin\n", "charger_policy_probe");

	if (zte_poweroff_charging_status()) {
		pr_info("policy: %s(): charge policy driver probe exit, in charging mode\n", "charger_policy_probe");
		return 0;
	}

	policy = devm_kzalloc(dev, sizeof(*policy), GFP_KERNEL);
	if (!policy)
		return -ENOMEM;

	policy->dev = dev;
	platform_set_drvdata(pdev, policy);

	/* Parse Device Tree (DTS) properties */
	ret = of_property_read_u32(np, "policy,enable", &policy->policy_enable);
	if (ret < 0) {
		policy->policy_enable = 0;
	}
	pr_info("policy: %s(): config: \"enable\" property: [%u]\n", "charger_policy_probe", policy->policy_enable);

	ret = of_property_read_u32(np, "policy,retry-times", &policy->retry_times);
	if (ret < 0) {
		policy->retry_times = 10;
	}
	pr_info("policy: %s(): config: \"retry-times\" property: [%u]\n", "charger_policy_probe", policy->retry_times);

	ret = of_property_read_u32(np, "policy,expired-mode-enable", &policy->expired_mode);
	if (ret < 0) {
		policy->expired_mode = 1;
	}
	pr_info("policy: %s(): config: \"expired-mode-enable\" property: [%u]\n", "charger_policy_probe", policy->expired_mode);

	ret = of_property_read_u32(np, "policy,low-temp-enable", &policy->low_temp);
	if (ret < 0) {
		policy->low_temp = 0;
	}
	pr_info("policy: %s(): config: \"low-temp-enable\" property: [%u]\n", "charger_policy_probe", policy->low_temp);

	ret = of_property_read_u32(np, "policy,have-power-path", &policy->have_power_path);
	if (ret < 0) {
		policy->have_power_path = 1;
	}
	pr_info("policy: %s(): config: \"have-power-path\" property: [%u]\n", "charger_policy_probe", policy->have_power_path);

	ret = of_property_read_u32(np, "policy,timeout-seconds", &policy->timeout_seconds);
	if (ret < 0) {
		policy->timeout_seconds = 86400;
	}
	pr_info("policy: %s(): config: \"timeout-seconds\" property: [%u]\n", "charger_policy_probe", policy->timeout_seconds);

	ret = of_property_read_u32(np, "policy,expired-max-capacity", &policy->expired_max_cap);
	if (ret < 0) {
		policy->expired_max_cap = 70;
	}
	pr_info("policy: %s(): config: \"expired-max-capacity\" property: [%u]\n", "charger_policy_probe", policy->expired_max_cap);

	ret = of_property_read_u32(np, "policy,expired-min-capacity", &policy->expired_min_cap);
	if (ret < 0) {
		policy->expired_min_cap = 50;
	}
	pr_info("policy: %s(): config: \"expired-min-capacity\" property: [%u]\n", "charger_policy_probe", policy->expired_min_cap);

	ret = of_property_read_u32(np, "policy,demo-max-capacity", &policy->demo_max_cap);
	if (ret < 0) {
		policy->demo_max_cap = 70;
	}
	pr_info("policy: %s(): config: \"demo-max-capacity\" property: [%u]\n", "charger_policy_probe", policy->demo_max_cap);

	ret = of_property_read_u32(np, "policy,demo-min-capacity", &policy->demo_min_cap);
	if (ret < 0) {
		policy->demo_min_cap = 50;
	}
	pr_info("policy: %s(): config: \"demo-min-capacity\" property: [%u]\n", "charger_policy_probe", policy->demo_min_cap);

	ret = of_property_read_u32(np, "policy,no-powerpath-delta-capacity", &policy->no_powerpath_delta);
	if (ret < 0) {
		policy->no_powerpath_delta = 10;
	}
	pr_info("policy: %s(): config: \"no-powerpath-delta-capacity\" property: [%u]\n", "charger_policy_probe", policy->no_powerpath_delta);

	ret = of_property_read_string(np, "policy,battery-phy-name", &policy->battery_phy_name);
	if (ret < 0) {
		policy->battery_phy_name = "battery";
	}
	pr_info("policy: %s(): config: \"battery-phy-name\" property: [%s]\n", "charger_policy_probe", policy->battery_phy_name);

	ret = of_property_read_string(np, "policy,zte-battery-phy-name", &policy->zte_battery_phy_name);
	if (ret < 0) {
		policy->zte_battery_phy_name = "zte_battery";
	}
	pr_info("policy: %s(): config: \"zte-battery-phy-name\" property: [%s]\n", "charger_policy_probe", policy->zte_battery_phy_name);

	ret = of_property_read_string(np, "policy,zte-usb-phy-name", &policy->zte_usb_phy_name);
	if (ret < 0) {
		policy->zte_usb_phy_name = "zte_usb";
	}
	pr_info("policy: %s(): config: \"zte-usb-phy-name\" property: [%s]\n", "charger_policy_probe", policy->zte_usb_phy_name);

	ret = of_property_read_string(np, "policy,interface-phy-name", &policy->interface_phy_name);
	if (ret < 0) {
		policy->interface_phy_name = "interface";
	}
	pr_info("policy: %s(): config: \"interface-phy-name\" property: [%s]\n", "charger_policy_probe", policy->interface_phy_name);

	ret = of_property_read_string(np, "policy,cas-phy-name", &policy->cas_phy_name);
	if (ret < 0) {
		policy->cas_phy_name = "cas";
	}
	pr_info("policy: %s(): config: \"cas-phy-name\" property: [%s]\n", "charger_policy_probe", policy->cas_phy_name);

	if (policy->policy_enable) {
		policy->probe_wq = alloc_workqueue("policy_probe_wq", WQ_UNBOUND | WQ_FREEZABLE | WQ_MEM_RECLAIM, 1);
		if (!policy->probe_wq)
			return -ENOMEM;

		INIT_DELAYED_WORK(&policy->probe_work, charger_policy_probe_work);
		queue_delayed_work(policy->probe_wq, &policy->probe_work, msecs_to_jiffies(1250));
		return 0;
	}

	pr_info("policy: %s(): charge policy is disabled, please config policy,enable\n", "charger_policy_probe");
	devm_kfree(dev, policy);
	return 0;
}

/* Remove platform driver instance */
static void charger_policy_remove(struct platform_device *pdev)
{
	struct charger_policy *policy = platform_get_drvdata(pdev);

	pr_info("policy: %s(): removing driver instance\n", "charger_policy_remove");

	if (policy) {
		power_supply_unreg_notifier(&policy->nb);
		if (policy->ws) {
			wakeup_source_unregister(policy->ws);
		}
		/* Workqueues are left allocated to match official binary imports */
		devm_kfree(&pdev->dev, policy);
	}

	pr_info("policy: %s(): driver successfully removed\n", "charger_policy_remove");
}

static const struct of_device_id charger_policy_match_table[] = {
	{ .compatible = "zte,charger-policy-service", },
	{ },
};
MODULE_DEVICE_TABLE(of, charger_policy_match_table);

static struct platform_driver charger_policy_driver = {
	.probe = charger_policy_probe,
	.remove = charger_policy_remove,
	.driver = {
		.name = "zte_charger_policy",
		.of_match_table = charger_policy_match_table,
	},
};

module_platform_driver(charger_policy_driver);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Antigravity Senior Quality & Systems Engineer");
MODULE_DESCRIPTION("Nubia/ZTE Charger Policy Driver Reconstruction");
