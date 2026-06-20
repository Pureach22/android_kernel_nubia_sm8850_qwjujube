/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2026, ZTE Corporation. All rights reserved.
 */

#ifndef __LINUX_SOC_QCOM_BATTERY_CHARGER_H__
#define __LINUX_SOC_QCOM_BATTERY_CHARGER_H__

#include <linux/notifier.h>

#define VMAX_CLAMP 0

int register_hboost_event_notifier(struct notifier_block *nb);
int unregister_hboost_event_notifier(struct notifier_block *nb);
int qti_battery_charger_get_prop(const char *psy_name, int prop, int *val);

#endif /* __LINUX_SOC_QCOM_BATTERY_CHARGER_H__ */
