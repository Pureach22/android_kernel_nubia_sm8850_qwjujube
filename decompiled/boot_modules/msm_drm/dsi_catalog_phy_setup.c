__int64 __fastcall dsi_catalog_phy_setup(__int64 a1, int a2, int a3)
{
  __int64 result; // x0
  void *v6; // x8
  unsigned __int64 v13; // x9

  if ( (unsigned int)(a2 - 10) <= 0xFFFFFFF6 )
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Unsupported version: %d\n", a2);
    return 4294966772LL;
  }
  *(_DWORD *)(a1 + 28) = a3;
  *(_DWORD *)(a1 + 36) = a2;
  _X8 = (unsigned __int64 *)(a1 + 48);
  __asm { PRFM            #0x11, [X8] }
  do
    v13 = __ldxr(_X8);
  while ( __stxr(v13 | 1, _X8) );
  dsi_phy_timing_calc_init(a1, a2);
  if ( a2 > 6 )
  {
    result = 0;
    if ( (unsigned int)(a2 - 8) >= 2 )
    {
      *(_QWORD *)(a1 + 104) = dsi_phy_hw_v5_0_enable;
      *(_QWORD *)(a1 + 128) = dsi_phy_hw_v5_0_disable;
      *(_QWORD *)(a1 + 200) = dsi_phy_hw_calculate_timing_params;
      *(_QWORD *)(a1 + 400) = dsi_phy_hw_v5_0_wait_for_lane_idle;
      *(_QWORD *)(a1 + 424) = dsi_phy_hw_v5_0_ulps_request;
      *(_QWORD *)(a1 + 448) = &dsi_phy_hw_v5_0_ulps_exit;
      *(_QWORD *)(a1 + 472) = dsi_phy_hw_v5_0_get_lanes_in_ulps;
      *(_QWORD *)(a1 + 496) = dsi_phy_hw_v5_0_is_lanes_in_ulps;
      *(_QWORD *)(a1 + 224) = dsi_phy_hw_timing_val_v5_0;
      *(_QWORD *)(a1 + 272) = dsi_phy_hw_v5_0_lane_reset;
      *(_QWORD *)(a1 + 296) = dsi_phy_hw_v5_0_toggle_resync_fifo;
      *(_QWORD *)(a1 + 320) = dsi_phy_hw_v5_0_reset_clk_en_sel;
      *(_QWORD *)(a1 + 568) = dsi_phy_hw_v5_0_dyn_refresh_config;
      *(_QWORD *)(a1 + 592) = dsi_phy_hw_v5_0_dyn_refresh_pipe_delay;
      *(_QWORD *)(a1 + 520) = dsi_phy_hw_v5_0_dyn_refresh_helper;
      *(_QWORD *)(a1 + 544) = dsi_phy_hw_v5_0_dyn_refresh_trigger_sel;
      *(_QWORD *)(a1 + 616) = dsi_phy_hw_v5_0_cache_phy_timings;
      *(_QWORD *)(a1 + 344) = dsi_phy_hw_v5_0_set_continuous_clk;
      *(_QWORD *)(a1 + 368) = dsi_phy_hw_v5_0_commit_phy_timing;
      v6 = dsi_phy_hw_v5_0_phy_idle_off;
    }
    else
    {
      *(_QWORD *)(a1 + 104) = dsi_phy_hw_v7_2_enable;
      *(_QWORD *)(a1 + 128) = dsi_phy_hw_v7_2_disable;
      *(_QWORD *)(a1 + 200) = dsi_phy_hw_calculate_timing_params;
      *(_QWORD *)(a1 + 400) = dsi_phy_hw_v7_2_wait_for_lane_idle;
      *(_QWORD *)(a1 + 424) = dsi_phy_hw_v7_2_ulps_request;
      *(_QWORD *)(a1 + 448) = &dsi_phy_hw_v7_2_ulps_exit;
      *(_QWORD *)(a1 + 472) = dsi_phy_hw_v7_2_get_lanes_in_ulps;
      *(_QWORD *)(a1 + 496) = dsi_phy_hw_v7_2_is_lanes_in_ulps;
      *(_QWORD *)(a1 + 224) = dsi_phy_hw_timing_val_v7_2;
      *(_QWORD *)(a1 + 272) = dsi_phy_hw_v7_2_lane_reset;
      *(_QWORD *)(a1 + 296) = dsi_phy_hw_v7_2_toggle_resync_fifo;
      *(_QWORD *)(a1 + 320) = dsi_phy_hw_v7_2_reset_clk_en_sel;
      *(_QWORD *)(a1 + 568) = dsi_phy_hw_v7_2_dyn_refresh_config;
      *(_QWORD *)(a1 + 592) = dsi_phy_hw_v7_2_dyn_refresh_pipe_delay;
      *(_QWORD *)(a1 + 520) = dsi_phy_hw_v7_2_dyn_refresh_helper;
      *(_QWORD *)(a1 + 544) = dsi_phy_hw_v7_2_dyn_refresh_trigger_sel;
      *(_QWORD *)(a1 + 616) = dsi_phy_hw_v7_2_cache_phy_timings;
      *(_QWORD *)(a1 + 344) = dsi_phy_hw_v7_2_set_continuous_clk;
      *(_QWORD *)(a1 + 368) = dsi_phy_hw_v7_2_commit_phy_timing;
      v6 = dsi_phy_hw_v7_2_phy_idle_off;
    }
    goto LABEL_10;
  }
  if ( (unsigned int)(a2 - 2) < 5 )
  {
    result = 0;
    *(_QWORD *)(a1 + 104) = dsi_phy_hw_v4_0_enable;
    *(_QWORD *)(a1 + 128) = dsi_phy_hw_v4_0_disable;
    *(_QWORD *)(a1 + 200) = dsi_phy_hw_calculate_timing_params;
    *(_QWORD *)(a1 + 400) = dsi_phy_hw_v4_0_wait_for_lane_idle;
    *(_QWORD *)(a1 + 424) = dsi_phy_hw_v4_0_ulps_request;
    *(_QWORD *)(a1 + 448) = &dsi_phy_hw_v4_0_ulps_exit;
    *(_QWORD *)(a1 + 472) = dsi_phy_hw_v4_0_get_lanes_in_ulps;
    *(_QWORD *)(a1 + 496) = dsi_phy_hw_v4_0_is_lanes_in_ulps;
    *(_QWORD *)(a1 + 224) = dsi_phy_hw_timing_val_v4_0;
    *(_QWORD *)(a1 + 272) = dsi_phy_hw_v4_0_lane_reset;
    *(_QWORD *)(a1 + 296) = dsi_phy_hw_v4_0_toggle_resync_fifo;
    *(_QWORD *)(a1 + 320) = dsi_phy_hw_v4_0_reset_clk_en_sel;
    *(_QWORD *)(a1 + 568) = dsi_phy_hw_v4_0_dyn_refresh_config;
    *(_QWORD *)(a1 + 592) = dsi_phy_hw_v4_0_dyn_refresh_pipe_delay;
    *(_QWORD *)(a1 + 520) = dsi_phy_hw_v4_0_dyn_refresh_helper;
    *(_QWORD *)(a1 + 544) = dsi_phy_hw_v4_0_dyn_refresh_trigger_sel;
    *(_QWORD *)(a1 + 616) = dsi_phy_hw_v4_0_cache_phy_timings;
    *(_QWORD *)(a1 + 344) = dsi_phy_hw_v4_0_set_continuous_clk;
    *(_QWORD *)(a1 + 368) = dsi_phy_hw_v4_0_commit_phy_timing;
    v6 = dsi_phy_hw_v4_0_phy_idle_off;
LABEL_10:
    *(_QWORD *)(a1 + 176) = v6;
    *(_QWORD *)(a1 + 56) = 0;
    *(_QWORD *)(a1 + 80) = 0;
    return result;
  }
  *(_QWORD *)(a1 + 56) = dsi_phy_hw_v3_0_regulator_enable;
  *(_QWORD *)(a1 + 80) = dsi_phy_hw_v3_0_regulator_disable;
  *(_QWORD *)(a1 + 104) = dsi_phy_hw_v3_0_enable;
  *(_QWORD *)(a1 + 128) = dsi_phy_hw_v3_0_disable;
  *(_QWORD *)(a1 + 200) = dsi_phy_hw_calculate_timing_params;
  *(_QWORD *)(a1 + 400) = dsi_phy_hw_v3_0_wait_for_lane_idle;
  *(_QWORD *)(a1 + 424) = dsi_phy_hw_v3_0_ulps_request;
  *(_QWORD *)(a1 + 448) = &dsi_phy_hw_v3_0_ulps_exit;
  *(_QWORD *)(a1 + 472) = dsi_phy_hw_v3_0_get_lanes_in_ulps;
  *(_QWORD *)(a1 + 496) = dsi_phy_hw_v3_0_is_lanes_in_ulps;
  *(_QWORD *)(a1 + 224) = dsi_phy_hw_timing_val_v3_0;
  *(_QWORD *)(a1 + 248) = dsi_phy_hw_v3_0_clamp_ctrl;
  *(_QWORD *)(a1 + 272) = dsi_phy_hw_v3_0_lane_reset;
  *(_QWORD *)(a1 + 296) = dsi_phy_hw_v3_0_toggle_resync_fifo;
  *(_QWORD *)(a1 + 568) = dsi_phy_hw_v3_0_dyn_refresh_config;
  *(_QWORD *)(a1 + 592) = dsi_phy_hw_v3_0_dyn_refresh_pipe_delay;
  *(_QWORD *)(a1 + 520) = dsi_phy_hw_v3_0_dyn_refresh_helper;
  *(_QWORD *)(a1 + 616) = dsi_phy_hw_v3_0_cache_phy_timings;
  *(_QWORD *)(a1 + 544) = 0;
  *(_QWORD *)(a1 + 176) = 0;
  return 0;
}
