__int64 sub_29EC50()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A5C24);
  return wlan_mlme_get_bss_load_sample_time();
}
