void __fastcall ipa_rm_wq_resume_handler(__int64 a1)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v3; // x8
  const char *v4; // x4
  unsigned int v5; // w8
  __int64 v6; // x20
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 ipc_logbuf; // x0
  __int64 v10; // x0
  _QWORD v11[2]; // [xsp+20h] [xbp-10h] BYREF

  v11[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11[0] = 0;
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v3 = *(unsigned int *)(a1 + 32);
    if ( (unsigned int)v3 <= 0x15 )
      v4 = resource_name_to_str[v3];
    else
      v4 = "INVALID RESOURCE";
    ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d resume work handler: %s", "ipa_rm_wq_resume_handler", 372, v4);
  }
  v5 = *(_DWORD *)(a1 + 32);
  if ( v5 <= 0x15 && (v5 & 1) != 0 )
  {
    ipa3_inc_client_enable_clks();
    v6 = raw_spin_lock_irqsave(ipa_rm_ctx + 16);
    if ( (unsigned int)ipa_rm_dep_graph_get_resource(*(_QWORD *)ipa_rm_ctx, *(unsigned int *)(a1 + 32), v11) )
    {
      printk(&unk_3E015F, "ipa_rm_wq_resume_handler");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(ipc_logbuf, "ipa_rm %s:%d resource does not exists\n", "ipa_rm_wq_resume_handler", 384);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v10 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v10, "ipa_rm %s:%d resource does not exists\n", "ipa_rm_wq_resume_handler", 384);
      }
      raw_spin_unlock_irqrestore(ipa_rm_ctx + 16, v6);
      ipa3_dec_client_disable_clks();
    }
    else
    {
      ipa_rm_resource_consumer_request_work(
        v11[0],
        *(unsigned int *)(a1 + 36),
        *(unsigned int *)(a1 + 40),
        1,
        *(unsigned __int8 *)(a1 + 44));
      raw_spin_unlock_irqrestore(ipa_rm_ctx + 16, v6);
    }
    kfree(a1);
  }
  else
  {
    printk(&unk_3DA620, "ipa_rm_wq_resume_handler");
    if ( ipa3_get_ipc_logbuf() )
    {
      v7 = ipa3_get_ipc_logbuf();
      ipc_log_string(v7, "ipa_rm %s:%d resource is not CONS\n", "ipa_rm_wq_resume_handler", 375);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v8 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v8, "ipa_rm %s:%d resource is not CONS\n", "ipa_rm_wq_resume_handler", 375);
    }
  }
  _ReadStatusReg(SP_EL0);
}
