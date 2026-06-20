 
#include "zte_disp_feature.h"
#include "../sde/sde_connector.h"
#include "../sde/sde_encoder.h"
#include "../sde/sde_encoder_phys.h"
#include "../sde/sde_trace.h"
#include <drm/drm_vblank.h>
#include "zte_disp_work.h"
#include "zte_disp_backlight.h"

#define to_sde_encoder_phys_cmd(x) \
    	container_of(x, struct sde_encoder_phys_cmd, base)

void sync_te(struct sde_encoder_virt *sde_enc) {
    struct sde_connector *c_conn = NULL;
    struct dsi_display *display = NULL;
    struct dsi_panel * p = NULL;
    struct sde_encoder_phys *phys_encoder = NULL;
    struct sde_encoder_phys_cmd *cmd_enc = NULL;
    struct sde_encoder_phys_cmd_te_timestamp *te_timestamp;
    ktime_t te_ktime;
    s64 diff, delay;
    s64 us_per_frame;
    s64 vsync_area = 9000;
    u32 fps;

    if (!sde_enc || !sde_enc->cur_master || !sde_enc->cur_master->connector)
	    return;

    c_conn = to_sde_connector(sde_enc->cur_master->connector);
	if (!c_conn)
		return;

    phys_encoder = sde_enc->phys_encs[0];
    if (!phys_encoder)
        return;

    cmd_enc = to_sde_encoder_phys_cmd(phys_encoder);
    if (!cmd_enc)
        return;

    if (c_conn->connector_type != DRM_MODE_CONNECTOR_DSI)
        return;

    display = c_conn->display;

	if (!display || !display->panel)
		return;

    p = display->panel;

    fps = p->cur_mode->timing.refresh_rate;
    if (fps >= 120) {
        vsync_area = 200;
    }

    us_per_frame = 1000000 / fps;

    if (c_conn->encoder)
        sde_encoder_wait_for_event(c_conn->encoder, MSM_ENC_VBLANK);

    te_timestamp = list_last_entry(&cmd_enc->te_timestamp_list, struct sde_encoder_phys_cmd_te_timestamp, list);
    te_ktime = te_timestamp->timestamp;
    diff = ktime_to_us(ktime_sub(ktime_get(), te_ktime));
    /* away te signal "diff" us */
    diff = diff % us_per_frame;
    if (diff < vsync_area) {
        delay = vsync_area - diff;
    } else {
        delay = us_per_frame - diff + vsync_area;
    }
    usleep_range(delay, delay + 10);
}

void process_aod_bl(struct dsi_panel *panel, u32 layer, u32 lv) {
    if (!panel)
        return;
     
    if (panel->aod_state == AOD_STATE_BOTH_ACTIVE) {
       if (panel->drm_aod_bl == lv)
           return;

        panel->drm_aod_bl = lv;

        queue_work(panel->aodbl_workq, &panel->aodbl_work);
    }
}

/*
 * aod bl : 0 miss, 1/2/3 level
 * layer : aod/fod/sdr_dim
 */
void sde_sync_aod_and_fod(struct sde_encoder_virt *sde_enc, u32 aodbl, u32 layer)
{
	struct sde_connector *c_conn = NULL;
    struct dsi_display *display = NULL;
    struct dsi_panel *p = NULL;
    bool aod_layer = false;
    bool fod_layer = false;

    if (!sde_enc || !sde_enc->cur_master || !sde_enc->cur_master->connector)
	    return;

    c_conn = to_sde_connector(sde_enc->cur_master->connector);
	if (!c_conn)
		return;

    if (c_conn->connector_type != DRM_MODE_CONNECTOR_DSI)
        return;

    display = c_conn->display;

    if (!display || !display->panel)
        return;

    p = display->panel;

    process_aod_bl(p, layer, aodbl);

    aod_layer = (layer & 0x1) > 0 ? true : false;
    fod_layer = (layer & 0x2) > 0 ? true : false;
    
    if (p->aod_layer != aod_layer) {
       p->aod_layer = aod_layer;
       zte_aod_handler(p, aod_layer ? FRAME_AOD_ACTIVE : FRAME_AOD_MISS);
    }

    if (p->fod_layer != fod_layer) {
       p->fod_layer = fod_layer;
       sync_te(sde_enc);
       zte_fod_handler(p, fod_layer ? FOD_ACTIVE : FOD_MISS);
    }
}

void sde_sync_sdr_dim(struct sde_encoder_virt *sde_enc, u32 sdr_dim, u64 bl)
{
	struct sde_connector *c_conn = NULL;
    struct dsi_display *display = NULL;
    struct dsi_panel * p = NULL;
    u64 bl_lvl;

    if (!sde_enc || !sde_enc->cur_master || !sde_enc->cur_master->connector)
	    return;

    c_conn = to_sde_connector(sde_enc->cur_master->connector);
	if (!c_conn)
		return;

    if (c_conn->connector_type != DRM_MODE_CONNECTOR_DSI)
        return;
    
    display = c_conn->display;

    if (!display || !display->panel)
        return;

    p = display->panel;

    c_conn->fsdr_dim = sdr_dim;

    bl_lvl = mult_frac(bl,  p->bl_config.bl_max_level, p->bl_config.brightness_max_level);

    if (c_conn->last_fsdr_dim != c_conn->fsdr_dim) {
        sync_te(sde_enc);
        dsi_panel_dim_handle(display->panel, false, false, false);
        zte_set_disp_parameter(p, ZTE_LCD_SET_SYNC_BL, bl_lvl, false);
        c_conn->last_fsdr_dim = c_conn->fsdr_dim;
        return;
    }

    if (sdr_dim) {
        dsi_panel_dim_handle(display->panel, true, false, false);
        zte_set_disp_parameter(p, ZTE_LCD_SET_SYNC_BL, bl_lvl, false);
    }
}

int sde_connector_frame_handler(void *sde_encoder_virt) {
    struct sde_encoder_virt *sde_enc = sde_encoder_virt;
	struct sde_connector *c_conn = NULL;
    if (!sde_enc || !sde_enc->cur_master || !sde_enc->cur_master->connector) {
		pr_err("Invalid sde_enc params\n");
		return -EINVAL;
	}

    c_conn = to_sde_connector(sde_enc->cur_master->connector);
	if (!c_conn) {
		pr_err("Invalid c_conn params\n");
		return -EINVAL;
	}

    if (c_conn->connector_type != DRM_MODE_CONNECTOR_DSI) {
		//pr_err("not in dsi mode\n");
		return 0;
	}

    sde_sync_aod_and_fod(sde_enc,
                         sde_connector_get_property(c_conn->base.state, CONNECTOR_PROP_ZTE_AOD_BL),
                         sde_connector_get_property(c_conn->base.state, CONNECTOR_PROP_ZTE_LAYER_TYPE));

    sde_sync_sdr_dim(sde_enc,
                     (sde_connector_get_property(c_conn->base.state, CONNECTOR_PROP_ZTE_LAYER_TYPE) & 0x4) > 0 ? 1 : 0,
                     sde_connector_get_property(c_conn->base.state, CONNECTOR_PROP_BRIGHTNESS));

    return 0;
 }