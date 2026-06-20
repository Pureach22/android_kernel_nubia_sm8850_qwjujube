/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2026, Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef __SYNX_API_H__
#define __SYNX_API_H__

#include <linux/types.h>
#include <linux/dma-fence.h>

struct synx_queue_desc {
	u64 dev_addr;
	u32 size;
	void *vaddr;
};

struct synx_session {
	void *client;
	union {
		int type;
		u32 client_id;
	};
	u32 padding;
	void *ops;
	char name[64];
	struct synx_queue_desc queue;
	bool active;
};

#define SYNX_MAX_SIGNAL_PER_CLIENT 64
#define SYNX_HW_FENCE_CLIENT_START 1024
#define SYNX_HW_FENCE_CLIENT_END 4096

enum synx_client_id {
	SYNX_CLIENT_NATIVE = 0,
	SYNX_CLIENT_ICP_CTX0 = 1,
	SYNX_CLIENT_ICP1_CTX0 = 2,
	SYNX_CLIENT_HW_FENCE_GFX_CTX0 = SYNX_HW_FENCE_CLIENT_START,
	SYNX_CLIENT_HW_FENCE_DPU0_CTL0 = SYNX_CLIENT_HW_FENCE_GFX_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_IPE_CTX0 = SYNX_CLIENT_HW_FENCE_DPU0_CTL0 + 64,
	SYNX_CLIENT_HW_FENCE_VID_CTX0 = SYNX_CLIENT_HW_FENCE_IPE_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_TEST_CTX0 = SYNX_CLIENT_HW_FENCE_VID_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_LSR0_CTX0 = SYNX_CLIENT_HW_FENCE_TEST_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_DCP0_CTX0 = SYNX_CLIENT_HW_FENCE_LSR0_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_GFX1_CTX0 = SYNX_CLIENT_HW_FENCE_DCP0_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_DPU1_CTL0 = SYNX_CLIENT_HW_FENCE_GFX1_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_TEST1_CTX0 = SYNX_CLIENT_HW_FENCE_DPU1_CTL0 + 64,
	SYNX_CLIENT_HW_FENCE_TEST2_CTX0 = SYNX_CLIENT_HW_FENCE_TEST1_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_TEST3_CTX0 = SYNX_CLIENT_HW_FENCE_TEST2_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_TEST4_CTX0 = SYNX_CLIENT_HW_FENCE_TEST3_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_IPA_CTX0 = SYNX_CLIENT_HW_FENCE_TEST4_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_IFE0_CTX0 = SYNX_CLIENT_HW_FENCE_IPA_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_IFE1_CTX0 = SYNX_CLIENT_HW_FENCE_IFE0_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_IFE2_CTX0 = SYNX_CLIENT_HW_FENCE_IFE1_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_IFE3_CTX0 = SYNX_CLIENT_HW_FENCE_IFE2_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_IFE4_CTX0 = SYNX_CLIENT_HW_FENCE_IFE3_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_IFE5_CTX0 = SYNX_CLIENT_HW_FENCE_IFE4_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_IFE6_CTX0 = SYNX_CLIENT_HW_FENCE_IFE5_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_IFE7_CTX0 = SYNX_CLIENT_HW_FENCE_IFE6_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_IFE8_CTX0 = SYNX_CLIENT_HW_FENCE_IFE7_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_IFE9_CTX0 = SYNX_CLIENT_HW_FENCE_IFE8_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_IFE10_CTX0 = SYNX_CLIENT_HW_FENCE_IFE9_CTX0 + 64,
	SYNX_CLIENT_HW_FENCE_IFE11_CTX0 = SYNX_CLIENT_HW_FENCE_IFE10_CTX0 + 64,
	SYNX_CLIENT_MAX = 4096
};

enum synx_resource_type {
	SYNX_RESOURCE_SOCCP = 0,
	SYNX_RESOURCE_MAX
};
#define synx_resource_id synx_resource_type

struct synx_initialization_params {
	const char *name;
	struct synx_queue_desc *ptr;
	u32 flags;
	enum synx_client_id id;
};

#define SYNX_CREATE_GLOBAL_FENCE 0x1
#define SYNX_CREATE_DMA_FENCE    0x2
#define SYNX_CREATE_CSL_FENCE    0x4
#define SYNX_CREATE_MAX_FLAGS    0x7

struct synx_create_params {
	const char *name;
	u32 flags;
	u32 *h_synx;
	struct dma_fence *fence;
};

#define SYNX_IMPORT_GLOBAL_FENCE 0x1
#define SYNX_IMPORT_DMA_FENCE    0x2
#define SYNX_IMPORT_SYNX_FENCE   0x4

struct synx_import_indv_params {
	u32 flags;
	void *fence;
	u32 *new_h_synx;
};

