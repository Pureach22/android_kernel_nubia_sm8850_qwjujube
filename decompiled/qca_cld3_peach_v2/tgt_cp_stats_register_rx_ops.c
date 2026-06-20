_QWORD *__fastcall tgt_cp_stats_register_rx_ops(_QWORD *result)
{
  result[22] = tgt_mc_cp_stats_process_stats_event;
  result[23] = tgt_mc_cp_stats_process_infra_stats_event;
  result[24] = tgt_mc_cp_stats_process_big_data_stats_event;
  return result;
}
