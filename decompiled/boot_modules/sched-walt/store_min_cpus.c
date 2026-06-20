__int64 __fastcall store_min_cpus(__int64 a1, char *s, __int64 a3)
{
  unsigned int v5; // w8
  __int64 v6; // x0
  unsigned int v8; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v9; // [xsp+8h] [xbp-8h]

  v9 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v8 = 0;
  if ( sscanf(s, "%u\n", &v8) == 1 )
  {
    v5 = v8;
    if ( v8 >= *(_DWORD *)(a1 + 72) )
      v5 = *(_DWORD *)(a1 + 72);
    *(_DWORD *)(a1 + 4) = v5;
    if ( (eval_need(a1) & 1) != 0 )
    {
      v6 = raw_spin_lock_irqsave(&core_ctl_pending_lock);
      core_ctl_pending = 1;
      raw_spin_unlock_irqrestore(&core_ctl_pending_lock, v6);
      wake_up_process(core_ctl_thread);
    }
  }
  else
  {
    a3 = -22;
  }
  _ReadStatusReg(SP_EL0);
  return a3;
}
