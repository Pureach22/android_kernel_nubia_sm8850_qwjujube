__int64 sub_29EA58()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A5A2C);
  return wlan_mlme_get_mawc_roam_ap_rssi_threshold();
}
