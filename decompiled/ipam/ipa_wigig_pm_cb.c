long double __fastcall ipa_wigig_pm_cb(__int64 a1, int a2)
{
  __int64 ipc_logbuf; // x0
  long double result; // q0
  __int64 ipc_logbuf_low; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d received pm event %d\n", "ipa_wigig_pm_cb", 555, a2);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    return ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d received pm event %d\n", "ipa_wigig_pm_cb", 555, a2);
  }
  return result;
}
