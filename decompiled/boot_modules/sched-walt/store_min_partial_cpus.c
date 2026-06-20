__int64 __fastcall store_min_partial_cpus(__int64 a1, char *s, __int64 a3)
{
  unsigned int v5; // w8
  __int64 v6; // x0
  __int64 v7; // x11
  __int64 v8; // x9
  unsigned int v10; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v11; // [xsp+8h] [xbp-8h]

  v11 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v10 = 0;
  if ( sscanf(s, "%u\n", &v10) == 1 )
  {
    v5 = v10;
    if ( v10 >= *(_DWORD *)(a1 + 72) )
      v5 = *(_DWORD *)(a1 + 72);
    *(_DWORD *)(a1 + 8) = v5;
    if ( (eval_need(a1) & 1) != 0 )
    {
      v6 = raw_spin_lock_irqsave(&core_ctl_pending_lock);
      core_ctl_pending = 1;
      raw_spin_unlock_irqrestore(&core_ctl_pending_lock, v6);
      wake_up_process(core_ctl_thread);
    }
    v7 = *(_QWORD *)(a1 + 80);
    if ( *(_DWORD *)(a1 + 8) )
      v8 = v7 | part_haltable_cpus;
    else
      v8 = (unsigned int)part_haltable_cpus & ~(_DWORD)v7;
    part_haltable_cpus = v8;
  }
  else
  {
    a3 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
