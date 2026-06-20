__int64 ipa_eth_uc_rdy_cb()
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_eth %s:%d IPA uC is ready for eth", "ipa_eth_uc_rdy_cb", 194);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_eth %s:%d IPA uC is ready for eth", "ipa_eth_uc_rdy_cb", 194);
  }
  queue_work_on(32, *(_QWORD *)(ipa_eth_ctx + 240), &ipa_eth_ready_notify);
  return 1;
}
