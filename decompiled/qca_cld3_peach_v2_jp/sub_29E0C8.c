__int64 sub_29E0C8()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A509C);
  return wlan_mlme_get_idle_roam_inactive_time();
}
