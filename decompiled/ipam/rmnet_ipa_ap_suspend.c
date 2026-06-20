__int64 rmnet_ipa_ap_suspend()
{
  __int64 v0; // x19
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v3; // x20
  __int64 v4; // x0
  __int64 v5; // x0
  unsigned int v6; // w19
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v10; // x0
  long double v11; // q0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0

  if ( !rmnet_ipa3_ctx || !*(_QWORD *)rmnet_ipa3_ctx )
  {
    v0 = 0;
    if ( !ipa3_get_ipc_logbuf() )
      goto LABEL_7;
    goto LABEL_6;
  }
  v0 = **(_QWORD **)rmnet_ipa3_ctx;
  if ( ipa3_get_ipc_logbuf() )
  {
LABEL_6:
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa-wan %s:%d Enter...\n", "rmnet_ipa_ap_suspend", 3926);
  }
LABEL_7:
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d Enter...\n", "rmnet_ipa_ap_suspend", 3926);
  }
  if ( v0 )
  {
    *(_DWORD *)(rmnet_ipa3_ctx + 1988) = 1;
    v3 = raw_spin_lock_irqsave(v0 + 2888);
    if ( *(_DWORD *)(v0 + 2880) )
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v4 = ipa3_get_ipc_logbuf();
        ipc_log_string(v4, "ipa-wan %s:%d Outstanding packets, postponing AP suspend.\n", "rmnet_ipa_ap_suspend", 3950);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v5 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v5, "ipa-wan %s:%d Outstanding packets, postponing AP suspend.\n", "rmnet_ipa_ap_suspend", 3950);
      }
      *(_DWORD *)(rmnet_ipa3_ctx + 1988) = 0;
      raw_spin_unlock_irqrestore(v0 + 2888, v3);
      v6 = -11;
      if ( ipa3_get_ipc_logbuf() )
        goto LABEL_16;
      goto LABEL_17;
    }
    netif_device_detach(v0);
    raw_spin_unlock_irqrestore(v0 + 2888, v3);
    if ( ipa3_get_ipc_logbuf() )
    {
      v10 = ipa3_get_ipc_logbuf();
      ipc_log_string(v10, "ipa-wan %s:%d De-activating the PM resource.\n", "rmnet_ipa_ap_suspend", 3961);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v12 = ipa3_get_ipc_logbuf_low();
      v11 = ipc_log_string(v12, "ipa-wan %s:%d De-activating the PM resource.\n", "rmnet_ipa_ap_suspend", 3961);
    }
    ((void (__fastcall *)(_QWORD, long double))ipa_pm_deactivate_sync)(*(unsigned int *)(rmnet_ipa3_ctx + 1184), v11);
  }
  else
  {
    printk(&unk_3BF303, "rmnet_ipa_ap_suspend");
    if ( ipa3_get_ipc_logbuf() )
    {
      v13 = ipa3_get_ipc_logbuf();
      ipc_log_string(v13, "ipa-wan %s:%d netdev is NULL.\n", "rmnet_ipa_ap_suspend", 3929);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v14 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v14, "ipa-wan %s:%d netdev is NULL.\n", "rmnet_ipa_ap_suspend", 3929);
    }
  }
  v6 = 0;
  if ( ipa3_get_ipc_logbuf() )
  {
LABEL_16:
    v7 = ipa3_get_ipc_logbuf();
    ipc_log_string(v7, "ipa-wan %s:%d Exit with %d\n", "rmnet_ipa_ap_suspend", 3965, v6);
  }
LABEL_17:
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v8 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v8, "ipa-wan %s:%d Exit with %d\n", "rmnet_ipa_ap_suspend", 3965, v6);
  }
  return v6;
}
