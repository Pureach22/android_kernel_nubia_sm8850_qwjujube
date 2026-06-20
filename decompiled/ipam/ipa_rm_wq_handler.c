__int64 __fastcall ipa_rm_wq_handler(__int64 a1)
{
  __int64 ipc_logbuf_low; // x0
  __int64 v3; // x8
  const char *v4; // x4
  int v5; // w8
  unsigned int v6; // w8
  __int64 v7; // x20
  __int64 result; // x0
  __int64 ipc_logbuf; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0
  _QWORD v15[2]; // [xsp+0h] [xbp-10h] BYREF

  v15[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v15[0] = 0;
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v3 = *(unsigned int *)(a1 + 36);
    if ( (unsigned int)v3 <= 0x15 )
      v4 = resource_name_to_str[v3];
    else
      v4 = "INVALID RESOURCE";
    ipc_log_string(
      ipc_logbuf_low,
      "ipa_rm %s:%d %s cmd=%d event=%d notify_registered_only=%d\n",
      "ipa_rm_wq_handler",
      318,
      v4,
      *(_DWORD *)(a1 + 32),
      *(_DWORD *)(a1 + 40),
      *(unsigned __int8 *)(a1 + 44));
  }
  v5 = *(_DWORD *)(a1 + 32);
  if ( v5 == 2 )
  {
    v7 = raw_spin_lock_irqsave(ipa_rm_ctx + 16);
    if ( (unsigned int)ipa_rm_dep_graph_get_resource(*(_QWORD *)ipa_rm_ctx, *(unsigned int *)(a1 + 36), v15) )
    {
      printk(&unk_3E015F, "ipa_rm_wq_handler");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(ipc_logbuf, "ipa_rm %s:%d resource does not exists\n", "ipa_rm_wq_handler", 346);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v10 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v10, "ipa_rm %s:%d resource does not exists\n", "ipa_rm_wq_handler", 346);
      }
    }
    else
    {
      ipa_rm_resource_consumer_handle_cb(v15[0], *(unsigned int *)(a1 + 40));
    }
    goto LABEL_14;
  }
  if ( !v5 )
  {
    v6 = *(_DWORD *)(a1 + 36);
    if ( v6 <= 0x15 && (v6 & 1) == 0 )
    {
      v7 = raw_spin_lock_irqsave(ipa_rm_ctx + 16);
      if ( (unsigned int)ipa_rm_dep_graph_get_resource(*(_QWORD *)ipa_rm_ctx, *(unsigned int *)(a1 + 36), v15) )
      {
        printk(&unk_3E015F, "ipa_rm_wq_handler");
        if ( ipa3_get_ipc_logbuf() )
        {
          v13 = ipa3_get_ipc_logbuf();
          ipc_log_string(v13, "ipa_rm %s:%d resource does not exists\n", "ipa_rm_wq_handler", 329);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v14 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v14, "ipa_rm %s:%d resource does not exists\n", "ipa_rm_wq_handler", 329);
        }
      }
      else
      {
        ipa_rm_resource_producer_notify_clients(v15[0], *(unsigned int *)(a1 + 40), *(unsigned __int8 *)(a1 + 44));
      }
LABEL_14:
      raw_spin_unlock_irqrestore(ipa_rm_ctx + 16, v7);
      goto LABEL_15;
    }
    printk(&unk_3BA376, "ipa_rm_wq_handler");
    if ( ipa3_get_ipc_logbuf() )
    {
      v11 = ipa3_get_ipc_logbuf();
      ipc_log_string(v11, "ipa_rm %s:%d resource is not PROD\n", "ipa_rm_wq_handler", 322);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v12 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v12, "ipa_rm %s:%d resource is not PROD\n", "ipa_rm_wq_handler", 322);
    }
  }
LABEL_15:
  result = kfree(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
