__int64 __fastcall target_if_cp_stats_register_tx_ops(
        _QWORD *a1,
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

  if ( a1 )
  {
    a1[42] = target_if_cp_stats_enable_cstats;
    a1[40] = target_if_infra_cp_stats_req;
    a1[32] = target_if_cp_stats_register_event_handler;
    a1[33] = target_if_cp_stats_unregister_event_handler;
    a1[34] = target_if_cp_stats_register_legacy_event_handler;
    a1[35] = target_if_cp_stats_unregister_legacy_event_handler;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: lmac tx ops is NULL!",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "target_if_cp_stats_register_tx_ops",
      v9,
      v10);
    return 4;
  }
}
