__int64 __fastcall wmi_sta_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8
  _QWORD *v2; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[201] = send_set_sta_sa_query_param_cmd_tlv;
  v1[200] = send_set_sta_keep_alive_cmd_tlv;
  v1[199] = send_vdev_set_gtx_cfg_cmd_tlv;
  v1[204] = send_process_dhcp_ind_cmd_tlv;
  v1[205] = send_get_link_speed_cmd_tlv;
  v1[202] = send_fw_profiling_cmd_tlv;
  v1[203] = send_nat_keepalive_en_cmd_tlv;
  v1[206] = &send_wlm_latency_level_cmd_tlv;
  v1[187] = send_process_set_ie_info_cmd_tlv;
  v1[188] = send_set_base_macaddr_indicate_cmd_tlv;
  v1[207] = send_tx_power_per_mcs_cmd_tlv;
  v1[208] = send_sar_limit_cmd_tlv;
  v1[209] = get_sar_limit_cmd_tlv;
  v1[210] = extract_sar_limit_event_tlv;
  v1[211] = extract_sar2_result_event_tlv;
  v1[196] = send_set_del_pmkid_cache_cmd_tlv;
  v1[177] = send_del_ts_cmd_tlv;
  v1[178] = send_aggr_qos_cmd_tlv;
  v1[179] = send_add_ts_cmd_tlv;
  v1[180] = send_process_add_periodic_tx_ptrn_cmd_tlv;
  v1[181] = send_process_del_periodic_tx_ptrn_cmd_tlv;
  v1[182] = send_set_auto_shutdown_timer_cmd_tlv;
  v1[193] = send_set_led_flashing_cmd_tlv;
  v1[186] = send_process_ch_avoid_update_cmd_tlv;
  v1[189] = &send_pdev_set_pcl_cmd_tlv;
  v1[197] = send_adapt_dwelltime_params_cmd_tlv;
  v1[198] = send_dbs_scan_sel_params_cmd_tlv;
  v1[194] = send_set_arp_stats_req_cmd_tlv;
  v1[195] = send_get_arp_stats_req_cmd_tlv;
  v1[28] = send_peer_unmap_conf_cmd_tlv;
  v2 = *(_QWORD **)(result + 728);
  v2[212] = send_set_tdls_offchan_mode_cmd_tlv;
  v2[213] = send_update_fw_tdls_state_cmd_tlv;
  v2[214] = send_update_tdls_peer_state_cmd_tlv;
  v2[215] = extract_vdev_tdls_ev_param_tlv;
  *(_QWORD *)(*(_QWORD *)(result + 728) + 1536LL) = send_pdev_set_dual_mac_config_cmd_tlv;
  *(_QWORD *)(*(_QWORD *)(result + 728) + 344LL) = send_reject_ap_list_cmd_tlv;
  return result;
}
