/* SPDX-License-Identifier: GPL-2.0-only */
#ifndef _LINUX_SOC_QCOM_PANEL_EVENT_NOTIFIER_H
#define _LINUX_SOC_QCOM_PANEL_EVENT_NOTIFIER_H

#include <linux/types.h>

enum panel_event_notifier_tag {
	PANEL_EVENT_NOTIFICATION_PRIMARY,
	PANEL_EVENT_NOTIFICATION_SECONDARY,
};

enum panel_event_notifier_client {
	PANEL_EVENT_NOTIFIER_CLIENT_PRIMARY_TOUCH,
	PANEL_EVENT_NOTIFIER_CLIENT_SECONDARY_TOUCH,
	PANEL_EVENT_NOTIFIER_CLIENT_OTHER,
};

enum {
	DRM_PANEL_EVENT_NONE,
	DRM_PANEL_EVENT_BLANK,
	DRM_PANEL_EVENT_UNBLANK,
	DRM_PANEL_EVENT_BLANK_LP,
	DRM_PANEL_EVENT_FPS_CHANGE,
};

struct panel_event_notification {
	int notif_type;
	void *panel;
	struct {
		int old_fps;
		int new_fps;
		bool early_trigger;
	} notif_data;
};

void panel_event_notification_trigger(enum panel_event_notifier_tag tag,
				      struct panel_event_notification *notif);

void *panel_event_notifier_register(enum panel_event_notifier_tag tag,
				     enum panel_event_notifier_client client_type,
				     void *panel,
				     void (*callback_func)(enum panel_event_notifier_tag tag,
							   struct panel_event_notification *notification,
							   void *client_data),
				     void *client_data);

int panel_event_notifier_unregister(void *cookie);

#endif /* _LINUX_SOC_QCOM_PANEL_EVENT_NOTIFIER_H */
