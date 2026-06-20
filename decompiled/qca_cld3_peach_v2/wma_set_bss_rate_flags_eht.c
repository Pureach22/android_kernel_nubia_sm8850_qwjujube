__int64 __fastcall wma_set_bss_rate_flags_eht(
        _DWORD *a1,
        __int64 a2,
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
  int v12; // w8
  int v13; // w8
  int v15; // w9

  if ( *(_BYTE *)(a2 + 868) != 1 )
    return 11;
  v12 = *(_DWORD *)(a2 + 852);
  if ( v12 == 7 )
  {
    v13 = 253952;
  }
  else if ( (unsigned int)(v12 - 3) >= 2 )
  {
    if ( v12 )
      v15 = 24576;
    else
      v15 = 0x2000;
    if ( v12 == 2 )
      v13 = 57344;
    else
      v13 = v15;
  }
  else
  {
    v13 = 122880;
  }
  *a1 |= v13;
  qdf_trace_msg(
    0x36u,
    8u,
    "%s: ehe_capable %d rate_flags 0x%x",
    a3,
    a4,
    a5,
    a6,
    a7,
    a8,
    a9,
    a10,
    "wma_set_bss_rate_flags_eht",
    *(unsigned __int8 *)(a2 + 868),
    v10,
    v11);
  return 0;
}
