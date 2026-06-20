__int64 __fastcall wmi_roam_attach_tlv(__int64 result)
{
  __int64 (__fastcall **v1)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *); // x8
  __int64 v2; // x8
  __int64 (__fastcall **v3)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *); // x8

  v1 = *(__int64 (__fastcall ***)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))(result + 728);
  v1[91] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_roam_scan_offload_rssi_thresh_cmd_tlv;
  v1[93] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_roam_mawc_params_cmd_tlv;
  v1[94] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_roam_scan_filter_cmd_tlv;
  v1[95] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_roam_scan_offload_mode_cmd_tlv;
  v1[96] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_roam_scan_offload_ap_profile_cmd_tlv;
  v1[97] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_roam_scan_offload_cmd_tlv;
  v1[92] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_roam_scan_offload_scan_period_cmd_tlv;
  v1[98] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_roam_scan_offload_chan_list_cmd_tlv;
  v1[99] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_roam_scan_offload_rssi_change_cmd_tlv;
  v1[100] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_per_roam_config_cmd_tlv;
  v1[108] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_limit_off_chan_cmd_tlv;
  v1[107] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_btm_config_cmd_tlv;
  v1[101] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_offload_11k_cmd_tlv;
  v1[102] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_invoke_neighbor_report_cmd_tlv;
  v1[103] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_roam_bss_load_config_tlv;
  v1[105] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_idle_roam_params_tlv;
  v1[104] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_disconnect_roam_params_tlv;
  v1[106] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_roam_preauth_status_tlv;
  *v1 = extract_roam_event_tlv;
  *(_QWORD *)(*(_QWORD *)(result + 728) + 712LL) = send_set_gateway_params_cmd_tlv;
  *(_QWORD *)(*(_QWORD *)(result + 728) + 720LL) = send_set_rssi_monitoring_cmd_tlv;
  v2 = *(_QWORD *)(result + 728);
  *(_QWORD *)(v2 + 880) = send_plm_stop_cmd_tlv;
  *(_QWORD *)(v2 + 888) = send_plm_start_cmd_tlv;
  v3 = *(__int64 (__fastcall ***)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))(result + 728);
  v3[2] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))extract_roam_initial_info_tlv;
  v3[3] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))extract_roam_msg_info_tlv;
  v3[4] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))extract_roam_frame_info_tlv;
  v3[5] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))extract_roam_sync_event_tlv;
  *v3 = extract_roam_event_tlv;
  v3[1] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))extract_roam_btm_response_stats_tlv;
  v3[6] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))extract_roam_sync_frame_event_tlv;
  v3[7] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))extract_btm_denylist_event;
  v3[8] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))extract_vdev_disconnect_event_tlv;
  v3[9] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))extract_roam_scan_chan_list_tlv;
  v3[10] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))&extract_roam_stats_event_tlv;
  v3[11] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))extract_auth_offload_event_tlv;
  v3[112] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_set_ric_req_cmd_tlv;
  v3[113] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_process_roam_synch_complete_cmd_tlv;
  v3[115] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_roam_invoke_cmd_tlv;
  v3[188] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_vdev_set_pcl_cmd_tlv;
  v3[116] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_set_roam_trigger_cmd_tlv;
  v3[12] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))extract_roam_pmkid_request_tlv;
  v3[13] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))extract_roam_candidate_frame_tlv;
  v3[14] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))extract_roam_vendor_control_param_event_tlv;
  v3[15] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))extract_peer_oper_mode_event_tlv;
  v3[114] = (__int64 (__fastcall *)(double, double, double, double, double, double, double, double, __int64, __int64, __int64, unsigned __int8 *))send_process_roam_vendor_handoff_req_cmd_tlv;
  *(_QWORD *)(*(_QWORD *)(result + 728) + 872LL) = send_roam_scan_send_hlp_cmd_tlv;
  return result;
}
