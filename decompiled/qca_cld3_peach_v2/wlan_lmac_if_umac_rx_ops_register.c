__int64 __fastcall wlan_lmac_if_umac_rx_ops_register(
        __int64 (__fastcall **a1)(__int64 a1, unsigned int a2, unsigned int a3, __int64 a4),
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  void (__fastcall *v10)(__int64 (__fastcall **)(__int64, unsigned int, unsigned int, __int64)); // x8

  if ( a1 )
  {
    *a1 = tgt_mgmt_txrx_tx_completion_handler;
    a1[1] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_mgmt_txrx_rx_frame_handler;
    a1[2] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_mgmt_txrx_get_nbuf_from_desc_id;
    a1[3] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_mgmt_txrx_get_peer_from_desc_id;
    a1[4] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_mgmt_txrx_get_vdev_id_from_desc_id;
    a1[5] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_mgmt_txrx_get_free_desc_pool_count;
    a1[6] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_mgmt_txrx_rx_frame_entry;
    a1[7] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_scan_event_handler;
    a1[8] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_scan_set_max_active_scans;
    a1[9] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))&tgt_scan_cached_scan_report_ev_handler;
    a1[25] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_cp_stats_twt_get_session_evt_handler;
    tgt_cp_stats_register_rx_ops();
    a1[26] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dcs_process_event;
    a1[27] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_cfr_support_set;
    a1[28] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_cfr_info_send;
    a1[29] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_cfr_capture_count_support_set;
    a1[30] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_cfr_mo_marking_support_set;
    a1[31] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_cfr_aoa_for_rcc_support_set;
    wlan_crypto_register_crypto_rx_ops(a1 + 41);
    v10 = (void (__fastcall *)(__int64 (__fastcall **)(__int64, unsigned int, unsigned int, __int64)))wlan_lmac_if_umac_crypto_rxpn_ops_register;
    if ( wlan_lmac_if_umac_crypto_rxpn_ops_register )
    {
      if ( *((_DWORD *)wlan_lmac_if_umac_crypto_rxpn_ops_register - 1) != 1524953787 )
        __break(0x8228u);
      v10(a1);
    }
    wifi_pos_register_rx_ops(a1);
    a1[48] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wifi_pos_handle_ranging_peer_create;
    a1[49] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wifi_pos_handle_ranging_peer_create_rsp;
    a1[50] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wifi_pos_handle_ranging_peer_delete;
    a1[51] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wifi_pos_vdev_delete_all_ranging_peers_rsp;
    a1[133] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_tdls_event_handler;
    a1[53] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_reg_process_master_chan_list;
    a1[54] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_reg_process_master_chan_list_ext;
    a1[55] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_reg_process_c2c_detect_evt;
    a1[56] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_reg_process_11d_new_country;
    a1[57] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_reg_set_regdb_offloaded;
    a1[58] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_reg_set_11d_offloaded;
    a1[59] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_reg_set_6ghz_supported;
    a1[60] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_reg_set_5dot9_ghz_supported;
    a1[61] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wlan_reg_get_dfs_region;
    a1[62] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_reg_process_ch_avoid_event;
    a1[63] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wlan_reg_freq_to_chan;
    a1[64] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_reg_modify_chan_144;
    a1[65] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_reg_get_en_chan_144;
    a1[66] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_reg_program_default_cc;
    a1[67] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wlan_reg_get_curr_regdomain;
    a1[68] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_reg_enable_dfs_channels;
    a1[69] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wlan_reg_modify_pdev_chan_range;
    a1[70] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wlan_reg_update_pdev_wireless_modes;
    a1[71] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wlan_reg_is_range_only6g;
    a1[72] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wlan_reg_is_range_overlap_6g;
    a1[74] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_reg_ignore_fw_reg_offload_ind;
    a1[73] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wlan_reg_disable_chan_coex;
    a1[75] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_reg_get_unii_5g_bitmap;
    a1[76] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_reg_set_ext_tpc_supported;
    a1[77] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_reg_set_lower_6g_edge_ch_supp;
    a1[78] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_reg_set_disable_upper_6g_edge_ch_supp;
    a1[79] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wlan_reg_display_super_chan_list;
    a1[80] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_reg_set_both_psd_eirp_preferred_support;
    a1[81] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_reg_get_both_psd_eirp_preferred_support;
    a1[82] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_reg_process_r2p_table_update_response;
    a1[83] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wlan_reg_is_5dot9_ghz_supported;
    a1[84] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_reg_process_txpb_event_handler;
    a1[16] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_p2p_lo_event_cb;
    a1[17] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_p2p_noa_event_cb;
    a1[18] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_p2p_add_mac_addr_status_event_cb;
    a1[19] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_p2p_ap_assist_dfs_group_bmiss_ev_handler;
    a1[20] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_p2p_mcc_quota_event_cb;
    a1[85] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_get_radars;
    a1[86] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_process_phyerr;
    a1[87] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_destroy_object;
    a1[88] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_radar_enable;
    a1[89] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_is_radar_enabled;
    a1[90] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_control;
    a1[91] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_is_precac_timer_running;
    a1[92] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_agile_precac_start;
    a1[93] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_set_agile_precac_state;
    a1[96] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))utils_dfs_start_precac_timer;
    a1[97] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))utils_dfs_cancel_precac_timer;
    a1[94] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_dfs_reset_agile_config;
    a1[98] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_dfs_override_precac_timeout;
    a1[99] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_dfs_set_precac_enable;
    a1[100] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_dfs_get_agile_precac_enable;
    a1[101] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_dfs_get_override_precac_timeout;
    a1[103] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_process_radar_ind;
    a1[104] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_cac_complete;
    a1[95] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_ocac_complete;
    a1[105] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_stop;
    a1[106] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_dfs_reinit_timers;
    a1[107] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_enable_stadfs;
    a1[108] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_is_stadfs_enabled;
    a1[109] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_process_phyerr_filter_offload;
    a1[110] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_is_phyerr_filter_offload;
    a1[111] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_dfs_set_override_status_timeout;
    a1[112] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_dfs_get_override_status_timeout;
    a1[113] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_reset_spoof_test;
    a1[114] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))utils_dfs_get_disable_radar_marking;
    a1[115] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_dfs_set_nol_subchannel_marking;
    a1[116] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_dfs_get_nol_subchannel_marking;
    a1[121] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))utils_dfs_bw_reduce;
    a1[122] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))utils_dfs_is_bw_reduce;
    a1[123] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_dfs_allow_hw_pulses;
    a1[124] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_dfs_is_hw_pulses_allowed;
    a1[125] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_set_fw_adfs_support;
    a1[126] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))utils_dfs_reset_dfs_prevchan;
    a1[127] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_init_tmp_psoc_nol;
    a1[128] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_deinit_tmp_psoc_nol;
    a1[129] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_save_dfs_nol_in_psoc;
    a1[130] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_reinit_nol_from_psoc_copy;
    a1[131] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_reinit_precac_lists;
    a1[132] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_complete_deferred_tasks;
    a1[102] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))tgt_dfs_set_current_channel_for_freq;
    a1[147] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wlan_green_ap_is_ps_enabled;
    a1[148] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_green_ap_get_debug_prints;
    a1[150] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_green_ap_set_ps_config;
    a1[149] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))ucfg_green_ap_get_ps_config;
    a1[151] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wlan_green_ap_suspend_handle;
    a1[153] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wlan_ftm_process_utf_event;
    tgt_vdev_mgr_register_rx_ops(a1);
    a1[154] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))mlo_process_link_set_active_resp;
    a1[155] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wlan_mlo_vdev_tid_to_link_map_event;
    a1[157] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wlan_handle_ml_link_state_info_event;
    a1[158] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))wlan_mlo_link_disable_request_handler;
    a1[159] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))mlo_mgr_link_switch_request_params;
    a1[160] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))mlo_mgr_link_state_switch_info_handler;
    a1[161] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))&mlo_mgr_link_recfg_indication_event_handler;
    a1[162] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))&mlo_mgr_link_recfg_req_cmd_handler;
    tgt_twt_register_rx_ops(a1);
    a1[173] = (__int64 (__fastcall *)(__int64, unsigned int, unsigned int, __int64))target_if_dbam_process_event;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x38u,
      2u,
      "%s: lmac if rx ops pointer is NULL",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "wlan_lmac_if_umac_rx_ops_register");
    return 4;
  }
}
