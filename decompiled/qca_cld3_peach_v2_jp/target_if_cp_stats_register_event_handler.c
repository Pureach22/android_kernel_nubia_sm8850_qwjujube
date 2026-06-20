__int64 __fastcall target_if_cp_stats_register_event_handler(
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
  __int64 v9; // x8
  _QWORD *v10; // x20
  unsigned int v11; // w0
  double v12; // d0
  double v13; // d1
  double v14; // d2
  double v15; // d3
  double v16; // d4
  double v17; // d5
  double v18; // d6
  double v19; // d7
  unsigned int v20; // w19
  const char *v21; // x2

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 2800);
    if ( v9 && (v10 = *(_QWORD **)(v9 + 16)) != nullptr )
    {
      v11 = wmi_unified_register_event_handler(
              *(_QWORD **)(v9 + 16),
              0xEEu,
              (__int64)target_if_infra_cp_stats_event_handler,
              0,
              a2,
              a3,
              a4,
              a5,
              a6,
              a7,
              a8,
              a9);
      if ( v11 )
      {
        v20 = v11;
        qdf_trace_msg(
          0x62u,
          2u,
          "%s: Failed to register for pdev_cp_fwstats_event",
          v12,
          v13,
          v14,
          v15,
          v16,
          v17,
          v18,
          v19,
          "target_if_cp_stats_infra_register_event_handler");
        v21 = "%s: Failed to register for pdev_cp_fwstats_event";
      }
      else
      {
        v20 = wmi_unified_register_event_handler(
                v10,
                0xC5u,
                (__int64)target_if_twt_session_params_event_handler,
                0,
                v12,
                v13,
                v14,
                v15,
                v16,
                v17,
                v18,
                v19);
        if ( !v20 )
          return v20;
        v21 = "%s: Failed to register twt session stats event";
      }
    }
    else
    {
      v20 = 4;
      v21 = "%s: wmi_handle is null";
    }
  }
  else
  {
    v20 = 4;
    v21 = "%s: PSOC is NULL!";
  }
  qdf_trace_msg(0x62u, 2u, v21, a2, a3, a4, a5, a6, a7, a8, a9, "target_if_cp_stats_register_event_handler");
  return v20;
}
