#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/device.h>
#include <linux/power_supply.h>
#include <linux/alarmtimer.h>
#include <linux/workqueue.h>
#include <linux/pm_wakeup.h>

struct charger_policy {
	union {
		struct {
			struct device *dev;
			struct power_supply *policy_psy;
			struct notifier_block nb;
		};
		u8 pad1[40];
	};
	union {
		struct alarm timeout_alarm;
		u8 pad2[120];
	};
	struct workqueue_struct *timeout_wq;
	union {
		struct delayed_work timeout_work;
		u8 pad3[104];
	};
	struct workqueue_struct *probe_wq;
	union {
		struct delayed_work probe_work;
		u8 pad4[104];
	};
	/* We only need the fields up to probe_work for cleanup */
	u32 policy_enable;
	u32 expired_mode;
	u32 low_temp;
	u32 have_power_path;
	u32 retry_times;
	u32 timeout_seconds;
	u32 expired_max_cap;
	u32 expired_min_cap;
	u32 demo_max_cap;
	u32 demo_min_cap;
	u32 no_powerpath_delta;
	u32 pad5;
	const char *interface_phy_name;
	const char *battery_phy_name;
	const char *zte_battery_phy_name;
	const char *zte_usb_phy_name;
	const char *cas_phy_name;
	u32 raw_field_472;
	u32 pad6;
	struct wakeup_source *ws;
};

struct zte_node_ops {
	const char *name;
	int (*set)(const char *buf, void *priv);
	int (*get)(char *buf, void *priv);
	int (*show)(char *buf, void *priv);
	void *priv;
};

/* Module parameters for symbol addresses */
static unsigned long node_ops_list_addr = 0;
module_param(node_ops_list_addr, ulong, 0444);

/* Direct kernel exports declared extern if not in headers */
extern struct bus_type platform_bus_type;

static int match_device_name(struct device *dev, const void *data)
{
	return strcmp(dev_name(dev), data) == 0;
}

static int __init zte_cleanup_init(void)
{
	struct device *dev;
	struct charger_policy *policy;
	struct zte_node_ops *list;
	int i;

	pr_info("zte_cleanup: starting cleanup execution\n");

	/* 1. Find the platform device using direct kernel calls */
	dev = bus_find_device(&platform_bus_type, NULL, "soc:charger_policy_service", match_device_name);
	if (!dev) {
		pr_info("zte_cleanup: platform device soc:charger_policy_service not found\n");
	} else {
		pr_info("zte_cleanup: found platform device soc:charger_policy_service\n");
		policy = dev_get_drvdata(dev);
		if (!policy) {
			pr_info("zte_cleanup: driver data (policy) is NULL\n");
		} else {
			pr_info("zte_cleanup: cleaning up policy structure...\n");

			/* Cancel alarm timer */
			alarm_try_to_cancel(&policy->timeout_alarm);
			pr_info("zte_cleanup: cancelled timeout_alarm\n");

			/* Cancel delayed works */
			cancel_delayed_work_sync(&policy->probe_work);
			cancel_delayed_work_sync(&policy->timeout_work);
			pr_info("zte_cleanup: cancelled delayed works\n");

			/* Destroy workqueues */
			if (policy->probe_wq) {
				destroy_workqueue(policy->probe_wq);
				pr_info("zte_cleanup: destroyed probe_wq\n");
			}
			if (policy->timeout_wq) {
				destroy_workqueue(policy->timeout_wq);
				pr_info("zte_cleanup: destroyed timeout_wq\n");
			}

			/* Unregister notifier */
			power_supply_unreg_notifier(&policy->nb);
			pr_info("zte_cleanup: unregistered notifier\n");

			/* Unregister wakeup source */
			if (policy->ws) {
				wakeup_source_unregister(policy->ws);
				pr_info("zte_cleanup: unregistered wakeup source\n");
			}

			/* Clear driver data */
			dev_set_drvdata(dev, NULL);
			pr_info("zte_cleanup: cleared driver data\n");
		}
		put_device(dev);
	}

	/* 2. Clear callbacks in zte_misc */
	if (node_ops_list_addr != 0) {
		list = (struct zte_node_ops *)node_ops_list_addr;
		pr_info("zte_cleanup: clearing zte_misc callbacks at %px\n", list);
		for (i = 0; i < 36; i++) {
			if (!list[i].name)
				continue;
			if (strcmp(list[i].name, "demo_charging_policy") == 0 ||
			    strcmp(list[i].name, "expired_charging_policy") == 0 ||
			    strcmp(list[i].name, "charging_time_sec") == 0 ||
			    strcmp(list[i].name, "force_disching_sec") == 0 ||
			    strcmp(list[i].name, "policy_cap_min") == 0 ||
			    strcmp(list[i].name, "policy_cap_max") == 0 ||
			    strcmp(list[i].name, "policy_enable") == 0) {
				list[i].set = NULL;
				list[i].get = NULL;
				list[i].show = NULL;
				list[i].priv = NULL;
				pr_info("zte_cleanup: cleared callbacks for %s\n", list[i].name);
			}
		}
	} else {
		pr_info("zte_cleanup: node_ops_list_addr parameter not provided, skipping callbacks cleanup\n");
	}

	pr_info("zte_cleanup: cleanup completed successfully\n");

	/* Return -ENODEV so the module doesn't stay loaded */
	return -ENODEV;
}

static void __exit zte_cleanup_exit(void)
{
}

module_init(zte_cleanup_init);
module_exit(zte_cleanup_exit);

MODULE_LICENSE("GPL v2");
MODULE_AUTHOR("Antigravity Senior Quality & Systems Engineer");
MODULE_DESCRIPTION("Nubia/ZTE Charger Policy Driver Safe Unloader");
