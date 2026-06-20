/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2026 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _SOC_QCOM_CRM_H
#define _SOC_QCOM_CRM_H

#include <linux/types.h>
#include <linux/clk.h>

#define CRM_HW_DRV          0
#define CRM_SW_DRV          1

#define CRM_PWR_STATE0      0
#define CRM_PWR_STATE1      1

#define CRM_ACTIVE_STATE    1

struct crm_dev;

struct crm_cmd {
	u32 data;
	u32 resource_idx;
	bool wait;
	struct {
		u32 sw;
	} pwr_state;
};

/* API Prototypes */
struct crm_dev *crm_get_device(const char *name);
int crm_write_pwr_states(const struct crm_dev *crm_dev, u32 client_idx);
int crm_write_perf_ol(const struct crm_dev *crm_dev, u32 drv_type, u32 client_idx, struct crm_cmd *cmd);
int qcom_clk_crmb_set_rate(struct clk *clk, u32 drv_type, u32 client_idx, u32 res_idx, u32 pwr_state, u64 rate_ab, u64 rate_ib);

#endif /* _SOC_QCOM_CRM_H */
