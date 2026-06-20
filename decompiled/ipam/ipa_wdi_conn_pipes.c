__int64 __fastcall ipa_wdi_conn_pipes(_DWORD *a1, const void *a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a1 && a2 )
  {
    a1[512] = 0;
    return ((__int64 (*)(void))ipa_wdi_conn_pipes_per_inst)();
  }
  else
  {
    printk(&unk_3E81FE, "ipa_wdi_conn_pipes");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_wdi %s:%d empty parameters. in=%pK out=%pK\n", "ipa_wdi_conn_pipes", 2370, a1, a2);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(
        ipc_logbuf_low,
        "ipa_wdi %s:%d empty parameters. in=%pK out=%pK\n",
        "ipa_wdi_conn_pipes",
        2370,
        a1,
        a2);
    }
    return 4294967274LL;
  }
}
