__int64 __fastcall lim_update_sta_eht_capable(
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
        __int64 a11,
        __int64 a12)
{
  __int64 v12; // x29
  __int64 v13; // x30
  char v14; // w4

  if ( *(_DWORD *)(a12 + 88) == 1 )
  {
    if ( *(_BYTE *)(a11 + 68) == 1 )
      v14 = *(_BYTE *)(a12 + 10071) & 1;
    else
      v14 = 0;
  }
  else
  {
    v14 = *(_BYTE *)(a12 + 10071);
  }
  *(_BYTE *)(a10 + 256) = v14;
  return qdf_trace_msg(
           0x35u,
           8u,
           "%s: eht_capable: %d",
           a1,
           a2,
           a3,
           a4,
           a5,
           a6,
           a7,
           a8,
           "lim_update_sta_eht_capable",
           v12,
           v13);
}
