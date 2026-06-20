__int64 __fastcall ipa_wigig_disable_pipe(unsigned int a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 result; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d \n", "ipa_wigig_disable_pipe", 1872);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d \n", "ipa_wigig_disable_pipe", 1872);
  }
  if ( a1 - 86 > 7 || ((1 << (a1 - 86)) & 0xAB) == 0 )
  {
    if ( (unsigned int)__ratelimit(&ipa_wigig_validate_client_type__rs, "ipa_wigig_validate_client_type") )
    {
      printk(&unk_3AE73D, "ipa_wigig_validate_client_type");
      if ( !ipa3_get_ipc_logbuf_low() )
        return 4294967274LL;
    }
    else if ( !ipa3_get_ipc_logbuf_low() )
    {
      return 4294967274LL;
    }
    v7 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v7, "ipa_wigig %s:%d invalid client type %d\n", "ipa_wigig_validate_client_type", 1722, a1);
    return 4294967274LL;
  }
  result = ipa3_disable_wigig_pipe_i(a1);
  if ( !(_DWORD)result )
  {
    if ( a1 == 86
      && (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(ipa_wigig_ctx + 64)) )
    {
      printk(&unk_3BCD17, "ipa_wigig_disable_pipe");
      if ( ipa3_get_ipc_logbuf() )
      {
        v8 = ipa3_get_ipc_logbuf();
        ipc_log_string(v8, "ipa_wigig %s:%d fail to deactivate ipa pm\n", "ipa_wigig_disable_pipe", 1886);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v9 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v9, "ipa_wigig %s:%d fail to deactivate ipa pm\n", "ipa_wigig_disable_pipe", 1886);
      }
      return 4294967282LL;
    }
    else
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v5 = ipa3_get_ipc_logbuf();
        ipc_log_string(v5, "ipa_wigig %s:%d exit\n", "ipa_wigig_disable_pipe", 1891);
      }
      result = ipa3_get_ipc_logbuf_low();
      if ( result )
      {
        v6 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v6, "ipa_wigig %s:%d exit\n", "ipa_wigig_disable_pipe", 1891);
        return 0;
      }
    }
  }
  return result;
}
