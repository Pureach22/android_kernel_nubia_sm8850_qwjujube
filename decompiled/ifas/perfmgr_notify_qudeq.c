void __fastcall perfmgr_notify_qudeq(int pid, unsigned __int64 identifier)
{
  __int64 v4; // x0
  __int64 v5; // x1
  __int64 v6; // x19
  __int64 v7; // x1

  if ( ifas_log_enable )
  {
    printk(&unk_F0B8, "perfmgr_notify_qudeq");
    if ( ifas_log_enable )
      printk(&unk_FFBA, (unsigned int)ifas_enable);
  }
  if ( ifas_enable )
  {
    v4 = _kmalloc_cache_noprof(queue_work_on, 2080, 64);
    if ( v4 )
    {
      v5 = qbuffer_notifyworkqueue;
      if ( qbuffer_notifyworkqueue )
      {
        *(_DWORD *)(v4 + 8) = pid;
        *(_DWORD *)v4 = 1;
        *(_QWORD *)(v4 + 32) = 0xFFFFFFFE00000LL;
        *(_QWORD *)(v4 + 16) = identifier;
        *(_QWORD *)(v4 + 40) = v4 + 40;
        *(_QWORD *)(v4 + 48) = v4 + 40;
        *(_QWORD *)(v4 + 56) = perfmgr_notifer_wq_cb;
        queue_work_on(32, v5, v4 + 32);
      }
      else
      {
        v6 = v4;
        printk(&unk_FEDD, "perfmgr_notify_qudeq");
        kfree(v6, v7);
      }
    }
    else
    {
      printk(&unk_1046A, "perfmgr_notify_qudeq");
    }
  }
}
