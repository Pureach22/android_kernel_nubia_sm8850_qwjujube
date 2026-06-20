_QWORD *__fastcall target_if_wifi_pos_register_tx_ops(_QWORD *result)
{
  result[98] = target_if_wifi_pos_register_events;
  result[99] = target_if_wifi_pos_deregister_events;
  result[101] = target_if_wifi_pos_convert_pdev_id_host_to_target;
  result[102] = target_if_wifi_pos_convert_pdev_id_target_to_host;
  result[103] = target_if_wifi_pos_get_vht_ch_width;
  result[100] = target_if_wifi_pos_oem_data_req;
  result[104] = target_if_wifi_pos_parse_measreq_chan_info;
  result[105] = target_if_wifi_pos_send_rtt_pasn_auth_status;
  result[106] = target_if_wifi_pos_send_rtt_pasn_deauth;
  return result;
}
