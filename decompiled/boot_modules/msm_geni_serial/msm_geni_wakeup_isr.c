__int64 __fastcall msm_geni_wakeup_isr(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  unsigned __int64 v4; // x20
  __int64 v5; // x21
  __int64 v7; // x0
  __int64 v8; // x21
  __int64 v9; // x0

  v2 = *(_QWORD *)(a2 + 968);
  if ( v2 )
  {
    if ( *(_DWORD *)(a2 + 916) )
    {
      v4 = sched_clock(a1);
      ipc_log_string(v2, "%s:start at %llu nsec(%llu usec)\n", "msm_geni_wakeup_isr", v4, v4 / 0x3E8);
    }
    else
    {
      v4 = 0;
    }
  }
  else
  {
    v4 = -22;
  }
  ipc_log_string(*(_QWORD *)(a2 + 944), "%s %d\n", "msm_geni_wakeup_isr", 1);
  _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s %d\n");
  v5 = raw_spin_lock_irqsave(a2);
  if ( *(_DWORD *)(a2 + 1344) )
    goto LABEL_7;
  if ( !*(_QWORD *)(*(_QWORD *)(a2 + 208) + 152LL) )
  {
    ipc_log_string(*(_QWORD *)(a2 + 944), "%s: Unexpected wakeup ISR\n", "msm_geni_wakeup_isr");
    _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s: Unexpected wakeup ISR\n");
LABEL_7:
    raw_spin_unlock_irqrestore(a2, v5);
    return 1;
  }
  *(_DWORD *)(a2 + 1344) = 1;
  queue_delayed_work_on(32, *(_QWORD *)(a2 + 1352), a2 + 1360, 0);
  raw_spin_unlock_irqrestore(a2, v5);
  ipc_log_string(*(_QWORD *)(a2 + 944), "%s: End %d\n", "msm_geni_wakeup_isr", 1);
  _ftrace_dbg(*(_QWORD *)(a2 + 344), "%s: End %d\n");
  v8 = *(_QWORD *)(a2 + 968);
  if ( v8 && v4 && *(_DWORD *)(a2 + 916) )
  {
    v9 = sched_clock(v7);
    ipc_log_string(v8, "%s:took %llu nsec(%llu usec)\n", "msm_geni_wakeup_isr", v9 - v4, (v9 - v4) / 0x3E8);
  }
  return 1;
}
