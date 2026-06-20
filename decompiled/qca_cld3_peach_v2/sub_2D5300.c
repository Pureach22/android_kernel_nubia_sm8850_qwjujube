__int64 sub_2D5300()
{
  char v0; // w25

  if ( (v0 & 0x40) != 0 )
    JUMPOUT(0x2DC2D4);
  return ucfg_mlme_stats_get_periodic_display_time();
}
