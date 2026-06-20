__int64 sub_29EBA8()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A5B7C);
  return wlan_mlme_get_bss_load_threshold();
}
