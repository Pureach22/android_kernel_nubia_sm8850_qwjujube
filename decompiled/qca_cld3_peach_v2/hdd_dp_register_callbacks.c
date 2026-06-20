__int64 __fastcall hdd_dp_register_callbacks(__int64 *a1)
{
  __int64 v2; // x0
  __int64 result; // x0
  _QWORD v4[50]; // [xsp+0h] [xbp-190h] BYREF

  v4[49] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(&v4[7], 0, 0x140u);
  v2 = *a1;
  v4[17] = wlan_hdd_sta_get_dot11mode;
  v4[18] = wlan_hdd_get_ap_client_count;
  v4[19] = wlan_hdd_sta_ndi_connected;
  v4[20] = hdd_any_adapter_connected;
  v4[28] = hdd_pld_request_pm_qos;
  v4[29] = wlan_hdd_pktlog_enable_disable;
  v4[26] = wlan_hdd_pm_qos_update_request;
  v4[27] = hdd_pld_remove_pm_qos;
  v4[24] = wlan_hdd_pm_qos_add_request;
  v4[25] = wlan_hdd_pm_qos_remove_request;
  v4[21] = wlan_hdd_send_svc_nlink_msg;
  v4[23] = wlan_hdd_send_mscs_action_frame;
  v4[30] = wlan_hdd_is_roaming_in_progress;
  v4[31] = hdd_is_ap_active;
  v4[33] = wlan_hdd_napi_apply_throughput_policy;
  v4[34] = wlan_hdd_display_tx_multiq_stats;
  v4[35] = wlan_hdd_display_netif_queue_history;
  v4[37] = hdd_is_link_adapter;
  v4[39] = hdd_get_pause_map;
  v4[40] = hdd_nud_failure_work;
  v4[0] = a1;
  v4[1] = hdd_get_netdev_by_vdev_mac;
  v4[2] = hdd_get_tx_flow_low_watermark;
  v4[3] = hdd_get_tx_resource;
  v4[4] = hdd_get_tsf_time_cb;
  v4[5] = hdd_tsf_timestamp_rx;
  v4[12] = hdd_legacy_gro_get_napi;
  v4[6] = hdd_fils_hlp_rx;
  v4[41] = wlan_hdd_link_speed_update;
  v4[47] = wlan_hdd_get_netdev_by_vdev_id;
  v4[48] = wlan_hdd_update_qtime_sync_period;
  result = os_if_dp_register_hdd_callbacks(v2, v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
