__int64 __fastcall wlansap_filter_non_2ghz_freq(
        __int64 result,
        _WORD *a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9,
        double a10)
{
  __int64 v11; // x20
  __int64 v12; // x21
  unsigned __int64 v13; // x22

  if ( !a2 )
    return qdf_trace_msg(
             0x39u,
             2u,
             "%s: NULL parameters",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "wlansap_filter_non_2ghz_freq");
  if ( *a2 )
  {
    v11 = result;
    v12 = 0;
    v13 = 0;
    do
    {
      result = wlan_reg_is_24ghz_ch_freq(*(_DWORD *)(v11 + 4 * v13));
      if ( (result & 1) != 0 )
        *(_DWORD *)(v11 + 4 * v12++) = *(_DWORD *)(v11 + 4 * v13);
      ++v13;
    }
    while ( v13 < (unsigned __int16)*a2 );
  }
  else
  {
    LOWORD(v12) = 0;
  }
  *a2 = v12;
  return result;
}
