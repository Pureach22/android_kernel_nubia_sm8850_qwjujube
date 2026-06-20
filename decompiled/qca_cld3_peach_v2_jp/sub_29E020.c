__int64 sub_29E020()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A4FF4);
  return wlan_mlme_get_idle_roam_rssi_delta();
}
