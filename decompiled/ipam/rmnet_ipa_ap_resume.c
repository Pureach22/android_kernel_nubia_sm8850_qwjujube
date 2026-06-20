__int64 rmnet_ipa_ap_resume()
{
  __int64 v0; // x19
  __int64 ipc_logbuf; // x0
  long double v2; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0

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
    ipc_log_string(ipc_logbuf, "ipa-wan %s:%d Enter...\n", "rmnet_ipa_ap_resume", 3983);
  }
LABEL_7:
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v2 = ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d Enter...\n", "rmnet_ipa_ap_resume", 3983);
  }
  if ( rmnet_ipa3_ctx )
    *(_DWORD *)(rmnet_ipa3_ctx + 1988) = 0;
  if ( v0 )
  {
    netif_device_attach(v0, v2);
    v4 = *(_QWORD *)(v0 + 24);
    if ( *(_QWORD *)(v4 + 328) != jiffies )
      *(_QWORD *)(v4 + 328) = jiffies;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v5 = ipa3_get_ipc_logbuf();
    ipc_log_string(v5, "ipa-wan %s:%d Exit\n", "rmnet_ipa_ap_resume", 3991);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v6 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v6, "ipa-wan %s:%d Exit\n", "rmnet_ipa_ap_resume", 3991);
  }
  return 0;
}
