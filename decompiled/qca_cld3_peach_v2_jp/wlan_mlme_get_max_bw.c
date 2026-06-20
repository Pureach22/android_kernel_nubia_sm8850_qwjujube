__int64 wlan_mlme_get_max_bw()
{
  int vht_ch_width; // w0

  vht_ch_width = wma_get_vht_ch_width();
  if ( (unsigned int)(vht_ch_width - 1) < 3 )
    return (unsigned int)(vht_ch_width + 1);
  else
    return 1;
}
