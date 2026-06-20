__int64 sub_2D0214()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D71E8);
  return wlan_mlme_get_mawc_roam_traffic_threshold();
}
