__int64 __fastcall show_active_cpus(__int64 a1, __int64 a2)
{
  int v3; // w0

  v3 = _sw_hweight64(*(_DWORD *)(a1 + 80) & (unsigned int)~(LODWORD(_cpu_partial_halt_mask[0])
                                                          | LODWORD(_cpu_halt_mask[0])));
  return (int)scnprintf(a2, 4096, "%u\n", v3);
}
