__int64 __fastcall wmi_roam_offload_attach_tlv(__int64 result)
{
  _QWORD *v1; // x8

  v1 = *(_QWORD **)(result + 728);
  v1[2] = extract_roam_initial_info_tlv;
  v1[3] = extract_roam_msg_info_tlv;
  v1[4] = extract_roam_frame_info_tlv;
  v1[5] = extract_roam_sync_event_tlv;
  *v1 = extract_roam_event_tlv;
  v1[1] = extract_roam_btm_response_stats_tlv;
  v1[6] = extract_roam_sync_frame_event_tlv;
  v1[7] = extract_btm_denylist_event;
  v1[8] = extract_vdev_disconnect_event_tlv;
  v1[9] = extract_roam_scan_chan_list_tlv;
  v1[10] = &extract_roam_stats_event_tlv;
  v1[11] = extract_auth_offload_event_tlv;
  v1[114] = send_set_ric_req_cmd_tlv;
  v1[115] = send_process_roam_synch_complete_cmd_tlv;
  v1[117] = send_roam_invoke_cmd_tlv;
  v1[190] = send_vdev_set_pcl_cmd_tlv;
  v1[118] = send_set_roam_trigger_cmd_tlv;
  v1[12] = extract_roam_pmkid_request_tlv;
  v1[13] = extract_roam_candidate_frame_tlv;
  v1[14] = extract_roam_vendor_control_param_event_tlv;
  v1[116] = send_process_roam_vendor_handoff_req_cmd_tlv;
  v1[598] = extract_roam_ml_info_tlv;
  v1[15] = extract_roam_synch_key_event_tlv;
  v1[16] = extract_peer_oper_mode_event_tlv;
  return result;
}
