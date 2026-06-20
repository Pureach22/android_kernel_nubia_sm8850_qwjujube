__int64 __fastcall sub_2D28F8(__int64 a1, __int64 a2)
{
  char v2; // w25

  if ( (v2 & 0x40) != 0 )
    JUMPOUT(0x2D98CC);
  return wlan_mlme_stats_get_periodic_display_time(a1, a2);
}
