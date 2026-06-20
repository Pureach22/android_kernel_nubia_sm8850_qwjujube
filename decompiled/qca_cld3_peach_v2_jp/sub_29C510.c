__int64 sub_29C510()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A34E4);
  return wlan_mlme_cfg_get_vht_basic_mcs_set();
}
