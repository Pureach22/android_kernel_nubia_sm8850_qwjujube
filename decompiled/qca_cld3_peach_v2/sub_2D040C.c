__int64 sub_2D040C()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D73E0);
  return wlan_mlme_get_bss_load_alpha();
}
