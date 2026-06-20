__int64 __fastcall ipa_pm_wrapper_wdi_set_perf_profile_internal(__int64 a1)
{
  __int64 result; // x0
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v5; // x8
  __int64 v6; // x0
  __int64 v7; // x0

  if ( a1 )
  {
    result = ((__int64 (__fastcall *)(_QWORD, _QWORD))ipa_pm_set_throughput)(
               (unsigned int)dword_E784,
               *(unsigned int *)(a1 + 4));
    if ( (_DWORD)result )
    {
      printk(&unk_3DC01B, "ipa_pm_wrapper_wdi_set_perf_profile_internal");
      v5 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v6 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v6 )
        {
          ipc_log_string(
            v6,
            "ipa %s:%d fail to set pm throughput\n",
            "ipa_pm_wrapper_wdi_set_perf_profile_internal",
            3374);
          v5 = ipa3_ctx;
        }
        v7 = *(_QWORD *)(v5 + 34160);
        if ( v7 )
          ipc_log_string(
            v7,
            "ipa %s:%d fail to set pm throughput\n",
            "ipa_pm_wrapper_wdi_set_perf_profile_internal",
            3374);
      }
      return 4294967282LL;
    }
  }
  else
  {
    printk(&unk_3B0460, "ipa_pm_wrapper_wdi_set_perf_profile_internal");
    v2 = ipa3_ctx;
    if ( !ipa3_ctx )
      return 4294967274LL;
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d Invalid input\n", "ipa_pm_wrapper_wdi_set_perf_profile_internal", 3367);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d Invalid input\n", "ipa_pm_wrapper_wdi_set_perf_profile_internal", 3367);
      return 4294967274LL;
    }
    else
    {
      return 4294967274LL;
    }
  }
  return result;
}
