__int64 __fastcall ipa_wdi_set_perf_profile(__int64 a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a1 )
    return ipa_wdi_set_perf_profile_per_inst(0, a1);
  printk(&unk_3DA0CE, "ipa_wdi_set_perf_profile");
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wdi %s:%d Invalid input\n", "ipa_wdi_set_perf_profile", 2400);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_wdi %s:%d Invalid input\n", "ipa_wdi_set_perf_profile", 2400);
  }
  return 4294967274LL;
}
