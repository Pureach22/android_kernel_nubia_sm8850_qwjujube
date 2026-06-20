__int64 try_core_ctl()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x1
  __int64 v2; // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    *(_DWORD *)(StatusReg + 48) = 1;
    __dmb(0xBu);
    v1 = raw_spin_lock_irqsave(&core_ctl_pending_lock);
    if ( (core_ctl_pending & 1) != 0 )
      goto LABEL_2;
    v2 = raw_spin_unlock_irqrestore(&core_ctl_pending_lock, v1);
    v3 = schedule(v2);
    if ( (kthread_should_stop(v3) & 1) != 0 )
      return 0;
    v1 = raw_spin_lock_irqsave(&core_ctl_pending_lock);
LABEL_2:
    *(_DWORD *)(StatusReg + 48) = 0;
    __dmb(0xBu);
    core_ctl_pending = 0;
    raw_spin_unlock_irqrestore(&core_ctl_pending_lock, v1);
    do_core_ctl();
  }
}
