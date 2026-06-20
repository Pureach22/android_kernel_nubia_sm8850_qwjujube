__int64 __fastcall wifi_pos_get_rx_ops(
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
  const char *v11; // x2

  if ( a1 )
  {
    v9 = *(_QWORD *)(a1 + 2136);
    if ( v9 )
      return v9 + 376;
    v11 = "%s: rx_ops is NULL";
  }
  else
  {
    v11 = "%s: psoc is null";
  }
  qdf_trace_msg(0x25u, 2u, v11, a2, a3, a4, a5, a6, a7, a8, a9, "wifi_pos_get_rx_ops");
  return 0;
}
