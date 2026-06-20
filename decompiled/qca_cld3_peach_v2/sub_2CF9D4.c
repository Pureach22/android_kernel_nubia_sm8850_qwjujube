__int64 sub_2CF9D4()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D69A8);
  return wlan_mlme_get_idle_roam_band();
}
