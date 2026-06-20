__int64 sub_29D300()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A42D4);
  return wlan_mlme_get_bmps_min_listen_interval();
}
