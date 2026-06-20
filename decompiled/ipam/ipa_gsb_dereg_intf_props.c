long double __fastcall ipa_gsb_dereg_intf_props(const char *a1)
{
  __int64 v2; // x0
  long double result; // q0
  __int64 v4; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( (unsigned int)((__int64 (*)(void))ipa_deregister_intf)() )
  {
    printk(&unk_3ED7B6, "ipa_gsb_dereg_intf_props");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_gsb %s:%d fail to dereg intf props\n", "ipa_gsb_dereg_intf_props", 433);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_gsb %s:%d fail to dereg intf props\n", "ipa_gsb_dereg_intf_props", 433);
    }
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v2 = ipa3_get_ipc_logbuf();
    ipc_log_string(v2, "ipa_gsb %s:%d deregistered iface props for %s\n", "ipa_gsb_dereg_intf_props", 436, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v4 = ipa3_get_ipc_logbuf_low();
    return ipc_log_string(v4, "ipa_gsb %s:%d deregistered iface props for %s\n", "ipa_gsb_dereg_intf_props", 436, a1);
  }
  return result;
}
