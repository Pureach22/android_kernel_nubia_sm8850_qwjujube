__int64 __fastcall walt_proc_user_hint_handler(__int64 a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  int v10; // w25
  unsigned int v11; // w19
  unsigned __int64 v12; // x9
  unsigned int v14; // w9
  __int64 v15; // x1

  mutex_lock(&walt_proc_user_hint_handler_mutex);
  v10 = sysctl_sched_user_hint;
  v11 = proc_dointvec_minmax(a1, a2, a3, a4, a5);
  if ( a2 && !v11 && v10 != sysctl_sched_user_hint )
  {
    v12 = *(unsigned int *)(_ReadStatusReg(SP_EL0) + 40);
    sched_user_hint_reset_time = jiffies + 250LL;
    if ( ((*(_QWORD *)((char *)&_cpu_online_mask + ((v12 >> 3) & 0x1FFFFFF8)) >> v12) & 1) != 0 )
    {
      irq_work_queue(&walt_migration_irq_work);
    }
    else
    {
      v14 = __clz(__rbit64(_cpu_online_mask));
      if ( _cpu_online_mask )
        v15 = v14;
      else
        v15 = 32;
      irq_work_queue_on(&walt_migration_irq_work, v15);
    }
  }
  mutex_unlock(&walt_proc_user_hint_handler_mutex);
  return v11;
}
