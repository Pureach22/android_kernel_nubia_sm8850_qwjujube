__int64 __fastcall wlan_spectral_is_mode_disabled_pdev(
        __int64 a1,
        int a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  unsigned int v11; // w8

  if ( !a1 )
  {
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: pdev is NULL!",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_spectral_is_mode_disabled_pdev");
    return 1;
  }
  if ( a2 != 1 )
  {
    if ( !a2 )
      return (*(unsigned __int8 *)(a1 + 16) >> 4) & 1;
    qdf_trace_msg(
      0x56u,
      2u,
      "%s: Invalid Spectral scan mode %d",
      a3,
      a4,
      a5,
      a6,
      a7,
      a8,
      a9,
      a10,
      "wlan_spectral_is_mode_disabled_pdev");
    return 1;
  }
  v11 = *(_DWORD *)(a1 + 16);
  if ( (~v11 & 0xE0) != 0 )
    return 0;
  else
    return (v11 >> 8) & 1;
}
