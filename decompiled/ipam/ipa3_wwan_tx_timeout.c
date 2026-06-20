long double __fastcall ipa3_wwan_tx_timeout(__int64 a1)
{
  __int64 ipc_logbuf; // x0
  long double result; // q0
  __int64 ipc_logbuf_low; // x0

  if ( *(_DWORD *)(a1 + 2880) )
  {
    printk(&unk_3D0D8F, "ipa3_wwan_tx_timeout");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(
        ipc_logbuf,
        "ipa-wan %s:%d [%s] data stall in UL, %d outstanding\n",
        "ipa3_wwan_tx_timeout",
        3264,
        (const char *)(a1 + 296),
        *(_DWORD *)(a1 + 2880));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      return ipc_log_string(
               ipc_logbuf_low,
               "ipa-wan %s:%d [%s] data stall in UL, %d outstanding\n",
               "ipa3_wwan_tx_timeout",
               3264,
               (const char *)(a1 + 296),
               *(_DWORD *)(a1 + 2880));
    }
  }
  return result;
}
