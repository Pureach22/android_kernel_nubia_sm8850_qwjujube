__int64 sub_29D458()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A442C);
  return wlan_mlme_get_auto_bmps_timer_value();
}
