__int64 __fastcall ipa_wigig_enable_pipe(unsigned int a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x0
  long double v5; // q0
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d \n", "ipa_wigig_enable_pipe", 1837);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d \n", "ipa_wigig_enable_pipe", 1837);
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
    v10 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v10, "ipa_wigig %s:%d invalid client type %d\n", "ipa_wigig_validate_client_type", 1722, a1);
    return 4294967274LL;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v4 = ipa3_get_ipc_logbuf();
    ipc_log_string(v4, "ipa_wigig %s:%d enabling pipe %d\n", "ipa_wigig_enable_pipe", 1843, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v6 = ipa3_get_ipc_logbuf_low();
    v5 = ipc_log_string(v6, "ipa_wigig %s:%d enabling pipe %d\n", "ipa_wigig_enable_pipe", 1843, a1);
  }
  result = ((__int64 (__fastcall *)(_QWORD, long double))ipa3_enable_wigig_pipe_i)(a1, v5);
  if ( !(_DWORD)result )
  {
    if ( a1 == 86 && (unsigned int)ipa_pm_activate_sync(*(_DWORD *)(ipa_wigig_ctx + 64)) )
    {
      printk(&unk_3BFA30, "ipa_wigig_enable_pipe");
      if ( ipa3_get_ipc_logbuf() )
      {
        v11 = ipa3_get_ipc_logbuf();
        ipc_log_string(v11, "ipa_wigig %s:%d fail to activate ipa pm\n", "ipa_wigig_enable_pipe", 1853);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v12 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v12, "ipa_wigig %s:%d fail to activate ipa pm\n", "ipa_wigig_enable_pipe", 1853);
      }
      ipa3_disable_wigig_pipe_i(0x56u);
      return 4294967282LL;
    }
    else
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v8 = ipa3_get_ipc_logbuf();
        ipc_log_string(v8, "ipa_wigig %s:%d exit\n", "ipa_wigig_enable_pipe", 1859);
      }
      result = ipa3_get_ipc_logbuf_low();
      if ( result )
      {
        v9 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v9, "ipa_wigig %s:%d exit\n", "ipa_wigig_enable_pipe", 1859);
        return 0;
      }
    }
  }
  return result;
}
