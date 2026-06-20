__int64 __fastcall target_if_cp_stats_unregister_legacy_event_handler(
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

  if ( a1 && (v9 = *(_QWORD **)(a1 + 2128)) != nullptr )
  {
    v9[41] = 0;
    v9[36] = 0;
    v9[37] = 0;
    v9[38] = 0;
    v9[39] = 0;
    v10 = *(_QWORD *)(a1 + 2800);
    if ( v10 && (v11 = *(_QWORD **)(v10 + 16)) != nullptr )
    {
      wmi_unified_unregister_event_handler(*(_QWORD **)(v10 + 16), 0xF0u, a2, a3, a4, a5, a6, a7, a8, a9);
      wmi_unified_unregister_event_handler(v11, 0xA7u, v12, v13, v14, v15, v16, v17, v18, v19);
      wmi_unified_unregister_event_handler(v11, 5u, v20, v21, v22, v23, v24, v25, v26, v27);
      return 0;
    }
    else
    {
      qdf_trace_msg(
        0x62u,
        2u,
        "%s: wmi_handle is null",
        a2,
        a3,
        a4,
        a5,
        a6,
        a7,
        a8,
        a9,
        "target_if_mc_cp_stats_unregister_event_handler");
      return 4;
    }
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
      "target_if_cp_stats_unregister_legacy_event_handler");
    return 16;
  }
}
