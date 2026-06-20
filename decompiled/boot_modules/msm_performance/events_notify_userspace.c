__int64 events_notify_userspace()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x1
  __int64 v2; // x0
  __int64 v3; // x0
  int v4; // w24

  StatusReg = _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    *(_DWORD *)(StatusReg + 48) = 1;
    __dmb(0xBu);
    v1 = raw_spin_lock_irqsave(&events_group);
    if ( (byte_B9AC & 1) == 0 )
      break;
LABEL_5:
    *(_DWORD *)(StatusReg + 48) = 0;
    __dmb(0xBu);
    v4 = (unsigned __int8)byte_B9AC;
    byte_B9AC = 0;
    raw_spin_unlock_irqrestore(&events_group, v1);
    if ( v4 == 1 )
      sysfs_notify(events_kobj, 0, "cpu_hotplug");
  }
  v2 = raw_spin_unlock_irqrestore(&events_group, v1);
  v3 = schedule(v2);
  if ( (kthread_should_stop(v3) & 1) == 0 )
  {
    v1 = raw_spin_lock_irqsave(&events_group);
    goto LABEL_5;
  }
  return 0;
}
