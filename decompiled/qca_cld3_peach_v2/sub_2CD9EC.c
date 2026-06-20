__int64 sub_2CD9EC()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D49C0);
  return wlan_mlme_cfg_get_vht_rx_mcs_map();
}
