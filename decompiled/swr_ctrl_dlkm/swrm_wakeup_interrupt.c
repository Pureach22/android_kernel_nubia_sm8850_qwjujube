__int64 __fastcall swrm_wakeup_interrupt(__int64 a1, __int64 a2)
{
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x20
  int v7; // w8
  __int64 result; // x0
  void *v9; // x0
  __int64 irq_data; // x0
  __int64 v11; // x20

  if ( !a2 || !*(_QWORD *)(a2 + 8512) )
  {
    result = __ratelimit(&swrm_wakeup_interrupt__rs, "swrm_wakeup_interrupt");
    if ( !(_DWORD)result )
      return result;
    v9 = &unk_10AC2;
LABEL_18:
    printk(v9, "swrm_wakeup_interrupt");
    return 0;
  }
  mutex_lock(a2 + 8736);
  if ( *(_DWORD *)(a2 + 15336) == 4 || (*(_BYTE *)(a2 + 15748) & 1) == 0 )
  {
    if ( *(int *)(a2 + 9124) >= 1 )
    {
      irq_data = irq_get_irq_data();
      if ( !irq_data )
      {
        if ( (unsigned int)__ratelimit(&swrm_wakeup_interrupt__rs_31, "swrm_wakeup_interrupt") )
          printk(&unk_1118B, "swrm_wakeup_interrupt");
        mutex_unlock(a2 + 8736);
        return 0;
      }
      v11 = irq_data;
      mutex_lock(a2 + 8928);
      if ( (*(_BYTE *)(*(_QWORD *)(v11 + 16) + 2LL) & 1) == 0 )
        disable_irq_nosync(*(unsigned int *)(a2 + 9124));
      mutex_unlock(a2 + 8928);
    }
    mutex_unlock(a2 + 8736);
    return 1;
  }
  mutex_unlock(a2 + 8736);
  if ( (swrm_lock_sleep(a2) & 1) == 0 )
  {
    if ( (unsigned int)__ratelimit(&swrm_wakeup_interrupt__rs_33, "swrm_wakeup_interrupt") )
      dev_err(*(_QWORD *)(a2 + 8512), "%s Failed to hold suspend\n", "swrm_wakeup_interrupt");
    return 1;
  }
  if ( *(int *)(a2 + 9124) < 1 )
    goto LABEL_11;
  v3 = irq_get_irq_data();
  if ( v3 )
  {
    v4 = v3;
    mutex_lock(a2 + 8928);
    if ( (*(_BYTE *)(*(_QWORD *)(v4 + 16) + 2LL) & 1) == 0 )
      disable_irq_nosync(*(unsigned int *)(a2 + 9124));
    mutex_unlock(a2 + 8928);
LABEL_11:
    v5 = _pm_runtime_resume(*(_QWORD *)(a2 + 8512), 4);
    v6 = *(_QWORD *)(a2 + 8512);
    *(_QWORD *)(v6 + 520) = ktime_get_mono_fast_ns(v5);
    _pm_runtime_suspend(*(_QWORD *)(a2 + 8512), 13);
    mutex_lock(a2 + 8880);
    v7 = *(_DWORD *)(a2 + 15832) - 1;
    *(_DWORD *)(a2 + 15832) = v7;
    if ( !v7 )
    {
      if ( *(_DWORD *)(a2 + 15800) == 1 )
        *(_DWORD *)(a2 + 15800) = 0;
      cpu_latency_qos_update_request(a2 + 15752, 0xFFFFFFFFLL);
      pm_relax(*(_QWORD *)(a2 + 8512));
    }
    mutex_unlock(a2 + 8880);
    _wake_up(a2 + 15808, 3, 0, 0);
    return 1;
  }
  result = __ratelimit(&swrm_wakeup_interrupt__rs_35, "swrm_wakeup_interrupt");
  if ( (_DWORD)result )
  {
    v9 = &unk_1118B;
    goto LABEL_18;
  }
  return result;
}
