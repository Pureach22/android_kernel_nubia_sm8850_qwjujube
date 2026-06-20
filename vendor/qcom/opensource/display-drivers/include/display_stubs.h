#ifndef _DISPLAY_STUBS_H_
#define _DISPLAY_STUBS_H_

#include <linux/types.h>
#include <linux/version.h>
#include <linux/device.h>

struct clk;
struct sde_hdcp_ops;
struct sde_hdcp_init_data;

// SOCINFO
#ifndef PART_DISPLAY
#define PART_DISPLAY 0x3
#endif
extern int socinfo_get_part_info(u32 part);
extern int socinfo_get_part_count(u32 part);
extern void socinfo_get_subpart_info(u32 part, void *info, u32 count);

// CLOCK FLAGS
#ifndef CLKFLAG_RETAIN_MEM
#define CLKFLAG_RETAIN_MEM BIT(0)
#endif
#ifndef CLKFLAG_NORETAIN_MEM
#define CLKFLAG_NORETAIN_MEM BIT(1)
#endif

// DRM PANEL EVENTS
#ifndef DRM_PANEL_EVENT_UNBLANK
enum {
    DRM_PANEL_EVENT_UNBLANK = 1,
    DRM_PANEL_EVENT_BLANK_LP = 2,
    DRM_PANEL_EVENT_BLANK = 3,
    DRM_PANEL_EVENT_FPS_CHANGE = 4,
};
#endif

enum panel_event_notifier_tag {
    PANEL_EVENT_NOTIFICATION_PRIMARY,
    PANEL_EVENT_NOTIFICATION_SECONDARY,
    PANEL_EVENT_NOTIFICATION_MAX
};

struct panel_event_notification {
    u32 event;
    void *data;
    u32 notif_type;
    void *panel;
    struct {
        u32 old_fps;
        u32 new_fps;
        bool early_trigger;
    } notif_data;
};

extern void panel_event_notification_trigger(u32 tag, struct panel_event_notification *n);

// SCM
#ifdef MDP_DEVICE_ID
#undef MDP_DEVICE_ID
#endif
#define MDP_DEVICE_ID 0x1A

extern int qcom_scm_mem_protect_sd_ctrl(u32 device, u64 addr, u64 size, u32 ctrl);

// Gunyah
#ifndef GH_PRIMARY_VM
#define GH_PRIMARY_VM 0
#endif

// HDCP
struct hdcp2_buffer {
    u8 *data;
    u32 length;
};

struct hdcp2_app_data {
    struct hdcp2_buffer response;
    struct hdcp2_buffer request;
    u32 timeout;
    bool repeater_flag;
};

#define HDCP2_CMD_START          1
#define HDCP2_CMD_START_AUTH     2
#define HDCP2_CMD_STOP           3
#define HDCP2_CMD_PROCESS_MSG    4
#define HDCP2_CMD_TIMEOUT        5
#define HDCP2_CMD_EN_ENCRYPTION  6
#define HDCP2_CMD_QUERY_STREAM   7

extern void *hdcp2_init(u32 device_type);
extern void hdcp2_deinit(void *ctx);
extern int hdcp2_app_comm(void *ctx, u32 cmd, struct hdcp2_app_data *data);
extern int hdcp2_open_stream(void *ctx, u8 vc, u8 sid, u32 *handle);
extern void hdcp2_close_stream(void *ctx, u32 handle);
extern bool hdcp2_feature_supported(void *ctx);
extern void hdcp2_force_encryption(void *ctx, int enable);

struct hdcp1_topology {
    u32 depth;
    u32 device_count;
    u32 max_devices_exceeded;
    u32 max_cascade_exceeded;
    u32 hdcp2LegacyDeviceDownstream;
    u32 hdcp1DeviceDownstream;
};

extern void *hdcp1_init(void);
extern void hdcp1_deinit(void *ctx);
extern int hdcp1_start(void *ctx, u32 *aksv_msb, u32 *aksv_lsb);
extern void hdcp1_stop(void *ctx);
extern void hdcp1_set_enc(void *ctx, bool enable);
extern void hdcp1_ops_notify(void *ctx, struct hdcp1_topology *topology, bool success);
extern bool hdcp1_feature_supported(void *ctx);
extern const char *sde_hdcp_version(u32 version);

// DP / HDMI HDCP Stubs
extern void *sde_hdcp_1x_init(struct sde_hdcp_init_data *init_data);
extern void sde_hdcp_1x_deinit(void *fd);
extern struct sde_hdcp_ops *sde_hdcp_1x_get(void *fd);

extern void *sde_dp_hdcp2p2_init(struct sde_hdcp_init_data *init_data);
extern void sde_dp_hdcp2p2_deinit(void *fd);
extern struct sde_hdcp_ops *sde_dp_hdcp2p2_get(void *fd);

// RPMH
extern void rpmh_mode_solver_set(const struct device *dev, bool enable);
extern void rpmh_write_sleep_and_wake(const struct device *dev);

// CRM / CESTA
#define CRM_HW_DRV 0
#define CRM_SW_DRV 1
#define CRM_PWR_STATE0 0
#define CRM_PWR_STATE1 1
#define CRM_ACTIVE_STATE 1

struct crm_cmd {
    u32 data;
    u32 resource_idx;
    bool wait;
    struct {
        u32 sw;
    } pwr_state;
};

extern int qcom_clk_crmb_set_rate(struct clk *clk, u32 drv, u32 client, u32 res, u32 state, u64 ab, u64 ib);
extern int crm_write_pwr_states(const struct device *dev, u32 client);
extern int crm_write_perf_ol(const struct device *dev, u32 drv, u32 client, struct crm_cmd *cmd);
extern void *crm_get_device(const char *name);

extern int spmi_pmic_arb_map_address(struct device *dev, u32 addr, struct resource *res);

// Clean up pr_fmt to allow local redefinitions in .c files
#ifdef pr_fmt
#undef pr_fmt
#endif

#endif
