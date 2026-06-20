_QWORD *__fastcall target_if_ll_sap_register_tx_ops(_QWORD *result)
{
  *result = target_if_send_audio_transport_switch_resp;
  result[1] = target_if_send_oob_connect_request;
  result[2] = target_if_get_tsf_stats_for_csa;
  return result;
}
