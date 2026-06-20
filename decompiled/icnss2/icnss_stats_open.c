__int64 __fastcall icnss_stats_open(__int64 a1, __int64 a2)
{
  return single_open(a2, icnss_stats_show, *(_QWORD *)(a1 + 696));
}
