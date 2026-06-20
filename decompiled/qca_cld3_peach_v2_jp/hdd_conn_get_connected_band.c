__int64 __fastcall hdd_conn_get_connected_band(__int64 a1)
{
  unsigned int v2; // w19
  __int64 result; // x0
  bool is_5ghz_ch_freq; // w8

  if ( (hdd_cm_is_vdev_associated() & 1) != 0 )
    v2 = *(_DWORD *)(a1 + 692);
  else
    v2 = 0;
  if ( wlan_reg_is_24ghz_ch_freq(v2) )
    return 1;
  is_5ghz_ch_freq = wlan_reg_is_5ghz_ch_freq(v2);
  result = 2;
  if ( !is_5ghz_ch_freq )
  {
    if ( wlan_reg_is_6ghz_chan_freq(v2) )
      return 2;
    else
      return 0;
  }
  return result;
}
