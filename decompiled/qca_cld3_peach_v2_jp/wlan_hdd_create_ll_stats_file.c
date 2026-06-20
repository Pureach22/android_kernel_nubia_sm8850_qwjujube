__int64 __fastcall wlan_hdd_create_ll_stats_file(__int64 a1)
{
  if ( debugfs_create_file("ll_stats", 292, *(_QWORD *)(a1 + 52048), *(_QWORD *)(a1 + 32), &fops_ll_stats_debugfs) )
    return 0;
  else
    return 4294967274LL;
}
