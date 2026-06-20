__int64 sub_2A18D4()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A88A8);
  return wlan_mlme_get_sta_keep_alive_period();
}
