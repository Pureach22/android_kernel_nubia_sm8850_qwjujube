/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2018-2021, The Linux Foundation. All rights reserved.
 */

#ifndef _SOC_QCOM_DCVS_H_
#define _SOC_QCOM_DCVS_H_

#include <linux/types.h>

/* DCVS Hardware Types */
#define DCVS_L3 1

/* DCVS Update Paths */
#define DCVS_SLOW_PATH 0
#define DCVS_FAST_PATH 1

struct dcvs_freq {
	u32 freq;
	u32 ib;
	u32 hw_type;
};

struct dcvs_voter;

/* SM8750 DCVS Voter interfaces */
int qcom_dcvs_register_voter(const char *name, u32 hw_type, u32 path);
void qcom_dcvs_unregister_voter(const char *name, u32 hw_type, u32 path);
int qcom_dcvs_update_voter(struct dcvs_voter *voter, struct dcvs_freq *freq);
int qcom_dcvs_update_votes(const char *name, struct dcvs_freq *freq, u32 count, u32 path);
int qcom_dcvs_hw_minmax_get(u32 hw_type, u32 *min, u32 *max);

#endif /* _SOC_QCOM_DCVS_H_ */
