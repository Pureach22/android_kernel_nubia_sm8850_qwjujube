__int64 __fastcall dp_mon_ops_register_tx_2_0(
        __int64 result,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  __int64 v9; // x29
  __int64 v10; // x30
  _QWORD *v11; // x8

  v11 = *(_QWORD **)(result + 416);
  if ( !v11 )
    return qdf_trace_msg(
             0x45u,
             2u,
             "%s: tx 2.0 ops registration failed",
             a2,
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             "dp_mon_ops_register_tx_2_0",
             v9,
             v10);
  v11[82] = dp_tx_mon_filter_update_2_0;
  v11[32] = dp_tx_mon_process_2_0;
  v11[33] = &dp_tx_mon_get_hal_ring_2_0;
  v11[34] = dp_mon_print_lpc_coc_stats_2_0;
  v11[35] = dp_tx_mon_print_ring_stat_2_0;
  return result;
}
