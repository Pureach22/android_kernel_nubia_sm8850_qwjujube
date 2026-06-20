__int64 __fastcall nbia_affinity_ctrl_work(__int64 result)
{
  unsigned int *v1; // x19
  __int64 v2; // x20
  __int64 vpid; // x0
  __int64 pid_task; // x0
  __int64 v5; // x8
  _QWORD *v6; // x9
  __int64 v7; // x21
  __int64 v9; // x24
  char v10; // w8
  unsigned __int64 v11; // x8
  unsigned __int64 v12; // x8
  unsigned __int64 v13; // x22
  char v14; // w8
  unsigned __int64 v15; // x8
  unsigned __int64 v16; // x22
  __int64 v17; // x20
  int v23; // w9

  v1 = (unsigned int *)(result - 16);
  if ( result == 16 )
  {
    if ( sched_nbia_debug )
      return printk(&unk_62F1D);
  }
  else
  {
    v2 = result;
    mutex_lock(&sysfs_store_lock);
    vpid = find_vpid(*v1);
    pid_task = get_pid_task(vpid, 0);
    if ( pid_task )
    {
      if ( pid_task != -5184 )
      {
        if ( sched_nbia_debug )
        {
          v9 = pid_task;
          printk(&unk_62F4A);
          v10 = 0;
          do
          {
            v11 = (unsigned int)(-1LL << v10) & *(_DWORD *)(v2 - 8);
            _ZF = (_DWORD)v11 == 0;
            v12 = __clz(__rbit64(v11));
            if ( _ZF )
              v13 = 32;
            else
              v13 = v12;
            if ( (unsigned int)v13 >= 0x20 )
              break;
            printk(&unk_66A74);
            v10 = v13 + 1;
          }
          while ( v13 <= 0x1E );
          v14 = 0;
          pid_task = v9;
          do
          {
            v15 = (unsigned int)(-1LL << v14) & **(_DWORD **)(pid_task + 1376);
            if ( !(_DWORD)v15 )
              break;
            v16 = __clz(__rbit64(v15));
            printk(&unk_6183C);
            pid_task = v9;
            v14 = v16 + 1;
          }
          while ( v16 < 0x1F );
        }
        v5 = *(_QWORD *)(v2 - 8);
        if ( (_DWORD)v5 )
        {
          v6 = *(_QWORD **)(pid_task + 1384);
          if ( v6 )
            *v6 = v5;
          v7 = pid_task;
          if ( (unsigned int)set_cpus_allowed_ptr() )
            printk(&unk_65459);
          pid_task = v7;
          if ( sched_nbia_debug )
          {
            printk(&unk_64A0B);
            pid_task = v7;
          }
        }
        else if ( sched_nbia_debug )
        {
          v17 = pid_task;
          printk(&unk_6208D);
          pid_task = v17;
        }
      }
      _X8 = (unsigned int *)(pid_task + 64);
      __asm { PRFM            #0x11, [X8] }
      do
        v23 = __ldxr(_X8);
      while ( __stlxr(v23 - 1, _X8) );
      if ( v23 == 1 )
      {
        __dmb(9u);
        _put_task_struct(pid_task);
      }
      else if ( v23 <= 0 )
      {
        refcount_warn_saturate(pid_task + 64, 3);
      }
    }
    else if ( sched_nbia_debug )
    {
      printk(&unk_61805);
    }
    mutex_unlock(&sysfs_store_lock);
    return kfree(v1);
  }
  return result;
}
