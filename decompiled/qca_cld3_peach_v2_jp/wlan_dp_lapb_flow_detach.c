__int64 __fastcall wlan_dp_lapb_flow_detach(__int64 a1)
{
  __int64 v1; // x29
  __int64 v2; // x30
  double v3; // d0
  double v4; // d1
  double v5; // d2
  double v6; // d3
  double v7; // d4
  double v8; // d5
  double v9; // d6
  double v10; // d7
  __int64 v12; // [xsp+8h] [xbp-8h]

  if ( *(_BYTE *)(a1 + 19792) == 1 )
  {
    v12 = v2;
    *(_QWORD *)(a1 + 19800) = 0;
    *(_BYTE *)(a1 + 19792) = 0;
    hrtimer_cancel(a1 + 19816);
    qdf_trace_msg(0x45u, 5u, "%s: LAPB detach", v3, v4, v5, v6, v7, v8, v9, v10, "wlan_dp_lapb_flow_detach", v1, v12);
  }
  return 0;
}
