_QWORD *__fastcall target_if_cm_roam_register_rx_ops(_QWORD *result)
{
  *result = cm_roam_sync_event_handler;
  result[1] = cm_roam_sync_frame_event_handler;
  result[2] = cm_roam_sync_key_event_handler;
  result[3] = cm_roam_event_handler;
  result[4] = cm_btm_denylist_event_handler;
  result[5] = cm_vdev_disconnect_event_handler;
  result[6] = cm_roam_scan_ch_list_event_handler;
  result[7] = cm_roam_stats_event_handler;
  result[8] = cm_roam_auth_offload_event_handler;
  result[9] = cm_roam_pmkid_request_handler;
  result[10] = cm_roam_candidate_event_handler;
  result[11] = cm_roam_vendor_handoff_event_handler;
  return result;
}
