__int64 sub_2CF884()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2D6858);
  return wlan_mlme_get_roam_info_stats_num();
}
