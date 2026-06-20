__int64 ddr_stats_get_ss_count()
{
  if ( *(_BYTE *)(*(_QWORD *)(drv + 8) + 35LL) )
    return 28;
  else
    return 4294967201LL;
}
