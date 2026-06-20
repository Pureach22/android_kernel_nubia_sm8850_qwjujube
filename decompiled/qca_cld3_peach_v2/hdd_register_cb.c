__int64 __fastcall hdd_register_cb(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  double v10; // d0
  double v11; // d1
  double v12; // d2
  double v13; // d3
  double v14; // d4
  double v15; // d5
  double v16; // d6
  double v17; // d7
  const char *v18; // x2
  unsigned int v19; // w1
  __int64 v20; // x19
  int v21; // w21
  double v22; // d0
  double v23; // d1
  double v24; // d2
  double v25; // d3
  double v26; // d4
  double v27; // d5
  double v28; // d6
  double v29; // d7
  unsigned int v30; // w0
  double v31; // d0
  double v32; // d1
  double v33; // d2
  double v34; // d3
  double v35; // d4
  double v36; // d5
  double v37; // d6
  double v38; // d7
  unsigned int v39; // w19
  double v41; // d0
  double v42; // d1
  double v43; // d2
  double v44; // d3
  double v45; // d4
  double v46; // d5
  double v47; // d6
  double v48; // d7
  double v49; // d0
  double v50; // d1
  double v51; // d2
  double v52; // d3
  double v53; // d4
  double v54; // d5
  double v55; // d6
  double v56; // d7
  double v57; // d0
  double v58; // d1
  double v59; // d2
  double v60; // d3
  double v61; // d4
  double v62; // d5
  double v63; // d6
  double v64; // d7
  __int64 v65; // x21

  qdf_trace_msg(0x33u, 8u, "%s: enter", a2, a3, a4, a5, a6, a7, a8, a9, "hdd_register_cb");
  if ( curr_con_mode == 5 )
  {
    v18 = "%s: in ftm mode, no need to register callbacks";
    v19 = 2;
  }
  else
  {
    v20 = *(_QWORD *)(a1 + 16);
    sme_register_mgmt_frame_ind_callback(v20, hdd_indicate_mgmt_frame);
    sme_set_tsfcb(v20, hdd_get_tsf_cb, a1);
    sme_stats_ext_register_callback(v20, wlan_hdd_cfg80211_stats_ext_callback);
    sme_stats_ext2_register_callback(v20, wlan_hdd_cfg80211_stats_ext2_callback);
    sme_multi_client_ll_rsp_register_callback(v20, hdd_latency_level_event_handler_cb);
    sme_set_rssi_threshold_breached_cb(v20, hdd_rssi_threshold_breached);
    sme_set_link_layer_stats_ind_cb(v20, wlan_hdd_cfg80211_link_layer_stats_callback);
    sme_rso_cmd_status_cb(v20, wlan_hdd_rso_cmd_status_cb);
    sme_set_link_layer_ext_cb(v20, wlan_hdd_cfg80211_link_layer_stats_ext_callback);
    sme_update_hidden_ssid_status_cb(v20, hdd_hidden_ssid_enable_roaming);
    v21 = sme_set_lost_link_info_cb(v20, hdd_lost_link_info_cb);
    wlan_hdd_register_cp_stats_cb(a1);
    hdd_dcs_register_cb(a1);
    hdd_thermal_register_callbacks(a1);
    if ( v21 )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: set lost link info callback failed",
        v22,
        v23,
        v24,
        v25,
        v26,
        v27,
        v28,
        v29,
        "hdd_register_cb");
    v30 = hdd_register_data_stall_detect_cb(v22, v23, v24, v25, v26, v27, v28, v29);
    if ( v30 )
    {
      v39 = v30;
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Register data stall detect detect callback failed.",
        v31,
        v32,
        v33,
        v34,
        v35,
        v36,
        v37,
        v38,
        "hdd_register_cb");
      return v39;
    }
    sme_register_set_connection_info_cb(v20, hdd_set_connection_in_progress, hdd_is_connection_in_progress);
    if ( (unsigned int)sme_set_bt_activity_info_cb(v20, hdd_bt_activity_cb) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: set bt activity info callback failed",
        v41,
        v42,
        v43,
        v44,
        v45,
        v46,
        v47,
        v48,
        "hdd_register_cb");
    if ( (unsigned int)sme_register_tx_queue_cb(v20, hdd_tx_queue_cb) )
      qdf_trace_msg(
        0x33u,
        2u,
        "%s: Register tx queue callback failed",
        v49,
        v50,
        v51,
        v52,
        v53,
        v54,
        v55,
        v56,
        "hdd_register_cb");
    mac_register_session_open_close_cb(*(_QWORD *)(a1 + 16), hdd_sme_close_session_callback, hdd_common_roam_callback);
    sme_set_roam_scan_ch_event_cb(v20, hdd_get_roam_scan_ch_cb);
    if ( (unsigned int)sme_set_monitor_mode_cb(v20, hdd_sme_monitor_mode_callback) )
    {
      v65 = jiffies;
      if ( hdd_register_cb___last_ticks - jiffies + 125 < 0 )
      {
        qdf_trace_msg(
          0x33u,
          2u,
          "%s: Register monitor mode callback failed",
          v57,
          v58,
          v59,
          v60,
          v61,
          v62,
          v63,
          v64,
          "hdd_register_cb");
        hdd_register_cb___last_ticks = v65;
      }
    }
    sme_async_oem_event_init(v20, hdd_oem_event_async_cb);
    sme_smem_oem_event_init(v20, hdd_oem_event_smem_cb);
    sme_register_pagefault_cb(v20, hdd_pagefault_action_cb);
    sme_register_set_disconnect_cb(v20, hdd_set_disconnect_link_info_cb);
    v18 = "%s: exit";
    v19 = 8;
  }
  qdf_trace_msg(0x33u, v19, v18, v10, v11, v12, v13, v14, v15, v16, v17, "hdd_register_cb");
  return 0;
}
