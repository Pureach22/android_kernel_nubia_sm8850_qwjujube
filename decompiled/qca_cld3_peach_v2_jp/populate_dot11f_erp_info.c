__int64 __fastcall populate_dot11f_erp_info(
        double a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        __int64 a9,
        _BYTE *a10,
        __int64 a11)
{
  __int64 v11; // x29
  __int64 v12; // x30

  if ( !a11 || *(_DWORD *)(a11 + 168) )
    return 0;
  *a10 = 1;
  if ( (*(_WORD *)(a11 + 432) & 0x200) != 0 )
  {
    if ( *(_BYTE *)(a11 + 437) )
      a10[1] |= 3u;
    if ( *(_BYTE *)(a11 + 1225) )
      a10[1] |= 2u;
    if ( !*(_BYTE *)(a11 + 448) && *(_BYTE *)(a11 + 7160) )
      return 0;
    a10[1] |= 4u;
    return 0;
  }
  else
  {
    qdf_trace_msg(
      0x35u,
      2u,
      "%s: 11B protection not enabled. Not populating ERP IE %d",
      a1,
      a2,
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      "populate_dot11f_erp_info",
      0,
      v11,
      v12);
    return 0;
  }
}
