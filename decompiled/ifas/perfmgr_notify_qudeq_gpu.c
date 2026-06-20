void __fastcall perfmgr_notify_qudeq_gpu(unsigned int startend, int pid, unsigned __int64 identifier)
{
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x19
  __int64 v9; // x1

  if ( ifas_log_enable )
  {
    printk(&unk_1015F, "perfmgr_notify_qudeq_gpu");
    if ( ifas_log_enable )
      printk(&unk_FFBA, (unsigned int)ifas_enable);
  }
  if ( ifas_enable && enable_gpu_policy )
  {
    v6 = _kmalloc_cache_noprof(queue_work_on, 2080, 64);
    if ( v6 )
    {
      v7 = qbuffer_notifyworkqueue;
      if ( qbuffer_notifyworkqueue )
      {
        *(_DWORD *)(v6 + 8) = pid;
        *(_DWORD *)v6 = 3;
        *(_DWORD *)(v6 + 4) = startend;
        *(_QWORD *)(v6 + 32) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v6 + 16) = identifier;
        *(_QWORD *)(v6 + 40) = v6 + 40;
        *(_QWORD *)(v6 + 48) = v6 + 40;
        *(_QWORD *)(v6 + 56) = perfmgr_notifer_wq_cb;
        queue_work_on(32, v7, v6 + 32);
      }
      else
      {
        v8 = v6;
        printk(&unk_FEDD, "perfmgr_notify_qudeq_gpu");
        kfree(v8, v9);
      }
    }
    else
    {
      printk(&unk_1046A, "perfmgr_notify_qudeq_gpu");
    }
  }
}
