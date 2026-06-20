__int64 __fastcall walt_get_cpus_in_state1(__int64 *a1)
{
  __int64 v2; // x9

  if ( (walt_disabled & 1) != 0 )
    return 4294967285LL;
  v2 = *(_QWORD *)(sched_cluster + 24) | _cpu_partial_halt_mask;
  *a1 = v2;
  *a1 = (unsigned int)v2 & ~(_DWORD)_cpu_halt_mask;
  return 0;
}
