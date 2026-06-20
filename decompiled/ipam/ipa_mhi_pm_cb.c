void __fastcall ipa_mhi_pm_cb(__int64 a1, int a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  const char *v7; // x4
  __int64 v8; // x0
  __int64 v9; // x8
  const char *v10; // x4
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x19
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_pm_cb", 2183);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_pm_cb", 2183);
  }
  if ( a2 == 1 )
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      v5 = ipa3_get_ipc_logbuf();
      v6 = *(unsigned int *)ipa_mhi_client_ctx;
      if ( (unsigned int)v6 > 5 )
        v7 = "INVALID";
      else
        v7 = ipa_mhi_state_str[v6];
      ipc_log_string(v5, "ipa_mhi_client %s:%d %s\n", "ipa_mhi_pm_cb", 2191, v7);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v8 = ipa3_get_ipc_logbuf_low();
      v9 = *(unsigned int *)ipa_mhi_client_ctx;
      if ( (unsigned int)v9 > 5 )
        v10 = "INVALID";
      else
        v10 = ipa_mhi_state_str[v9];
      ipc_log_string(v8, "ipa_mhi_client %s:%d %s\n", "ipa_mhi_pm_cb", 2191, v10);
    }
    v11 = raw_spin_lock_irqsave(ipa_mhi_client_ctx + 4);
    v12 = ipa_mhi_client_ctx;
    v13 = v11;
    if ( *(_DWORD *)ipa_mhi_client_ctx == 3 )
    {
      *(_BYTE *)(ipa_mhi_client_ctx + 24) = 1;
    }
    else if ( *(_DWORD *)ipa_mhi_client_ctx == 4 )
    {
      ipa_mhi_notify_wakeup();
      v12 = ipa_mhi_client_ctx;
    }
    raw_spin_unlock_irqrestore(v12 + 4, v13);
    if ( ipa3_get_ipc_logbuf() )
    {
      v14 = ipa3_get_ipc_logbuf();
      ipc_log_string(v14, "ipa_mhi_client %s:%d EXIT", "ipa_mhi_pm_cb", 2201);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v15 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v15, "ipa_mhi_client %s:%d EXIT", "ipa_mhi_pm_cb", 2201);
    }
  }
  else
  {
    printk(&unk_3A8437, "ipa_mhi_pm_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      v16 = ipa3_get_ipc_logbuf();
      ipc_log_string(v16, "ipa_mhi_client %s:%d Unexpected event %d\n", "ipa_mhi_pm_cb", 2186, a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v17 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v17, "ipa_mhi_client %s:%d Unexpected event %d\n", "ipa_mhi_pm_cb", 2186, a2);
    }
    __break(0x800u);
  }
}
