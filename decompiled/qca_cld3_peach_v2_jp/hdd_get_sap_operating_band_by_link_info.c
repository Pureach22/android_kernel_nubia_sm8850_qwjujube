__int64 __fastcall hdd_get_sap_operating_band_by_link_info(_DWORD *a1)
{
  unsigned int v1; // w19
  __int64 result; // x0
  bool is_5ghz_ch_freq; // w8

  if ( (*(_DWORD *)(*(_QWORD *)a1 + 40LL) & 0xFFFFFFFD) != 1 )
    return 3;
  v1 = a1[538];
  if ( wlan_reg_is_24ghz_ch_freq(v1) )
    return 1;
  is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(v1);
  result = 2;
  if ( !is_5ghz_ch_freq )
  {
    if ( wlan_reg_is_6ghz_chan_freq(v1) )
      return 2;
    else
      return 3;
  }
  return result;
}
