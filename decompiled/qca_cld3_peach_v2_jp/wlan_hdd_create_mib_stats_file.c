__int64 __fastcall wlan_hdd_create_mib_stats_file(__int64 a1)
{
  if ( debugfs_create_file("mib_stats", 292, *(_QWORD *)(a1 + 52048), *(_QWORD *)(a1 + 32), &fops_mib_stats) )
    return 0;
  else
    return 4294967274LL;
}
