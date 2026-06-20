__int64 sub_64B3AC()
{
  int v0; // w17

  if ( (v0 & 0x80000) == 0 )
    JUMPOUT(0x645E70);
  return wlan_twt_get_rx_ops();
}
