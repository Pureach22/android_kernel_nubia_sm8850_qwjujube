/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2016-2021, The Linux Foundation. All rights reserved.
 */

#ifndef _SOC_QCOM_MSM_PERFORMANCE_H_
#define _SOC_QCOM_MSM_PERFORMANCE_H_

#include <linux/types.h>

/* MSM Performance Client IDs */
#define MSM_PERF_GFX 1

/* MSM Performance Event IDs */
enum msm_perf_event {
	MSM_PERF_RETIRED = 0,
	MSM_PERF_SUBMIT  = 1,
	MSM_PERF_QUEUE   = 2,
};

/* SM8750 Performance interfaces (6 arguments required) */
void msm_perf_events_update(u32 client, u32 event, u32 pid, u32 ctx_id, u32 ts, u32 eof);

#endif /* _SOC_QCOM_MSM_PERFORMANCE_H_ */
