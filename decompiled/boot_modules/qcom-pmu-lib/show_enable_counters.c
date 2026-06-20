__int64 __fastcall show_enable_counters(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%u\n", (pmu_counters_enabled & 1) == 0);
}
