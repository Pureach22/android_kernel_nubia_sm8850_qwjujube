__int64 mlme_get_vht_ch_width()
{
  int vht_ch_width; // w0
  unsigned int v1; // w8

  vht_ch_width = wma_get_vht_ch_width();
  if ( vht_ch_width == 2 )
    v1 = 3;
  else
    v1 = 2;
  if ( vht_ch_width == 3 )
    return 4;
  else
    return v1;
}
