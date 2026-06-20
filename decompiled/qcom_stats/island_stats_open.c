__int64 __fastcall island_stats_open(__int64 a1, __int64 a2)
{
  return single_open(a2, island_stats_show, *(_QWORD *)(a1 + 696));
}
