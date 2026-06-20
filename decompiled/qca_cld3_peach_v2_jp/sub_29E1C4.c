__int64 sub_29E1C4()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A5198);
  return wlan_mlme_get_idle_roam_band();
}
