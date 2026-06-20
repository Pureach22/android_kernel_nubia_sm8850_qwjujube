__int64 __fastcall lim_get_basic_rates(__int64 a1, unsigned int a2)
{
  bool is_24ghz_ch_freq; // w20
  __int64 result; // x0

  is_24ghz_ch_freq = wlan_reg_is_24ghz_ch_freq(a2);
  if ( is_24ghz_ch_freq )
    return wlan_populate_basic_rates(a1, !is_24ghz_ch_freq, 1);
  result = wlan_reg_is_5ghz_ch_freq(a2);
  if ( (result & 1) != 0 )
    return wlan_populate_basic_rates(a1, !is_24ghz_ch_freq, 1);
  return result;
}
