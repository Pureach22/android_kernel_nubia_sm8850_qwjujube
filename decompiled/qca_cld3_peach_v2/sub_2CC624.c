__int64 sub_2CC624()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D35F8);
  return wlan_mlme_get_sta_miracast_mcc_rest_time();
}
