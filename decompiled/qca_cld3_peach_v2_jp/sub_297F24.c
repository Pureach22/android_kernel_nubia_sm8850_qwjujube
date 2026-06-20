__int64 sub_297F24()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x29EEF8);
  return wlan_mlme_cfg_get_he_ul_mumimo();
}
