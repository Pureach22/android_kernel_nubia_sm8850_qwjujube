__int64 ipa_rm_initialize()
{
  __int64 v0; // x0
  __int64 v1; // x8
  unsigned int v2; // w0
  __int64 ipc_logbuf; // x0
  __int64 result; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  unsigned int v10; // w20
  __int64 v11; // x0
  __int64 v12; // x0

  ipa_rm_ctx = _kmalloc_cache_noprof(raw_spin_lock_irqsave, 3520, 208);
  if ( ipa_rm_ctx )
  {
    v0 = alloc_workqueue("%s", (const char *)0x6000A);
    v1 = ipa_rm_ctx;
    *(_QWORD *)(ipa_rm_ctx + 8) = v0;
    if ( v0 )
    {
      v2 = ipa_rm_dep_graph_create(v1);
      if ( !v2 )
      {
        *(_DWORD *)(ipa_rm_ctx + 16) = 0;
        if ( ipa3_get_ipc_logbuf() )
        {
          ipc_logbuf = ipa3_get_ipc_logbuf();
          ipc_log_string(ipc_logbuf, "ipa_rm %s:%d SUCCESS\n", "ipa_rm_initialize", 532);
        }
        result = ipa3_get_ipc_logbuf_low();
        if ( result )
        {
          ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
          ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d SUCCESS\n", "ipa_rm_initialize", 532);
          return 0;
        }
        return result;
      }
      v10 = v2;
      printk(&unk_3CED91, "ipa_rm_initialize");
      if ( ipa3_get_ipc_logbuf() )
      {
        v11 = ipa3_get_ipc_logbuf();
        ipc_log_string(v11, "ipa_rm %s:%d create dependency graph failed\n", "ipa_rm_initialize", 528);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v12 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v12, "ipa_rm %s:%d create dependency graph failed\n", "ipa_rm_initialize", 528);
      }
      destroy_workqueue(*(_QWORD *)(ipa_rm_ctx + 8));
    }
    else
    {
      printk(&unk_3E56D0, "ipa_rm_initialize");
      if ( ipa3_get_ipc_logbuf() )
      {
        v8 = ipa3_get_ipc_logbuf();
        ipc_log_string(v8, "ipa_rm %s:%d create workqueue failed\n", "ipa_rm_initialize", 522);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v9 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v9, "ipa_rm %s:%d create workqueue failed\n", "ipa_rm_initialize", 522);
      }
      v10 = -12;
    }
    kfree(ipa_rm_ctx);
    return v10;
  }
  printk(&unk_3E0188, "ipa_rm_initialize");
  if ( ipa3_get_ipc_logbuf() )
  {
    v6 = ipa3_get_ipc_logbuf();
    ipc_log_string(v6, "ipa_rm %s:%d no mem\n", "ipa_rm_initialize", 516);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v7 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v7, "ipa_rm %s:%d no mem\n", "ipa_rm_initialize", 516);
  }
  return 4294967284LL;
}
