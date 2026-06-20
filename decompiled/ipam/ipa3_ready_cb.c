__int64 __fastcall ipa3_ready_cb(__int64 a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  m_pdev = a1;
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa-wan %s:%d IPA ready callback has been triggered\n", "ipa3_ready_cb", 3587);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d IPA ready callback has been triggered\n", "ipa3_ready_cb", 3587);
  }
  return queue_work_on(32, system_wq, &ipa3_scheduled_probe);
}
