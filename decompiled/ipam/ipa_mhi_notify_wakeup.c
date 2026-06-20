long double ipa_mhi_notify_wakeup()
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v2; // x0
  long double result; // q0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_notify_wakeup", 504);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_notify_wakeup", 504);
  }
  if ( *(_BYTE *)(ipa_mhi_client_ctx + 25) == 1 )
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      v2 = ipa3_get_ipc_logbuf();
      ipc_log_string(v2, "ipa_mhi_client %s:%d wakeup already called\n", "ipa_mhi_notify_wakeup", 506);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v4 = ipa3_get_ipc_logbuf_low();
      return ipc_log_string(v4, "ipa_mhi_client %s:%d wakeup already called\n", "ipa_mhi_notify_wakeup", 506);
    }
  }
  else
  {
    queue_work_on(32, *(_QWORD *)(ipa_mhi_client_ctx + 32), &ipa_mhi_notify_wakeup_work);
    *(_BYTE *)(ipa_mhi_client_ctx + 25) = 1;
    if ( ipa3_get_ipc_logbuf() )
    {
      v5 = ipa3_get_ipc_logbuf();
      ipc_log_string(v5, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_notify_wakeup", 511);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v6 = ipa3_get_ipc_logbuf_low();
      return ipc_log_string(v6, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_notify_wakeup", 511);
    }
  }
  return result;
}
