__int64 wlan_mlme_get_max_bw()
{
  unsigned int v0; // w8

  v0 = wma_get_eht_ch_width() - 1;
  if ( v0 > 3 )
    return 1;
  else
    return dword_B35928[v0];
}
