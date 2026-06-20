__int64 sub_29D644()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2A4618);
  return wlan_mlme_get_4way_hs_offload();
}
