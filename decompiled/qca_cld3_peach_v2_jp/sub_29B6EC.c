__int64 sub_29B6EC()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A26C0);
  return wlan_mlme_get_sta_miracast_mcc_rest_time();
}
