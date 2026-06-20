__int64 __fastcall ipa_wigig_tx_dp(unsigned int a1, __int64 a2)
{
  __int64 ipc_logbuf_low; // x0
  __int64 result; // x0
  __int64 v6; // x0
  __int64 v7; // x0

  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d \n", "ipa_wigig_tx_dp", 1900);
  }
  if ( a1 - 86 > 7 || ((1 << (a1 - 86)) & 0xAB) == 0 )
  {
    if ( (unsigned int)__ratelimit(&ipa_wigig_validate_client_type__rs, "ipa_wigig_validate_client_type") )
    {
      printk(&unk_3AE73D, "ipa_wigig_validate_client_type");
      if ( ipa3_get_ipc_logbuf_low() )
        goto LABEL_11;
    }
    else if ( ipa3_get_ipc_logbuf_low() )
    {
LABEL_11:
      v7 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v7, "ipa_wigig %s:%d invalid client type %d\n", "ipa_wigig_validate_client_type", 1722, a1);
      return 4294967274LL;
    }
    return 4294967274LL;
  }
  result = ipa_tx_dp(a1, a2, nullptr);
  if ( !(_DWORD)result )
  {
    result = ipa3_get_ipc_logbuf_low();
    if ( result )
    {
      v6 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v6, "ipa_wigig %s:%d exit\n", "ipa_wigig_tx_dp", 1910);
      return 0;
    }
  }
  return result;
}
