__int64 __fastcall sched_pipeline_special_handler(_QWORD *a1, unsigned int a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 v9; // x8
  __int64 v10; // x9
  __int64 v11; // x9
  __int64 v12; // x10
  unsigned int v13; // w19
  __int64 vpid; // x0
  __int64 pid_task; // x0
  __int64 v17; // x19
  int v23; // w9
  _QWORD v25[8]; // [xsp+0h] [xbp-40h] BYREF

  v25[7] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9 = a1[4];
  v10 = a1[5];
  v25[6] = a1[6];
  v25[4] = v9;
  v25[5] = v10;
  v11 = a1[1];
  v25[0] = *a1;
  v25[1] = v11;
  v12 = a1[3];
  v25[2] = a1[2];
  v25[3] = v12;
  mutex_lock(&sched_pipeline_special_handler_mutex);
  v13 = proc_dointvec_minmax(v25, a2, a3, a4, a5);
  if ( a2 && !v13 )
  {
    if ( !sysctl_sched_pipeline_special )
    {
      remove_special_task(0);
LABEL_14:
      v13 = 0;
      goto LABEL_15;
    }
    vpid = find_vpid((unsigned int)sysctl_sched_pipeline_special);
    pid_task = get_pid_task(vpid, 0);
    if ( pid_task )
    {
      _X8 = (unsigned int *)(pid_task + 64);
      __asm { PRFM            #0x11, [X8] }
      do
        v23 = __ldxr(_X8);
      while ( __stlxr(v23 - 1, _X8) );
      if ( v23 == 1 )
      {
        __dmb(9u);
        v17 = pid_task;
        _put_task_struct(pid_task);
      }
      else
      {
        if ( v23 > 0 )
          goto LABEL_13;
        v17 = pid_task;
        refcount_warn_saturate(pid_task + 64, 3);
      }
      pid_task = v17;
LABEL_13:
      set_special_task(pid_task);
      goto LABEL_14;
    }
    remove_special_task(0);
    sysctl_sched_pipeline_special = 0;
    v13 = -2;
  }
LABEL_15:
  mutex_unlock(&sched_pipeline_special_handler_mutex);
  _ReadStatusReg(SP_EL0);
  return v13;
}
