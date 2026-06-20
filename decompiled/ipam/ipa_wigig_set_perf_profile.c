__int64 __fastcall ipa_wigig_set_perf_profile(unsigned int a1)
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v4; // x0
  long double v5; // q0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 result; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d setting throughput to %d\n", "ipa_wigig_set_perf_profile", 1493, a1);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d setting throughput to %d\n", "ipa_wigig_set_perf_profile", 1493, a1);
  }
  if ( ipa_wigig_ctx )
  {
    if ( ipa3_get_ipc_logbuf() )
    {
      v4 = ipa3_get_ipc_logbuf();
      ipc_log_string(
        v4,
        "ipa_wigig %s:%d ipa_pm handle %d\n",
        "ipa_wigig_set_perf_profile",
        1500,
        *(_DWORD *)(ipa_wigig_ctx + 64));
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v6 = ipa3_get_ipc_logbuf_low();
      v5 = ipc_log_string(
             v6,
             "ipa_wigig %s:%d ipa_pm handle %d\n",
             "ipa_wigig_set_perf_profile",
             1500,
             *(_DWORD *)(ipa_wigig_ctx + 64));
    }
    if ( (unsigned int)((__int64 (__fastcall *)(_QWORD, _QWORD, long double))ipa_pm_set_throughput)(
                         *(unsigned int *)(ipa_wigig_ctx + 64),
                         a1,
                         v5) )
    {
      printk(&unk_3B3B44, "ipa_wigig_set_perf_profile");
      if ( ipa3_get_ipc_logbuf() )
      {
        v12 = ipa3_get_ipc_logbuf();
        ipc_log_string(v12, "ipa_wigig %s:%d fail to setup pm perf profile\n", "ipa_wigig_set_perf_profile", 1503);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v13 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v13, "ipa_wigig %s:%d fail to setup pm perf profile\n", "ipa_wigig_set_perf_profile", 1503);
      }
      return 4294967282LL;
    }
    else
    {
      if ( ipa3_get_ipc_logbuf() )
      {
        v7 = ipa3_get_ipc_logbuf();
        ipc_log_string(v7, "ipa_wigig %s:%d exit\n", "ipa_wigig_set_perf_profile", 1506);
      }
      result = ipa3_get_ipc_logbuf_low();
      if ( result )
      {
        v9 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v9, "ipa_wigig %s:%d exit\n", "ipa_wigig_set_perf_profile", 1506);
        return 0;
      }
    }
  }
  else
  {
    printk(&unk_3CE6D1, "ipa_wigig_set_perf_profile");
    if ( ipa3_get_ipc_logbuf() )
    {
      v10 = ipa3_get_ipc_logbuf();
      ipc_log_string(v10, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_set_perf_profile", 1496);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v11 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v11, "ipa_wigig %s:%d wigig ctx is not initialized\n", "ipa_wigig_set_perf_profile", 1496);
    }
    return 0xFFFFFFFFLL;
  }
  return result;
}
