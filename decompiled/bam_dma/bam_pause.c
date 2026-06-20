__int64 __fastcall bam_pause(__int64 a1)
{
  __int64 v1; // x21
  __int64 v3; // x0
  __int64 result; // x0
  __int64 v5; // x0
  unsigned int *v6; // x8
  __int64 v7; // x20
  __int64 v8; // x0
  __int64 v9; // x19

  v1 = *(_QWORD *)(a1 + 256);
  v3 = *(_QWORD *)(v1 + 536);
  if ( v3 )
    ipc_log_string(v3, "%s chan id:%d\n", "bam_pause", *(_DWORD *)(a1 + 264));
  _ftrace_dbg(*(_QWORD *)(v1 + 8), "%s chan id:%d\n");
  result = _pm_runtime_resume(*(_QWORD *)(v1 + 8), 4);
  if ( (result & 0x80000000) == 0 )
  {
    v5 = raw_spin_lock_irqsave(a1 + 160);
    v6 = *(unsigned int **)(v1 + 440);
    v7 = v5;
    writel_relaxed(
      1,
      *(_QWORD *)v1
    + v6[60]
    + v6[61] * *(_DWORD *)(a1 + 264)
    + v6[62] * *(_DWORD *)(a1 + 264)
    + (unsigned __int64)(*(_DWORD *)(v1 + 424) * v6[63]));
    *(_DWORD *)(a1 + 368) = 1;
    v8 = raw_spin_unlock_irqrestore(a1 + 160, v7);
    v9 = *(_QWORD *)(v1 + 8);
    *(_QWORD *)(v9 + 520) = ktime_get_mono_fast_ns(v8);
    _pm_runtime_suspend(*(_QWORD *)(v1 + 8), 13);
    return 0;
  }
  return result;
}
