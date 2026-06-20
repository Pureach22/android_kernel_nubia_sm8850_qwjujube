__int64 __fastcall epping_timer_expire(
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
  if ( !a1 )
    return qdf_trace_msg(0x33u, 1u, "%s: netdev = NULL", a2, a3, a4, a5, a6, a7, a8, a9, "epping_timer_expire");
  *(_DWORD *)(a1 + 2816) = 0;
  return epping_tx_timer_expire(a1 + 2688, a2, a3, a4, a5, a6, a7, a8, a9);
}
