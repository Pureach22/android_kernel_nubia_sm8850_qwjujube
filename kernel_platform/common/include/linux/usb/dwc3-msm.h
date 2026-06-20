/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2026 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _LINUX_USB_DWC3_MSM_H
#define _LINUX_USB_DWC3_MSM_H

#include <linux/types.h>
#include <linux/device.h>

int dwc3_msm_set_dp_mode(struct device *dev, bool connected, int lanes);

#endif /* _LINUX_USB_DWC3_MSM_H */
