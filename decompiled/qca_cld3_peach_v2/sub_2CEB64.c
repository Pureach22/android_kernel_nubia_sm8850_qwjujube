__int64 sub_2CEB64()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D5B38);
  return wlan_mlme_get_bmps_max_listen_interval();
}
