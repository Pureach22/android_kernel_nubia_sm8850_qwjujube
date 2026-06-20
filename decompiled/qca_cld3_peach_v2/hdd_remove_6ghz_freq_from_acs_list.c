__int64 __fastcall hdd_remove_6ghz_freq_from_acs_list(
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
  __int64 result; // x0
  unsigned __int64 v13; // x22
  unsigned __int16 v14; // w21
  __int64 v15; // x9

  result = qdf_trace_msg(
             0x33u,
             8u,
             "%s: Remove 6 GHz channels from ACS list",
             a3,
             a4,
             a5,
             a6,
             a7,
             a8,
             a9,
             a10,
             "hdd_remove_6ghz_freq_from_acs_list");
  if ( *a2 )
  {
    v13 = 0;
    v14 = 0;
    do
    {
      result = wlan_reg_is_6ghz_chan_freq(*(_DWORD *)(a1 + 4 * v13));
      if ( (result & 1) == 0 )
      {
        v15 = v14++;
        *(_DWORD *)(a1 + 4 * v15) = *(_DWORD *)(a1 + 4 * v13);
      }
      ++v13;
    }
    while ( v13 < (unsigned __int8)*a2 );
  }
  else
  {
    LOBYTE(v14) = 0;
  }
  *a2 = v14;
  return result;
}
