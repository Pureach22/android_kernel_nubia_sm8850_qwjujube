__int64 sub_2CEC68()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D5C3C);
  return wlan_mlme_get_auto_bmps_timer_value();
}
