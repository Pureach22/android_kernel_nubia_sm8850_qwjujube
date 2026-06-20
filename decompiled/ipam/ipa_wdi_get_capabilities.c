__int64 __fastcall ipa_wdi_get_capabilities(unsigned __int8 *a1)
{
  __int64 ipc_logbuf; // x0
  __int64 result; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v5; // x0
  __int64 v6; // x0

  if ( a1 )
  {
    *a1 = 2;
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_wdi %s:%d Wdi Capability: %d\n", "ipa_wdi_get_capabilities", 254, *a1);
    }
    result = ipa3_get_ipc_logbuf_low();
    if ( result )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_wdi %s:%d Wdi Capability: %d\n", "ipa_wdi_get_capabilities", 254, *a1);
      return 0;
    }
  }
  else
  {
    printk(&unk_3E81D6, "ipa_wdi_get_capabilities");
    if ( ipa3_get_ipc_logbuf() )
    {
      v5 = ipa3_get_ipc_logbuf();
      ipc_log_string(v5, "ipa_wdi %s:%d invalid params out=%pK\n", "ipa_wdi_get_capabilities", 249, nullptr);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v6 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v6, "ipa_wdi %s:%d invalid params out=%pK\n", "ipa_wdi_get_capabilities", 249, nullptr);
    }
    return 4294967274LL;
  }
  return result;
}
