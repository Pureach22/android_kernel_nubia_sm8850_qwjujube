/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _LINUX_SOC_QCOM_SPMI_PMIC_ARB_H
#define _LINUX_SOC_QCOM_SPMI_PMIC_ARB_H

#include <linux/types.h>
#include <linux/device.h>
#include <linux/ioport.h>

int spmi_pmic_arb_map_address(struct device *dev, u32 addr, struct resource *res);

#endif /* _LINUX_SOC_QCOM_SPMI_PMIC_ARB_H */
