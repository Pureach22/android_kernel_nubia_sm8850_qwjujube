long double ipa_mhi_wq_notify_wakeup()
{
  __int64 ipc_logbuf; // x0
  long double v1; // q0
  __int64 ipc_logbuf_low; // x0
  __int64 v3; // x0
  _DWORD *v4; // x9
  __int64 v5; // x0
  long double result; // q0
  __int64 v7; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_wq_notify_wakeup", 522);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v1 = ipc_log_string(ipc_logbuf_low, "ipa_mhi_client %s:%d ENTRY\n", "ipa_mhi_wq_notify_wakeup", 522);
  }
  v4 = *(_DWORD **)(ipa_mhi_client_ctx + 8);
  v3 = *(_QWORD *)(ipa_mhi_client_ctx + 16);
  if ( *(v4 - 1) != -967519881 )
    __break(0x8229u);
  ((void (__fastcall *)(__int64, __int64, _QWORD, long double))v4)(v3, 1, 0, v1);
  if ( ipa3_get_ipc_logbuf() )
  {
    v5 = ipa3_get_ipc_logbuf();
    ipc_log_string(v5, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_wq_notify_wakeup", 525);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v7 = ipa3_get_ipc_logbuf_low();
    return ipc_log_string(v7, "ipa_mhi_client %s:%d EXIT\n", "ipa_mhi_wq_notify_wakeup", 525);
  }
  return result;
}