#define SYNX_IMPORT_INDV_PARAMS 1
#define SYNX_IMPORT_ARR_PARAMS  2

struct synx_import_arr_params {
	struct synx_import_indv_params *list;
	u32 num_fences;
};

struct synx_import_params {
	u32 type;
	union {
		struct synx_import_indv_params indv;
		struct synx_import_arr_params arr;
	};
};

struct synx_signal_indv_params {
	u32 h_synx;
	u32 status;
	u32 *signal_idx;
	u64 client_data;
	u32 flags;
};

#define SYNX_SIGNAL_INDV_PARAMS 1
#define SYNX_SIGNAL_ARR_PARAMS  2

struct synx_signal_arr_params {
	struct synx_signal_indv_params *list;
	u32 num_fences;
};

struct synx_signal_n_params {
	u32 type;
	union {
		struct synx_signal_indv_params indv;
		struct synx_signal_arr_params arr;
	};
};

struct synx_release_indv_params {
	u32 h_synx;
	int result;
};

#define SYNX_RELEASE_INDV_PARAMS 1
#define SYNX_RELEASE_ARR_PARAMS  2

struct synx_release_arr_params {
	struct synx_release_indv_params *list;
	u32 num_objs;
};

struct synx_release_n_params {
	u32 type;
	union {
		struct synx_release_indv_params indv;
		struct synx_release_arr_params arr;
	};
};

#define SYNX_SIGNAL_DELAYED   0x1
#define SYNX_SIGNAL_IMMEDIATE 0x2

#define SYNX_SUCCESS 0

typedef void (*synx_callback_fn)(u32 h_synx, int status, void *userdata);

struct synx_callback_params {
	u32 h_synx;
	synx_callback_fn cb_func;
	void *userdata;
	u32 timeout_ms;
	void *cancel_cb_func;
};

#define SYNX_NO_TIMEOUT 0xFFFFFFFF

/* State flags */
#define SYNX_HW_FENCE_FLAG_ENABLED_BIT 0
#define SYNX_HW_FENCE_FLAG_SIGNALED_BIT 1
#define SYNX_NATIVE_FENCE_FLAG_ENABLED_BIT 2

#define SYNX_INIT_MAX 1

enum synx_signal_status {
	SYNX_STATE_INVALID = 0,
	SYNX_STATE_ACTIVE,
	SYNX_STATE_SIGNALED_SUCCESS,
	SYNX_STATE_SIGNALED_CANCEL,
	SYNX_STATE_SIGNALED_ERROR,
	SYNX_STATE_SIGNALED_SSR,
	SYNX_STATE_SIGNALED_EXTERNAL,
	SYNX_STATE_SIGNALED_MAX
};

/* Functions exported by Synx */
struct synx_session *synx_initialize(struct synx_initialization_params *params);
int synx_uninitialize(struct synx_session *session);
int synx_create(struct synx_session *session, struct synx_create_params *params);
int synx_release(struct synx_session *session, u32 h_synx);
int synx_release_n(struct synx_session *session, u32 *h_synx, u32 count);
int synx_signal(struct synx_session *session, u32 h_synx, u32 status);
int synx_signal_n(struct synx_session *session, struct synx_signal_n_params *params);
int synx_import(struct synx_session *session, struct synx_import_params *params);
int synx_async_wait(struct synx_session *session, struct synx_callback_params *params);
int synx_cancel_async_wait(struct synx_session *session, struct synx_callback_params *params);
int synx_merge(struct synx_session *session, u32 *h_synx, u32 count, u32 *h_merged);
int synx_wait(struct synx_session *session, u32 h_synx, u32 timeout_ms);
int synx_get_status(struct synx_session *session, u32 h_synx, u32 *status);
void *synx_get_fence(struct synx_session *session, u32 h_synx);
int synx_recover(enum synx_client_id id);
int synx_enable_resources(enum synx_client_id id, enum synx_resource_id res, bool pwr_on);

struct synx_ops {
	int (*uninitialize)(struct synx_session *session);
	int (*create)(struct synx_session *session, struct synx_create_params *params);
	int (*release)(struct synx_session *session, u32 h_synx);
	int (*release_n)(struct synx_session *session, struct synx_release_n_params *params);
	int (*signal)(struct synx_session *session, u32 h_synx, enum synx_signal_status status);
	int (*signal_n)(struct synx_session *session, struct synx_signal_n_params *params);
	int (*import)(struct synx_session *session, struct synx_import_params *params);
	void *(*get_fence)(struct synx_session *session, u32 h_synx);
	int (*get_status)(struct synx_session *session, u32 h_synx);
	int (*wait)(struct synx_session *session, u32 h_synx, u64 timeout_ms);
};

int synx_hwfence_init_ops(struct synx_ops *hwfence_ops);

#endif /* __SYNX_API_H__ */
