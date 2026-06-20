__int64 __fastcall target_if_cp_stats_register_legacy_event_handler(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  _QWORD *v9; // x8
  __int64 v10; // x8
  _QWORD *v11; // x19
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  double v20; // d0
  double v21; // d1
  double v22; // d2
  double v23; // d3
  double v24; // d4
  double v25; // d5
  double v26; // d6
  double v27; // d7
  int v28; // w8
  __int64 result; // x0
  unsigned int v30; // w19
  const char *v31; // x2

  if ( !a1 || (v9 = *(_QWORD **)(a1 + 2128)) == nullptr )
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
      "target_if_cp_stats_register_legacy_event_handler");
    return 16;
  }
  v9[36] = target_if_cp_stats_inc_wake_lock_stats;
  v9[37] = target_if_cp_stats_send_stats_req;
  v9[38] = target_if_cp_stats_send_peer_stats_req;
  v9[39] = target_if_set_pdev_stats_update_period;
  v9[41] = target_if_cp_stats_send_big_data_stats_req;
  v10 = *(_QWORD *)(a1 + 2800);
  if ( !v10 || (v11 = *(_QWORD **)(v10 + 16)) == nullptr )
  {
    v30 = 4;
    v31 = "%s: wmi_handle is null";
    goto LABEL_13;
  }
  if ( (unsigned int)wmi_unified_register_event_handler(
                       *(_QWORD **)(v10 + 16),
                       5u,
                       (__int64)target_if_mc_cp_stats_stats_event_handler,
                       0,
                       a2,
                       a3,
                       a4,
                       a5,
                       a6,
                       a7,
                       a8,
                       a9) )
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: Failed to register stats event cb",
      v12,
      v13,
      v14,
      v15,
      v16,
      v17,
      v18,
      v19,
      "target_if_mc_cp_stats_register_event_handler");
  if ( (unsigned int)wmi_unified_register_event_handler(
                       v11,
                       0xA7u,
                       (__int64)target_if_mc_cp_stats_peer_stats_info_event_handler,
                       0,
                       v12,
                       v13,
                       v14,
                       v15,
                       v16,
                       v17,
                       v18,
                       v19) )
    qdf_trace_msg(
      0x62u,
      2u,
      "%s: Failed to register peer stats info event cb",
      v20,
      v21,
      v22,
      v23,
      v24,
      v25,
      v26,
      v27,
      "target_if_mc_cp_stats_register_event_handler");
  v28 = wmi_unified_register_event_handler(
          v11,
          0xF0u,
          (__int64)target_if_mc_cp_stats_big_data_stats_event_handler,
          0,
          v20,
          v21,
          v22,
          v23,
          v24,
          v25,
          v26,
          v27);
  result = 0;
  if ( v28 )
  {
    v30 = 0;
    v31 = "%s: Failed to register big data stats info event cb";
LABEL_13:
    qdf_trace_msg(0x62u, 2u, v31, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_mc_cp_stats_register_event_handler");
    return v30;
  }
  return result;
}
