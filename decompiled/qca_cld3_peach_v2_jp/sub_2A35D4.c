__int64 sub_2A35D4()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2AA5A8);
  return ucfg_mlme_stats_get_periodic_display_time();
}
