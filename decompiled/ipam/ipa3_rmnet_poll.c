__int64 ipa3_rmnet_poll()
{
  unsigned int v0; // w19
  __int64 ipc_logbuf_low; // x0

  v0 = ipa3_rx_poll(*(_DWORD *)(rmnet_ipa3_ctx + 1084), 64);
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d rcvd packets: %d\n", "ipa3_rmnet_poll", 6936, v0);
  }
  return v0;
}
