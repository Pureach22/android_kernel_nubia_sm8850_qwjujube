__int64 __fastcall dsi_catalog_ctrl_setup(__int64 a1, int a2, int a3, char a4, char a5)
{
  unsigned int v5; // w8
  unsigned __int64 v13; // x10
  unsigned __int64 v16; // x10
  unsigned __int64 v19; // x10
  unsigned __int64 v22; // x10
  unsigned __int64 v25; // x10
  unsigned __int64 v28; // x11

  if ( (unsigned int)(a2 - 12) > 0xFFFFFFF4 )
  {
    *(_DWORD *)(a1 + 56) = a3;
    *(_BYTE *)(a1 + 1505) = a5 & 1;
    _X9 = (unsigned __int64 *)(a1 + 64);
    __asm { PRFM            #0x11, [X9] }
    do
      v13 = __ldxr(_X9);
    while ( __stxr(v13 | 1, _X9) );
    _X9 = (unsigned __int64 *)(a1 + 64);
    __asm { PRFM            #0x11, [X9] }
    do
      v16 = __ldxr(_X9);
    while ( __stxr(v16 | 2, _X9) );
    _X9 = (unsigned __int64 *)(a1 + 64);
    __asm { PRFM            #0x11, [X9] }
    do
      v19 = __ldxr(_X9);
    while ( __stxr(v19 | 4, _X9) );
    _X9 = (unsigned __int64 *)(a1 + 64);
    __asm { PRFM            #0x11, [X9] }
    do
      v22 = __ldxr(_X9);
    while ( __stxr(v22 | 8, _X9) );
    _X9 = (unsigned __int64 *)(a1 + 64);
    __asm { PRFM            #0x11, [X9] }
    do
      v25 = __ldxr(_X9);
    while ( __stxr(v25 | 0x20, _X9) );
    _X10 = (unsigned __int64 *)(a1 + 64);
    __asm { PRFM            #0x11, [X10] }
    do
      v28 = __ldxr(_X10);
    while ( __stxr(v28 | 0x40, _X10) );
    *(_BYTE *)(a1 + 1504) = a4 & 1;
    if ( (unsigned int)(a2 - 1) > 2 )
    {
      v5 = 0;
      *(_BYTE *)(a1 + 1506) = 1;
      *(_QWORD *)(a1 + 72) = dsi_ctrl_hw_cmn_host_setup;
      *(_QWORD *)(a1 + 96) = dsi_ctrl_hw_cmn_video_engine_en;
      *(_QWORD *)(a1 + 144) = &dsi_ctrl_hw_cmn_video_engine_setup;
      *(_QWORD *)(a1 + 168) = dsi_ctrl_hw_cmn_set_video_timing;
      *(_QWORD *)(a1 + 1056) = dsi_ctrl_hw_cmn_set_timing_db;
      *(_QWORD *)(a1 + 192) = &dsi_ctrl_hw_cmn_cmd_engine_setup;
      *(_QWORD *)(a1 + 216) = dsi_ctrl_hw_cmn_setup_cmd_stream;
      *(_QWORD *)(a1 + 240) = dsi_ctrl_hw_cmn_ctrl_en;
      *(_QWORD *)(a1 + 264) = dsi_ctrl_hw_cmn_cmd_engine_en;
      *(_QWORD *)(a1 + 288) = dsi_ctrl_hw_cmn_phy_sw_reset;
      *(_QWORD *)(a1 + 336) = dsi_ctrl_hw_cmn_soft_reset;
      *(_QWORD *)(a1 + 384) = dsi_ctrl_hw_cmn_kickoff_command;
      *(_QWORD *)(a1 + 432) = dsi_ctrl_hw_cmn_kickoff_fifo_command;
      *(_QWORD *)(a1 + 456) = dsi_ctrl_hw_cmn_reset_cmd_fifo;
      *(_QWORD *)(a1 + 480) = dsi_ctrl_hw_cmn_trigger_command_dma;
      *(_QWORD *)(a1 + 696) = dsi_ctrl_hw_cmn_get_interrupt_status;
      *(_QWORD *)(a1 + 744) = dsi_ctrl_hw_cmn_poll_dma_status;
      *(_QWORD *)(a1 + 792) = dsi_ctrl_hw_cmn_get_error_status;
      *(_QWORD *)(a1 + 816) = dsi_ctrl_hw_cmn_clear_error_status;
      *(_QWORD *)(a1 + 720) = dsi_ctrl_hw_cmn_clear_interrupt_status;
      *(_QWORD *)(a1 + 768) = dsi_ctrl_hw_cmn_enable_status_interrupts;
      *(_QWORD *)(a1 + 840) = dsi_ctrl_hw_cmn_enable_error_interrupts;
      *(_QWORD *)(a1 + 864) = dsi_ctrl_hw_cmn_video_test_pattern_setup;
      *(_QWORD *)(a1 + 888) = dsi_ctrl_hw_cmn_cmd_test_pattern_setup;
      *(_QWORD *)(a1 + 912) = dsi_ctrl_hw_cmn_test_pattern_enable;
      *(_QWORD *)(a1 + 960) = dsi_ctrl_hw_cmn_trigger_cmd_test_pattern;
      *(_QWORD *)(a1 + 936) = dsi_ctrl_hw_dln0_phy_err;
      *(_QWORD *)(a1 + 504) = dsi_ctrl_hw_cmn_get_cmd_read_data;
      *(_QWORD *)(a1 + 1080) = dsi_ctrl_hw_cmn_clear_rdbk_reg;
      *(_QWORD *)(a1 + 1128) = dsi_ctrl_hw_cmn_ctrl_reset;
      *(_QWORD *)(a1 + 1152) = dsi_ctrl_hw_cmn_mask_error_intr;
      *(_QWORD *)(a1 + 1176) = dsi_ctrl_hw_cmn_error_intr_ctrl;
      *(_QWORD *)(a1 + 1200) = dsi_ctrl_hw_cmn_get_error_mask;
      *(_QWORD *)(a1 + 1224) = dsi_ctrl_hw_cmn_get_hw_version;
      *(_QWORD *)(a1 + 1248) = dsi_ctrl_hw_cmn_wait_for_cmd_mode_mdp_idle;
      *(_QWORD *)(a1 + 120) = dsi_ctrl_hw_cmn_setup_avr;
      *(_QWORD *)(a1 + 1272) = dsi_ctrl_hw_cmn_set_continuous_clk;
      *(_QWORD *)(a1 + 1296) = dsi_ctrl_hw_cmn_wait4dynamic_refresh_done;
      *(_QWORD *)(a1 + 1344) = dsi_ctrl_hw_cmn_hs_req_sel;
      *(_QWORD *)(a1 + 1320) = dsi_ctrl_hw_cmn_vid_engine_busy;
      *(_QWORD *)(a1 + 1416) = &dsi_ctrl_hw_cmn_init_cmddma_trig_ctrl;
      *(_QWORD *)(a1 + 672) = dsi_ctrl_hw_22_phy_reset_config;
      *(_QWORD *)(a1 + 312) = dsi_ctrl_hw_22_config_clk_gating;
      *(_QWORD *)(a1 + 360) = dsi_ctrl_hw_22_setup_lane_map;
      *(_QWORD *)(a1 + 528) = dsi_ctrl_hw_22_wait_for_lane_idle;
      *(_QWORD *)(a1 + 984) = dsi_ctrl_hw_22_reg_dump_to_buffer;
      *(_QWORD *)(a1 + 552) = dsi_ctrl_hw_cmn_ulps_request;
      *(_QWORD *)(a1 + 576) = dsi_ctrl_hw_cmn_ulps_exit;
      *(_QWORD *)(a1 + 600) = dsi_ctrl_hw_cmn_get_lanes_in_ulps;
      *(_QWORD *)(a1 + 1104) = dsi_ctrl_hw_22_schedule_dma_cmd;
      *(_QWORD *)(a1 + 408) = dsi_ctrl_hw_kickoff_non_embedded_mode;
      *(_QWORD *)(a1 + 1368) = dsi_ctrl_hw_22_configure_cmddma_window;
      *(_QWORD *)(a1 + 1392) = dsi_ctrl_hw_22_reset_trigger_controls;
      *(_QWORD *)(a1 + 1440) = dsi_ctrl_hw_22_log_line_count;
      *(_QWORD *)(a1 + 1464) = dsi_ctrl_hw_22_configure_splitlink;
      *(_QWORD *)(a1 + 1008) = dsi_ctrl_hw_22_setup_misr;
      *(_QWORD *)(a1 + 624) = 0;
      *(_QWORD *)(a1 + 648) = 0;
      *(_QWORD *)(a1 + 1032) = dsi_ctrl_hw_22_collect_misr;
    }
    else
    {
      *(_QWORD *)(a1 + 72) = dsi_ctrl_hw_cmn_host_setup;
      *(_QWORD *)(a1 + 96) = dsi_ctrl_hw_cmn_video_engine_en;
      *(_QWORD *)(a1 + 144) = &dsi_ctrl_hw_cmn_video_engine_setup;
      *(_QWORD *)(a1 + 168) = dsi_ctrl_hw_cmn_set_video_timing;
      *(_QWORD *)(a1 + 1056) = dsi_ctrl_hw_cmn_set_timing_db;
      *(_QWORD *)(a1 + 192) = &dsi_ctrl_hw_cmn_cmd_engine_setup;
      *(_QWORD *)(a1 + 216) = dsi_ctrl_hw_cmn_setup_cmd_stream;
      *(_QWORD *)(a1 + 240) = dsi_ctrl_hw_cmn_ctrl_en;
      *(_QWORD *)(a1 + 264) = dsi_ctrl_hw_cmn_cmd_engine_en;
      *(_QWORD *)(a1 + 288) = dsi_ctrl_hw_cmn_phy_sw_reset;
      *(_QWORD *)(a1 + 336) = dsi_ctrl_hw_cmn_soft_reset;
      *(_QWORD *)(a1 + 384) = dsi_ctrl_hw_cmn_kickoff_command;
      *(_QWORD *)(a1 + 432) = dsi_ctrl_hw_cmn_kickoff_fifo_command;
      *(_QWORD *)(a1 + 456) = dsi_ctrl_hw_cmn_reset_cmd_fifo;
      *(_QWORD *)(a1 + 480) = dsi_ctrl_hw_cmn_trigger_command_dma;
      *(_QWORD *)(a1 + 696) = dsi_ctrl_hw_cmn_get_interrupt_status;
      *(_QWORD *)(a1 + 744) = dsi_ctrl_hw_cmn_poll_dma_status;
      *(_QWORD *)(a1 + 792) = dsi_ctrl_hw_cmn_get_error_status;
      *(_QWORD *)(a1 + 816) = dsi_ctrl_hw_cmn_clear_error_status;
      *(_QWORD *)(a1 + 720) = dsi_ctrl_hw_cmn_clear_interrupt_status;
      *(_QWORD *)(a1 + 768) = dsi_ctrl_hw_cmn_enable_status_interrupts;
      *(_QWORD *)(a1 + 840) = dsi_ctrl_hw_cmn_enable_error_interrupts;
      *(_QWORD *)(a1 + 864) = dsi_ctrl_hw_cmn_video_test_pattern_setup;
      *(_QWORD *)(a1 + 888) = dsi_ctrl_hw_cmn_cmd_test_pattern_setup;
      *(_QWORD *)(a1 + 912) = dsi_ctrl_hw_cmn_test_pattern_enable;
      *(_QWORD *)(a1 + 960) = dsi_ctrl_hw_cmn_trigger_cmd_test_pattern;
      *(_QWORD *)(a1 + 936) = dsi_ctrl_hw_dln0_phy_err;
      *(_QWORD *)(a1 + 504) = dsi_ctrl_hw_cmn_get_cmd_read_data;
      *(_QWORD *)(a1 + 1080) = dsi_ctrl_hw_cmn_clear_rdbk_reg;
      *(_QWORD *)(a1 + 1128) = dsi_ctrl_hw_cmn_ctrl_reset;
      *(_QWORD *)(a1 + 1152) = dsi_ctrl_hw_cmn_mask_error_intr;
      *(_QWORD *)(a1 + 1176) = dsi_ctrl_hw_cmn_error_intr_ctrl;
      *(_QWORD *)(a1 + 1200) = dsi_ctrl_hw_cmn_get_error_mask;
      *(_QWORD *)(a1 + 1224) = dsi_ctrl_hw_cmn_get_hw_version;
      *(_QWORD *)(a1 + 1248) = dsi_ctrl_hw_cmn_wait_for_cmd_mode_mdp_idle;
      *(_QWORD *)(a1 + 120) = dsi_ctrl_hw_cmn_setup_avr;
      *(_QWORD *)(a1 + 1272) = dsi_ctrl_hw_cmn_set_continuous_clk;
      *(_QWORD *)(a1 + 1296) = dsi_ctrl_hw_cmn_wait4dynamic_refresh_done;
      *(_QWORD *)(a1 + 1344) = dsi_ctrl_hw_cmn_hs_req_sel;
      *(_QWORD *)(a1 + 1320) = dsi_ctrl_hw_cmn_vid_engine_busy;
      *(_QWORD *)(a1 + 1416) = &dsi_ctrl_hw_cmn_init_cmddma_trig_ctrl;
      *(_QWORD *)(a1 + 672) = dsi_ctrl_hw_22_phy_reset_config;
      *(_QWORD *)(a1 + 312) = dsi_ctrl_hw_22_config_clk_gating;
      *(_QWORD *)(a1 + 360) = dsi_ctrl_hw_22_setup_lane_map;
      *(_QWORD *)(a1 + 528) = dsi_ctrl_hw_22_wait_for_lane_idle;
      *(_QWORD *)(a1 + 984) = dsi_ctrl_hw_22_reg_dump_to_buffer;
      *(_QWORD *)(a1 + 552) = dsi_ctrl_hw_cmn_ulps_request;
      *(_QWORD *)(a1 + 576) = dsi_ctrl_hw_cmn_ulps_exit;
      *(_QWORD *)(a1 + 600) = dsi_ctrl_hw_cmn_get_lanes_in_ulps;
      *(_QWORD *)(a1 + 1104) = dsi_ctrl_hw_22_schedule_dma_cmd;
      *(_QWORD *)(a1 + 408) = dsi_ctrl_hw_kickoff_non_embedded_mode;
      *(_QWORD *)(a1 + 1368) = dsi_ctrl_hw_22_configure_cmddma_window;
      *(_QWORD *)(a1 + 1392) = dsi_ctrl_hw_22_reset_trigger_controls;
      *(_QWORD *)(a1 + 1440) = dsi_ctrl_hw_22_log_line_count;
      *(_QWORD *)(a1 + 1464) = dsi_ctrl_hw_22_configure_splitlink;
      *(_QWORD *)(a1 + 1008) = dsi_ctrl_hw_22_setup_misr;
      v5 = 0;
      *(_QWORD *)(a1 + 1032) = dsi_ctrl_hw_22_collect_misr;
      *(_QWORD *)(a1 + 624) = 0;
      *(_QWORD *)(a1 + 648) = 0;
    }
  }
  else
  {
    drm_dev_printk(0, &unk_248D72, "*ERROR* [msm-dsi-error]: Unsupported version: %d\n", a2);
    return (unsigned int)-524;
  }
  return v5;
}
