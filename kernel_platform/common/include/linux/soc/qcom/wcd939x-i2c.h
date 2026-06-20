/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2026 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _LINUX_SOC_QCOM_WCD939X_I2C_H
#define _LINUX_SOC_QCOM_WCD939X_I2C_H

#include <linux/types.h>
#include <linux/notifier.h>

struct device_node;

enum wcd_usbss_cable_status {
	WCD_USBSS_CABLE_DISCONNECT = 0,
	WCD_USBSS_CABLE_CONNECT,
};

enum wcd_usbss_cable_types {
	WCD_USBSS_DP_AUX_CC1 = 0,
	WCD_USBSS_DP_AUX_CC2,
};

int wcd_usbss_switch_update(enum wcd_usbss_cable_types event,
			    enum wcd_usbss_cable_status status);

int wcd_usbss_reg_notifier(struct notifier_block *nb,
			   struct device_node *np);

int wcd_usbss_unreg_notifier(struct notifier_block *nb,
			     struct device_node *np);

#endif /* _LINUX_SOC_QCOM_WCD939X_I2C_H */
