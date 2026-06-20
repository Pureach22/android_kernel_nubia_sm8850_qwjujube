__int64 sub_2D03B8()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D738C);
  return wlan_mlme_get_bss_load_threshold();
}
