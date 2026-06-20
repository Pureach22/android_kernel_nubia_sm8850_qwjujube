__int64 __fastcall show_enable_trace(__int64 a1, __int64 a2, __int64 a3)
{
  return (int)scnprintf(a3, 4096, "%u\n", pmu_enable_trace);
}
