__int64 __fastcall wbuff_stats_debugfs_open(__int64 a1, __int64 a2)
{
  return single_open(a2, wbuff_stats_debugfs_show, *(_QWORD *)(a1 + 696));
}
