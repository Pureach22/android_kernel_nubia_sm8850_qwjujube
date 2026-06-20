__int64 __fastcall qlpmm_get_adsp_clks_stats_open(__int64 a1, __int64 a2)
{
  return single_open(a2, qlpmm_get_adsp_clks_stats_show, *(_QWORD *)(a1 + 696));
}
