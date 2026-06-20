__int64 __fastcall show_nrrun_cpu_misfit_mask(__int64 a1, __int64 a2)
{
  return (int)scnprintf(a2, 4096, "0x%lx\n", *(_QWORD *)(a1 + 264));
}
