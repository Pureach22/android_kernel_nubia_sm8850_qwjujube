__int64 __fastcall ipa_bridge_set_perf_profile(unsigned int a1, unsigned int a2)
{
  __int64 v4; // x0
  __int64 v5; // x0
  unsigned int v6; // w22
  unsigned int v7; // w19
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v13; // x0
  __int64 v14; // x0

  if ( ipa_gsb_ctx )
  {
    if ( a1 >= 5 )
    {
      printk(&unk_3E7C9B, "ipa_bridge_set_perf_profile");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(ipc_logbuf, "ipa_gsb %s:%d invalid hdl: %d\n", "ipa_bridge_set_perf_profile", 1160, a1);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(ipc_logbuf_low, "ipa_gsb %s:%d invalid hdl: %d\n", "ipa_bridge_set_perf_profile", 1160, a1);
      }
      return (unsigned int)-22;
    }
    else
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v4 = ipa3_get_ipc_logbuf();
        ipc_log_string(v4, "ipa_gsb %s:%d client hdl: %d, BW: %d\n", "ipa_bridge_set_perf_profile", 1164, a1, a2);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v5 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v5, "ipa_gsb %s:%d client hdl: %d, BW: %d\n", "ipa_bridge_set_perf_profile", 1164, a1, a2);
      }
      v6 = a1;
      mutex_lock(ipa_gsb_ctx + 48LL * a1 + 136);
      v7 = ((__int64 (__fastcall *)(_QWORD, _QWORD))ipa_pm_set_throughput)(*(unsigned int *)(ipa_gsb_ctx + 396), a2);
      if ( v7 )
      {
        printk(&unk_3C8616, "ipa_bridge_set_perf_profile");
        if ( ipa3_get_ipc_logbuf() )
        {
          v13 = ipa3_get_ipc_logbuf();
          ipc_log_string(v13, "ipa_gsb %s:%d fail to set perf profile\n", "ipa_bridge_set_perf_profile", 1171);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v14 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v14, "ipa_gsb %s:%d fail to set perf profile\n", "ipa_bridge_set_perf_profile", 1171);
        }
      }
      mutex_unlock(ipa_gsb_ctx + 48LL * v6 + 136);
    }
  }
  else
  {
    printk(&unk_3C85BE, "ipa_bridge_set_perf_profile");
    if ( ipa3_get_ipc_logbuf() )
    {
      v9 = ipa3_get_ipc_logbuf();
      ipc_log_string(v9, "ipa_gsb %s:%d ipa_gsb_ctx was not initialized\n", "ipa_bridge_set_perf_profile", 1155);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v10 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v10, "ipa_gsb %s:%d ipa_gsb_ctx was not initialized\n", "ipa_bridge_set_perf_profile", 1155);
    }
    return (unsigned int)-14;
  }
  return v7;
}
