/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2026, Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef __UAPI_MSM_SYNX_H__
#define __UAPI_MSM_SYNX_H__

#include <linux/types.h>
#include <linux/ioctl.h>

#define SYNX_MAX_NAME_LEN 64

struct synx_ioctl_ops {
	u32 op_id;
	u32 size;
	u32 reserved;
	u32 padding;
	u64 user_payload;
};

#define SYNX_IOC_MAGIC 'S'
#define SYNX_IOC_COMMON _IOWR(SYNX_IOC_MAGIC, 0x82, struct synx_ioctl_ops)

#endif /* __UAPI_MSM_SYNX_H__ */
