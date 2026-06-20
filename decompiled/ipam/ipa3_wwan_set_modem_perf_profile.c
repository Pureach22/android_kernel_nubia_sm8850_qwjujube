__int64 __fastcall ipa3_wwan_set_modem_perf_profile(unsigned int a1)
{
  __int64 ipc_logbuf; // x0
  long double v3; // q0
  __int64 ipc_logbuf_low; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa-wan %s:%d throughput: %d\n", "ipa3_wwan_set_modem_perf_profile", 3481, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    v3 = ipc_log_string(ipc_logbuf_low, "ipa-wan %s:%d throughput: %d\n", "ipa3_wwan_set_modem_perf_profile", 3481, a1);
  }
  return ((__int64 (__fastcall *)(_QWORD, _QWORD, long double))ipa_pm_set_throughput)(
           *(unsigned int *)(rmnet_ipa3_ctx + 1192),
           a1,
           v3);
}
