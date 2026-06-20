__int64 __fastcall cnss_stats_open(__int64 a1, __int64 a2)
{
  return single_open(a2, cnss_stats_show, *(_QWORD *)(a1 + 696));
}
