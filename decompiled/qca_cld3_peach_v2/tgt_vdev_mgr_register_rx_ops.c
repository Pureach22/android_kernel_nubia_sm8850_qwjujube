_QWORD *__fastcall tgt_vdev_mgr_register_rx_ops(_QWORD *result)
{
  result[137] = tgt_vdev_mgr_offload_bcn_tx_status_event_handler;
  result[138] = tgt_vdev_mgr_tbttoffset_update_handler;
  result[134] = tgt_vdev_mgr_start_response_handler;
  result[135] = tgt_vdev_mgr_stop_response_handler;
  result[136] = tgt_vdev_mgr_delete_response_handler;
  result[139] = tgt_vdev_mgr_peer_delete_all_response_handler;
  result[142] = tgt_vdev_mgr_get_response_timer_info;
  result[140] = tgt_vdev_mgr_multi_vdev_restart_resp_handler;
  result[144] = tgt_vdev_mgr_set_max_channel_switch_time;
  result[146] = tgt_vdev_mgr_csa_received_handler;
  result[141] = tgt_psoc_get_wakelock_info;
  result[143] = wlan_vdev_mlme_notify_set_mac_addr_response;
  result[145] = tgt_vdev_mgr_quiet_offload_handler;
  return result;
}
