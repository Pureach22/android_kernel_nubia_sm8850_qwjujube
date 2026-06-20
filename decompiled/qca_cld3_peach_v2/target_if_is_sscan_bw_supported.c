__int64 __fastcall target_if_is_sscan_bw_supported(
        __int64 a1,
        unsigned int a2,
        unsigned int a3,
        unsigned int a4,
        _BYTE *a5,
        char a6,
        double a7,
        double a8,
        double a9,
        double a10,
        double a11,
        double a12,
        double a13,
        double a14)
{
  __int64 v14; // x29
  __int64 v15; // x30
  unsigned int v17; // w9

  *a5 = 0;
  if ( a4 < 8 )
  {
    if ( (a3 != 4) == (a6 & 1) )
    {
      return 0;
    }
    else
    {
      if ( a3 > 7 )
        LOBYTE(v17) = -1;
      else
        v17 = dword_B354A8[a3];
      *a5 = (*(_DWORD *)(a1 + 36LL * a2 + 4LL * a4 + 1976) >> v17) & 1;
      return 0;
    }
  }
  else
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Invalid channel width %d",
      a7,
      a8,
      a9,
      a10,
      a11,
      a12,
      a13,
      a14,
      "target_if_is_sscan_bw_supported",
      a4,
      v14,
      v15);
    return 4;
  }
}
