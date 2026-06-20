_QWORD *__fastcall dp_mon_register_tx_pkt_enh_ops_1_0(_QWORD *result)
{
  result[42] = 0;
  result[39] = dp_tx_ppdu_stats_attach_2_0;
  result[40] = dp_tx_ppdu_stats_detach_2_0;
  return result;
}
