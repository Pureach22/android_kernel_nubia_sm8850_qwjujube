__int64 sub_2CF980()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D6954);
  return wlan_mlme_get_idle_roam_min_rssi();
}
