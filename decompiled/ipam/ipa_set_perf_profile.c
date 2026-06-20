__int64 __fastcall ipa_set_perf_profile(_DWORD *a1)
{
  __int64 v2; // x0
  long double v3; // q0
  __int64 v4; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v8; // x0
  __int64 v9; // x0

  if ( !a1 )
  {
    printk(&unk_3DCF11, "ipa_set_perf_profile");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_uc_offload %s:%d Invalid input\n", "ipa_set_perf_profile", 715);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_uc_offload %s:%d Invalid input\n", "ipa_set_perf_profile", 715);
    }
    return 4294967274LL;
  }
  if ( (*a1 & 0xFFFFFFFE) != 0x30 )
  {
    printk(&unk_3D1300, "ipa_set_perf_profile");
    if ( ipa3_get_ipc_logbuf() )
    {
      v8 = ipa3_get_ipc_logbuf();
      ipc_log_string(v8, "ipa_uc_offload %s:%d not supported\n", "ipa_set_perf_profile", 721);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v9 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v9, "ipa_uc_offload %s:%d not supported\n", "ipa_set_perf_profile", 721);
    }
    return 4294967274LL;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v2 = ipa3_get_ipc_logbuf();
    ipc_log_string(v2, "ipa_uc_offload %s:%d setting throughput to %d\n", "ipa_set_perf_profile", 726, a1[2]);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v4 = ipa3_get_ipc_logbuf_low();
    v3 = ipc_log_string(v4, "ipa_uc_offload %s:%d setting throughput to %d\n", "ipa_set_perf_profile", 726, a1[2]);
  }
  return ((__int64 (__fastcall *)(_QWORD, _QWORD, long double))ipa_pm_set_throughput)(
           *(unsigned int *)(qword_203E30 + 104),
           (unsigned int)a1[2],
           v3);
}
