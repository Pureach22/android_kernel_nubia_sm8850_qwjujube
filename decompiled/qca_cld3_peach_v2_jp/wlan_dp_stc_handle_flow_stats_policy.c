__int64 __fastcall wlan_dp_stc_handle_flow_stats_policy(unsigned int a1, unsigned int a2)
{
  __int64 v4; // x21
  double v5; // d0
  double v6; // d1
  double v7; // d2
  double v8; // d3
  double v9; // d4
  double v10; // d5
  double v11; // d6
  double v12; // d7

  v4 = *(_QWORD *)(dp_get_context() + 2936);
  if ( !v4 )
    return 11;
  qdf_trace_msg(
    0x45u,
    5u,
    "%s: STC: type %d action %d",
    v5,
    v6,
    v7,
    v8,
    v9,
    v10,
    v11,
    v12,
    "wlan_dp_stc_handle_flow_stats_policy",
    a1,
    a2);
  if ( a1 == 2 )
  {
    if ( a2 != 1 )
    {
      if ( !a2 )
      {
        *(_BYTE *)(v4 + 9) = 1;
        return 0;
      }
      return 4;
    }
    *(_BYTE *)(v4 + 9) = 0;
    return 0;
  }
  else
  {
    if ( a1 != 1 )
      return 0;
    if ( a2 != 1 )
    {
      if ( !a2 )
      {
        *(_BYTE *)(v4 + 8) = 1;
        return 0;
      }
      return 4;
    }
    *(_BYTE *)(v4 + 8) = 0;
    return 0;
  }
}
