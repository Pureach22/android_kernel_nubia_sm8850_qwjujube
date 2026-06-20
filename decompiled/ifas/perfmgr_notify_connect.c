void __fastcall perfmgr_notify_connect(int pid, unsigned __int64 identifier, int connectedAPI)
{
  __int64 v6; // x0
  __int64 v7; // x1
  __int64 v8; // x19
  __int64 v9; // x1

  if ( ifas_log_enable )
    printk(&unk_10287, "perfmgr_notify_connect");
  v6 = _kmalloc_cache_noprof(queue_work_on, 2080, 64);
  if ( v6 )
  {
    v7 = qbuffer_notifyworkqueue;
    if ( qbuffer_notifyworkqueue )
    {
      *(_QWORD *)(v6 + 16) = identifier;
      *(_DWORD *)v6 = 2;
      *(_QWORD *)(v6 + 32) = 0xFFFFFFFE00000LL;
      *(_DWORD *)(v6 + 8) = pid;
      *(_DWORD *)(v6 + 12) = connectedAPI;
      *(_QWORD *)(v6 + 40) = v6 + 40;
      *(_QWORD *)(v6 + 48) = v6 + 40;
      *(_QWORD *)(v6 + 56) = perfmgr_notifer_wq_cb;
      queue_work_on(32, v7, v6 + 32);
    }
    else
    {
      v8 = v6;
      printk(&unk_EB97, "perfmgr_notify_connect");
      kfree(v8, v9);
    }
  }
  else
  {
    printk(&unk_FC92, "perfmgr_notify_connect");
  }
}
