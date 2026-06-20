_QWORD *__fastcall os_if_dp_register_txrx_callbacks(_QWORD *result)
{
  result[15] = 0;
  result[16] = 0;
  result[7] = osif_dp_rx_pkt_to_nw;
  result[8] = osif_dp_rx_napi_gro_flush;
  result[9] = osif_dp_rx_thread_napi_gro_flush;
  result[10] = osif_dp_rx_napi_gro_receive;
  result[11] = osif_dp_lro_rx;
  result[13] = osif_dp_register_rx_offld_flush_cb;
  result[14] = osif_dp_rx_check_qdisc_configured;
  return result;
}
