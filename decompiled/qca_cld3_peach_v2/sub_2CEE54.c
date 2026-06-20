__int64 sub_2CEE54()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D5E28);
  return wlan_mlme_get_4way_hs_offload();
}
