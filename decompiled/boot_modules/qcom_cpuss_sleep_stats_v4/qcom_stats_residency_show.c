__int64 __fastcall qcom_stats_residency_show(__int64 a1)
{
  __int64 *v1; // x20
  unsigned int v3; // w0
  __int64 v4; // x8
  __int64 v5; // x9
  __int64 v6; // x20
  unsigned int v7; // w0

  v1 = *(__int64 **)(a1 + 128);
  v3 = readl_relaxed((unsigned int *)(*v1 + *((unsigned int *)v1 + 2) + *((unsigned int *)v1 + 8)));
  v4 = *v1;
  v5 = *((unsigned int *)v1 + 2);
  v6 = v3;
  v7 = readl_relaxed((unsigned int *)(v4 + v5));
  seq_printf(a1, "%llu\n", v7 | (unsigned __int64)(v6 << 32));
  return 0;
}
