/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2014-2021, The Linux Foundation. All rights reserved.
 * Copyright (c) 2022-2023 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _SOC_QCOM_OF_COMMON_H_
#define _SOC_QCOM_OF_COMMON_H_

#include <linux/types.h>
#include <linux/of.h>

/* of_get_available_child_count is already in linux/of.h for GKI 6.12+ */

int of_fdt_get_ddrtype(void);

#endif /* _SOC_QCOM_OF_COMMON_H_ */

