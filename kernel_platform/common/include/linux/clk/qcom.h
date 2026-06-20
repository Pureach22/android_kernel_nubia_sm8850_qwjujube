/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2017-2021, The Linux Foundation. All rights reserved.
 * Copyright (c) 2022-2023 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _LINUX_CLK_QCOM_H_
#define _LINUX_CLK_QCOM_H_

#include <linux/types.h>

struct clk;
struct regulator;

/* Clock flags for power management */
#define QCOM_CLK_OFF            0
#define QCOM_CLK_ON             1
#define QCOM_CLK_SUSPEND        2

#define CLKFLAG_RETAIN_MEM	0x00000040
#define CLKFLAG_NORETAIN_MEM	0x00000080

void qcom_clk_set_flags(struct clk *clk, u32 flags);

/* Diagnostic interfaces for RedMagic firmware parity */
void qcom_clk_dump(struct clk *clk, struct regulator *reg, bool verbose);

#endif /* _LINUX_CLK_QCOM_H_ */
