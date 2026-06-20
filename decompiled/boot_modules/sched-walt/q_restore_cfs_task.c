__int64 __fastcall q_restore_cfs_task(int a1, int a2)
{
  __int64 result; // x0
  __int64 v5; // x20
  void *v6; // x0

  result = _kmalloc_cache_noprof(android_rvh_probe_register, 3520, 48);
  if ( result )
  {
    *(_DWORD *)result = a1;
    *(_DWORD *)(result + 4) = a2;
    if ( kthread_running != 1 )
      return kfree(result);
    *(_QWORD *)(result + 32) = 0;
    *(_QWORD *)(result + 40) = 0;
    v5 = result;
    *(_QWORD *)(result + 8) = result + 8;
    *(_QWORD *)(result + 16) = result + 8;
    *(_QWORD *)(result + 24) = restore_task_to_cfs_work;
    result = kthread_queue_work(&worker, result + 8);
    if ( (result & 1) == 0 )
    {
      if ( byte_6A5A8 == 1 )
        printk(&unk_63D07);
      result = kfree(v5);
    }
    if ( byte_6A5A8 == 1 )
    {
      v6 = &unk_639E5;
      return printk(v6);
    }
  }
  else if ( byte_6A5A8 == 1 )
  {
    v6 = &unk_66CFD;
    return printk(v6);
  }
  return result;
}
