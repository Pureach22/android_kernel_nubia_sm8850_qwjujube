/* SPDX-License-Identifier: GPL-2.0-only */
/*
 * Copyright (c) 2026 Qualcomm Innovation Center, Inc. All rights reserved.
 */

#ifndef _LINUX_SOC_QCOM_ALTMODE_GLINK_H
#define _LINUX_SOC_QCOM_ALTMODE_GLINK_H

#include <linux/types.h>
#include <linux/device.h>

#define USB_SID_DISPLAYPORT 0xff01

enum altmode_pan_ack_msg_cmd {
	ALTMODE_PAN_ACK = 0x11,
};

struct altmode_pan_ack_msg {
	u32 cmd_type;
	u8 port_index;
};

struct altmode_client;

struct altmode_client_data {
	u16 svid;
	const char *name;
	void *priv;
	int (*callback)(void *priv, void *data, size_t len);
};

struct altmode_client *altmode_register_client(struct device *dev,
		const struct altmode_client_data *client_data);

void altmode_deregister_client(struct altmode_client *client);

int altmode_register_notifier(struct device *dev,
		void (*callback)(void *priv), void *priv);

void altmode_deregister_notifier(struct device *dev, void *priv);

int altmode_send_data(struct altmode_client *client, void *data, size_t len);

#endif /* _LINUX_SOC_QCOM_ALTMODE_GLINK_H */
