__int64 __fastcall policy_mgr_allow_multiple_sta_connections(
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
  __int64 v10; // x0
  double v11; // d0
  double v12; // d1
  double v13; // d2
  double v14; // d3
  double v15; // d4
  double v16; // d5
  double v17; // d6
  double v18; // d7
  __int64 v20; // x20

  if ( a1 && (v9 = *(_QWORD *)(a1 + 2800)) != 0 && (v10 = *(_QWORD *)(v9 + 16)) != 0 )
  {
    if ( (wmi_service_enabled(v10, 0xABu, a2, a3, a4, a5, a6, a7, a8, a9) & 1) != 0 )
      return 1;
    v20 = jiffies;
    if ( policy_mgr_allow_multiple_sta_connections___last_ticks - jiffies + 125 < 0 )
    {
      qdf_trace_msg(
        0x4Fu,
        8u,
        "%s: STA+STA is not supported",
        v11,
        v12,
        v13,
        v14,
        v15,
        v16,
        v17,
        v18,
        "policy_mgr_allow_multiple_sta_connections");
      policy_mgr_allow_multiple_sta_connections___last_ticks = v20;
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x4Fu,
      8u,
      "%s: Invalid WMI handle",
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      "policy_mgr_allow_multiple_sta_connections");
  }
  return 0;
}
