__int64 sub_2CDBD4()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D4BA8);
  return wlan_mlme_cfg_get_vht_basic_mcs_set();
}
