__int64 __fastcall ucfg_cm_get_connected_band(
        __int64 a1,
        double a2,
        double a3,
        double a4,
        double a5,
        double a6,
        double a7,
        double a8,
        double a9)
{
  unsigned int v10; // w19
  __int64 result; // x0
  char is_5ghz_ch_freq; // w8

  if ( cm_is_vdev_connected(a1, a2, a3, a4, a5, a6, a7, a8, a9) )
    v10 = **(unsigned __int16 **)(a1 + 32);
  else
    v10 = 0;
  if ( (wlan_reg_is_24ghz_ch_freq(v10) & 1) != 0 )
    return 1;
  is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(v10);
  result = 2;
  if ( (is_5ghz_ch_freq & 1) == 0 )
  {
    if ( (wlan_reg_is_6ghz_chan_freq(v10) & 1) != 0 )
      return 2;
    else
      return 0;
  }
  return result;
}
