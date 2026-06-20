/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2017-2021, The Linux Foundation. All rights reserved.
 */

#ifndef _LINUX_MSM_SYSSTATS_H_
#define _LINUX_MSM_SYSSTATS_H_

#include <linux/types.h>

struct msm_sysstats_pmu_data {
	u32 type;
	u32 config;
	u64 count;
};

/* KGSL Callback registration with correct SM8750 signature */
void sysstats_register_kgsl_stats_cb(u64 (*cb)(pid_t pid));
void sysstats_unregister_kgsl_stats_cb(void);

void msm_sysstats_event(u32 type, u32 config, u64 count);

#endif /* _LINUX_MSM_SYSSTATS_H_ */
