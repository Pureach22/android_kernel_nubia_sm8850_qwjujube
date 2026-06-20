__int64 __fastcall lim_get_bpcc_from_mlo_ie(
        __int64 a1,
        _BYTE *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v10; // x29
  __int64 v11; // x30

  if ( !a1 )
    return 4;
  if ( *(_BYTE *)(a1 + 3437) != 1 || (*(_WORD *)(a1 + 3438) & 0x20) == 0 )
  {
    *a2 = 0;
    return 4;
  }
  *a2 = *(_BYTE *)(a1 + 3448);
  qdf_trace_msg(0x35u, 8u, "%s: mlie bpcc %d", a3, a4, a5, a6, a7, a8, a9, a10, "lim_get_bpcc_from_mlo_ie", v10, v11);
  return 0;
}
