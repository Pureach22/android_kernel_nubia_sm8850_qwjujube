__int64 __fastcall store_assist_cpu_min_misfit(__int64 a1, char *s, __int64 a3)
{
  __int64 v5; // x0
  int v7; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v8; // [xsp+8h] [xbp-8h]

  v8 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = 0;
  if ( sscanf(s, "%u\n", &v7) == 1 )
  {
    *(_DWORD *)(a1 + 296) = v7;
    if ( (eval_need(a1) & 1) != 0 )
    {
      v5 = raw_spin_lock_irqsave(&core_ctl_pending_lock);
      core_ctl_pending = 1;
      raw_spin_unlock_irqrestore(&core_ctl_pending_lock, v5);
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
