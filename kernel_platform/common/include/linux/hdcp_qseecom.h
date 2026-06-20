/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2015-2023 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef __LINUX_HDCP_QSEECOM_H__
#define __LINUX_HDCP_QSEECOM_H__

#include <linux/types.h>

#define HDCP1_AKSV_SIZE 8

enum hdcp2_app_cmd {
	HDCP2_CMD_START,
	HDCP2_CMD_START_AUTH,
	HDCP2_CMD_STOP,
	HDCP2_CMD_PROCESS_MSG,
	HDCP2_CMD_TIMEOUT,
	HDCP2_CMD_EN_ENCRYPTION,
	HDCP2_CMD_QUERY_STREAM,
};

struct hdcp2_buffer {
	unsigned char *data;
	u32 length;
};

struct hdcp2_app_data {
	struct hdcp2_buffer request;
	struct hdcp2_buffer response;
	u32 timeout;
	bool repeater_flag;
};

struct hdcp1_topology {
	uint32_t depth;
	uint32_t device_count;
	uint32_t max_devices_exceeded;
	uint32_t max_cascade_exceeded;
	uint32_t hdcp2LegacyDeviceDownstream;
	uint32_t hdcp1DeviceDownstream;
};

#ifdef CONFIG_HDCP_QSEECOM
void *hdcp1_init(void);
void hdcp1_deinit(void *data);
bool hdcp1_feature_supported(void *data);
int hdcp1_set_enc(void *data, bool enable);
int hdcp1_ops_notify(void *data, void *topo, bool is_authenticated);
int hdcp1_start(void *data, u32 *aksv_msb, u32 *aksv_lsb);
void hdcp1_stop(void *data);
void hdcp1_set_hdcp_key_verify_retries(void *ctx, u32 max_hdcp_key_verify_retries);

void *hdcp2_init(u32 device_type);
void hdcp2_deinit(void *ctx);
bool hdcp2_feature_supported(void *ctx);
int hdcp2_force_encryption(void *ctx, uint32_t enable);
int hdcp2_app_comm(void *ctx, enum hdcp2_app_cmd cmd, struct hdcp2_app_data *app_data);
int hdcp2_open_stream(void *ctx, uint8_t vc_payload_id, uint8_t stream_number, uint32_t *stream_id);
int hdcp2_close_stream(void *ctx, uint32_t stream_id);
void hdcp2_set_hdcp_key_verify_retries(void *ctx, u32 max_hdcp_key_verify_retries);
#else
static inline void *hdcp1_init(void) { return NULL; }
static inline void hdcp1_deinit(void *data) {}
static inline bool hdcp1_feature_supported(void *data) { return false; }
static inline int hdcp1_set_enc(void *data, bool enable) { return -ENODEV; }
static inline int hdcp1_ops_notify(void *data, void *topo, bool is_authenticated) { return -ENODEV; }
static inline int hdcp1_start(void *data, u32 *aksv_msb, u32 *aksv_lsb) { return -ENODEV; }
static inline void hdcp1_stop(void *data) {}
static inline void hdcp1_set_hdcp_key_verify_retries(void *ctx, u32 max_hdcp_key_verify_retries) {}

static inline void *hdcp2_init(u32 device_type) { return NULL; }
static inline void hdcp2_deinit(void *ctx) {}
static inline bool hdcp2_feature_supported(void *ctx) { return false; }
static inline int hdcp2_force_encryption(void *ctx, uint32_t enable) { return -ENODEV; }
static inline int hdcp2_app_comm(void *ctx, enum hdcp2_app_cmd cmd, struct hdcp2_app_data *app_data) { return -ENODEV; }
static inline int hdcp2_open_stream(void *ctx, uint8_t vc_payload_id, uint8_t stream_number, uint32_t *stream_id) { return -ENODEV; }
static inline int hdcp2_close_stream(void *ctx, uint32_t stream_id) { return -ENODEV; }
static inline void hdcp2_set_hdcp_key_verify_retries(void *ctx, u32 max_hdcp_key_verify_retries) {}
#endif

#endif /* __LINUX_HDCP_QSEECOM_H__ */
