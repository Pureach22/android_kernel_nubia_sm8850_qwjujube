/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2026, Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef __SYNX_INTEROP_H__
#define __SYNX_INTEROP_H__

#include <synx_api.h>

#define SYNX_SUCCESS 0
#define SYNX_NOMEM 12
#define SYNX_NOPERM 1
#define SYNX_TIMEOUT 110
#define SYNX_ALREADY 114
#define SYNX_NOENT 2
#define SYNX_INVALID 22
#define SYNX_BUSY 16
#define SYNX_EAGAIN 11

enum synx_core_id {
	SYNX_CORE_SOCCP = 0,
	SYNX_CORE_MAX
};

struct synx_hwfence_interops {
	int (*share_handle_status)(struct synx_import_indv_params *params, u64 handle, u32 *signal_status);
	void *(*get_fence)(u32 h_synx);
	int (*notify_recover)(enum synx_core_id id);
	int (*signal_fence)(enum synx_core_id id, bool is_ssr, u32 h_synx, u32 status);
	int (*dma_add_cb_no_enable_sig)(struct dma_fence *fence, struct dma_fence_cb *cb, dma_fence_func_t func);
};

int synx_hwfence_init_interops(struct synx_hwfence_interops *synx_ops, struct synx_hwfence_interops *hwfence_ops);

#endif /* __SYNX_INTEROP_H__ */
