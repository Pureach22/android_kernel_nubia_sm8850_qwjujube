__int64 __fastcall restore_task_to_cfs_work(__int64 a1)
{
  unsigned int *v1; // x19
  __int64 vpid; // x0
  __int64 pid_task; // x0
  __int64 v5; // x20
  int v13; // w8

  v1 = (unsigned int *)(a1 - 8);
  if ( a1 == 8 )
    return printk(&unk_62DB4);
  if ( (unsigned int)(*(_DWORD *)(a1 - 4) - 141) <= 0xFFFFFFD7 )
  {
    printk(&unk_6769D);
  }
  else
  {
    vpid = find_vpid(*v1);
    pid_task = get_pid_task(vpid, 0);
    if ( pid_task )
    {
      v5 = pid_task;
      if ( byte_6A5A8 )
        printk(&unk_64735);
      sched_set_normal(v5, (unsigned int)(*(_DWORD *)(a1 - 4) - 120));
      if ( byte_6A5A8 == 1 )
        printk(&unk_66A1A);
      _X0 = (unsigned int *)(v5 + 64);
      __asm { PRFM            #0x11, [X0] }
      do
        v13 = __ldxr(_X0);
      while ( __stlxr(v13 - 1, _X0) );
      if ( v13 == 1 )
      {
        __dmb(9u);
        _put_task_struct(v5);
      }
      else if ( v13 <= 0 )
      {
        refcount_warn_saturate(_X0, 3);
      }
    }
    else if ( byte_6A5A8 )
    {
      printk(&unk_6577F);
    }
  }
  return kfree(v1);
}
