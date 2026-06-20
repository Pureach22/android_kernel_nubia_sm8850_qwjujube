/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2026 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _MSM_MMRM_H_
#define _MSM_MMRM_H_

#include <linux/types.h>

struct clk;
struct device;

enum mmrm_client_type {
	MMRM_CLIENT_CLOCK,
	MMRM_CLIENT_TYPE_MAX
};

enum mmrm_client_domain {
	MMRM_CLIENT_DOMAIN_CAMERA = 1,
	MMRM_CLIENT_DOMAIN_EVA = 2,
	MMRM_CLIENT_DOMAIN_DISPLAY = 3,
	MMRM_CLIENT_DOMAIN_VIDEO = 4,
	MMRM_CLIENT_DOMAIN_MAX
};

enum mmrm_client_priority {
	MMRM_CLIENT_PRIOR_LOW,
	MMRM_CLIENT_PRIOR_MEDIUM,
	MMRM_CLIENT_PRIOR_HIGH,
	MMRM_CLIENT_PRIOR_MAX
};

struct mmrm_client_desc_info {
	char name[128];
	enum mmrm_client_domain client_domain;
	u32 client_id;
	struct clk *clk;
};

struct mmrm_client_notifier_data;

struct mmrm_client_desc {
	enum mmrm_client_type client_type;
	union {
		struct mmrm_client_desc_info desc;
	} client_info;
	enum mmrm_client_priority priority;
	void *pvt_data;
	int (*notifier_callback_fn)(struct mmrm_client_notifier_data *data);
};

#define MMRM_CRM_HW_DRV 0
#define MMRM_CRM_SW_DRV 1

#define CRM_PWR_STATE0 0
#define CRM_PWR_STATE1 1

struct mmrm_client_data {
	u32 num_hw_blocks;
	u32 crm_drv_idx;
	u32 drv_type;
	u32 pwr_st;
	u32 flags;
};

#define MMRM_CLIENT_DATA_FLAG_RESERVE_ONLY (1U << 0)

struct mmrm_client_res_value {
	u64 min;
	u64 cur;
	u64 new_val;
};

enum mmrm_cb_type {
	MMRM_CLIENT_RESOURCE_VALUE_CHANGE,
	MMRM_CLIENT_CB_TYPE_MAX
};

struct mmrm_client_notifier_data {
	void *pvt_data;
	enum mmrm_cb_type cb_type;
	union {
		struct mmrm_client_res_value val_chng;
	} cb_data;
};

struct mmrm_client;

/* Exported MMRM APIs */
struct mmrm_client *mmrm_client_register(struct mmrm_client_desc *desc);
int mmrm_client_deregister(struct mmrm_client *client);
int mmrm_client_set_value(struct mmrm_client *client, struct mmrm_client_data *data, u64 rate);
int mmrm_client_set_value_in_range(struct mmrm_client *client, struct mmrm_client_data *data, struct mmrm_client_res_value *val);
int mmrm_client_get_value(struct mmrm_client *client, struct mmrm_client_data *data, u64 *rate);
int mmrm_client_get_clk_count(void);
bool mmrm_client_check_scaling_supported(enum mmrm_client_type type, u32 id);

#endif /* _MSM_MMRM_H_ */
