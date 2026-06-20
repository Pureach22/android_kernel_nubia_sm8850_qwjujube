__int64 __fastcall qcom_stats_core_count_open(__int64 a1, __int64 a2)
{
  return single_open(a2, qcom_stats_core_count_show, *(_QWORD *)(a1 + 696));
}
