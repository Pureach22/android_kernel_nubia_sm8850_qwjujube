__int64 __fastcall ipa_wdi_reg_intf(__int64 a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a1 )
  {
    *(_DWORD *)(a1 + 60) = 0;
    return ((__int64 (*)(void))ipa_wdi_reg_intf_per_inst)();
  }
  else
  {
    printk(&unk_3B3895, "ipa_wdi_reg_intf");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_wdi %s:%d invalid params in=%pK\n", "ipa_wdi_reg_intf", 2352, nullptr);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_wdi %s:%d invalid params in=%pK\n", "ipa_wdi_reg_intf", 2352, nullptr);
    }
    return 4294967274LL;
  }
}
