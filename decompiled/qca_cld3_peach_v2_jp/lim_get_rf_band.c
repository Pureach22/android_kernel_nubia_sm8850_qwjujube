__int64 __fastcall lim_get_rf_band(unsigned int a1)
{
  if ( wlan_reg_is_6ghz_chan_freq(a1) )
    return 2;
  if ( wlan_reg_is_5ghz_ch_freq(a1) )
    return 1;
  if ( wlan_reg_is_24ghz_ch_freq(a1) )
    return 0;
  return 3;
}
