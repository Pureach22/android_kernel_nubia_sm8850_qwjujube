__int64 __fastcall delayed_release_work_func(__int64 a1)
{
  unsigned int v2; // w8
  __int64 v3; // x20
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  _QWORD v9[2]; // [xsp+0h] [xbp-10h] BYREF

  v9[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_DWORD *)(a1 + 104);
  v9[0] = 0;
  if ( v2 <= 0x15 && (v2 & 1) != 0 )
  {
    v3 = raw_spin_lock_irqsave(ipa_rm_ctx + 16);
    if ( (unsigned int)ipa_rm_dep_graph_get_resource(*(_QWORD *)ipa_rm_ctx, *(unsigned int *)(a1 + 104), v9) )
    {
      printk(&unk_3E015F, "delayed_release_work_func");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(ipc_logbuf, "ipa_rm %s:%d resource does not exists\n", "delayed_release_work_func", 239);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(ipc_logbuf_low, "ipa_rm %s:%d resource does not exists\n", "delayed_release_work_func", 239);
      }
    }
    else
    {
      ipa_rm_resource_consumer_release(v9[0], *(unsigned int *)(a1 + 108), *(unsigned __int8 *)(a1 + 112));
    }
    raw_spin_unlock_irqrestore(ipa_rm_ctx + 16, v3);
  }
  else
  {
    printk(&unk_3DD74A, "delayed_release_work_func");
    if ( ipa3_get_ipc_logbuf() )
    {
      v5 = ipa3_get_ipc_logbuf();
      ipc_log_string(v5, "ipa_rm %s:%d can be called on CONS only\n", "delayed_release_work_func", 231);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v6 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v6, "ipa_rm %s:%d can be called on CONS only\n", "delayed_release_work_func", 231);
    }
  }
  result = kfree(a1);
  _ReadStatusReg(SP_EL0);
  return result;
}
