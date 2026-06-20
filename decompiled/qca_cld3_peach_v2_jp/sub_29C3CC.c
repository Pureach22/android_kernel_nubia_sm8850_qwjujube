__int64 sub_29C3CC()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A33A0);
  return wlan_mlme_cfg_get_vht_tx_mcs_map();
}
