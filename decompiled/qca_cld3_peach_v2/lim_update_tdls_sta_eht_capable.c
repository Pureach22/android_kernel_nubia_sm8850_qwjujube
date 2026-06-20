__int64 __fastcall lim_update_tdls_sta_eht_capable(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        __int64 a10,
        __int64 a11)
{
  __int64 v11; // x29
  __int64 v12; // x30

  if ( *(_BYTE *)(a11 + 356) == 4 && !*(_BYTE *)(a11 + 932) )
    *(_BYTE *)(a10 + 256) = 0;
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: tdls eht_capable: %d",
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           "lim_update_tdls_sta_eht_capable",
           *(unsigned __int8 *)(a10 + 256),
           v11,
           v12);
}
