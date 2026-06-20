__int64 __fastcall ipa_wdi_init(_DWORD *a1, _BYTE *a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a1 )
  {
    a1[8] = -1;
    return ipa_wdi_init_per_inst(a1, a2);
  }
  else
  {
    printk(&unk_3B3895, "ipa_wdi_init");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_wdi %s:%d invalid params in=%pK\n", "ipa_wdi_init", 2334, nullptr);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_wdi %s:%d invalid params in=%pK\n", "ipa_wdi_init", 2334, nullptr);
    }
    return 4294967274LL;
  }
}
