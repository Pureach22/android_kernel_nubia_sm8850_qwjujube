_QWORD *__fastcall target_if_dp_register_tx_ops(_QWORD *result)
{
  *result = target_if_dp_arp_stats_register_event_handler;
  result[1] = target_if_dp_arp_stats_unregister_event_handler;
  result[2] = target_if_dp_get_arp_req_stats;
  result[3] = target_if_dp_set_arp_req_stats;
  result[5] = target_if_dp_lro_config_cmd;
  result[6] = target_if_dp_send_dhcp_ind;
  result[7] = target_if_dp_active_traffic_map;
  result[8] = target_if_dp_send_opm_stats_cmd;
  return result;
}
