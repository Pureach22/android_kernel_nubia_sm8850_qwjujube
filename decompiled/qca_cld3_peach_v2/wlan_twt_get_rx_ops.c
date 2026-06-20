__int64 __fastcall wlan_twt_get_rx_ops(
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
  __int64 v9; // x29
  __int64 v10; // x30
  __int64 v11; // x8

  if ( a1 )
  {
    v11 = *(_QWORD *)(a1 + 2136);
    if ( v11 )
      return v11 + 1312;
  }
  qdf_trace_msg(0x96u, 2u, "%s: rx_ops is NULL", a2, a3, a4, a5, a6, a7, a8, a9, "wlan_twt_get_rx_ops", v9, v10);
  return 0;
}
