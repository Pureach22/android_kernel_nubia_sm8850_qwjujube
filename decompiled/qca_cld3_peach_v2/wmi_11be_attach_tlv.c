__int64 __fastcall wmi_11be_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[584] = extract_mlo_link_set_active_resp_tlv;
  v1[582] = &send_mlo_link_set_active_cmd_tlv;
  v1[607] = &send_mlo_peer_tid_to_link_map_cmd_tlv;
  v1[608] = &send_mlo_vdev_tid_to_link_map_cmd_tlv;
  v1[609] = send_link_state_request_cmd_tlv;
  v1[610] = send_link_set_bss_params_cmd_tlv;
  v1[611] = extract_mlo_vdev_tid_to_link_map_event_tlv;
  v1[612] = extract_mlo_vdev_bcast_tid_to_link_map_event_tlv;
  v1[604] = &extract_mlo_link_state_event_tlv;
  v1[585] = extract_mgmt_rx_ml_cu_params_tlv;
  v1[586] = send_mlo_link_removal_cmd_tlv;
  v1[587] = extract_mlo_link_removal_evt_fixed_param_tlv;
  v1[588] = extract_mlo_3_link_tlt_selection_fixed_param_tlv;
  v1[589] = extract_mlo_link_removal_tbtt_update_tlv;
  v1[590] = extract_mgmt_rx_mlo_link_removal_info_tlv;
  v1[591] = extract_mlo_link_disable_request_evt_param_tlv;
  v1[583] = send_mlo_vdev_pause_cmd_tlv;
  v1[593] = extract_mlo_link_switch_request_event_tlv;
  v1[594] = send_link_switch_request_cnf_cmd_tlv;
  v1[592] = &extract_mlo_link_state_switch_event_tlv;
  v1[595] = extract_mlo_link_recfg_indication_event_tlv;
  v1[596] = send_mlo_link_recfg_complete_cmd_tlv;
  v1[643] = send_link_reconfig_req_cmd_tlv;
  v1[597] = send_mlo_ttlm_complete_cmd_tlv;
  return result;
}
