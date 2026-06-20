__int64 __fastcall ipa3_wwan_change_mtu(__int64 a1, unsigned int a2)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0

  if ( a2 > 0x2400 )
    return 4294967274LL;
  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(
      ipc_logbuf,
      "ipa-wan %s:%d [%s] MTU change: old=%d new=%d\n",
      "ipa3_wwan_change_mtu",
      3106,
      (const char *)(a1 + 296),
      *(_DWORD *)(a1 + 56),
      a2);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(
      ipc_logbuf_low,
      "ipa-wan %s:%d [%s] MTU change: old=%d new=%d\n",
      "ipa3_wwan_change_mtu",
      3106,
      (const char *)(a1 + 296),
      *(_DWORD *)(a1 + 56),
      a2);
  }
  *(_DWORD *)(a1 + 56) = a2;
  return 0;
}
