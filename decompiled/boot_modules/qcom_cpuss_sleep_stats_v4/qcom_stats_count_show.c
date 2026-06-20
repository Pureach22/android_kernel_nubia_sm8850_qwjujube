__int64 __fastcall qcom_stats_count_show(__int64 a1)
{
  int v2; // w0

  v2 = readl_relaxed(**(_QWORD **)(a1 + 128) + *(unsigned int *)(*(_QWORD *)(a1 + 128) + 8LL));
  seq_printf(a1, "%u\n", v2);
  return 0;
}
