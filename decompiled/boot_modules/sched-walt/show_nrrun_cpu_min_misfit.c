__int64 __fastcall show_nrrun_cpu_min_misfit(__int64 a1, __int64 a2)
{
  return (int)scnprintf(a2, 4096, "%u\n", *(_DWORD *)(a1 + 272));
}
