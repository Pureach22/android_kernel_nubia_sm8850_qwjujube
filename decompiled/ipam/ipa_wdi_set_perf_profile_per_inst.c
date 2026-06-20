__int64 __fastcall ipa_wdi_set_perf_profile_per_inst(unsigned int a1, __int64 a2)
{
  __int64 v2; // x8
  __int64 result; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x0

  if ( a2 )
  {
    if ( a1 >= 2 )
    {
      printk(&unk_3F6766, "ipa_wdi_set_perf_profile_per_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        ipc_logbuf = ipa3_get_ipc_logbuf();
        ipc_log_string(ipc_logbuf, "ipa_wdi %s:%d Invalid Handle %d\n", "ipa_wdi_set_perf_profile_per_inst", 948, a1);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          ipc_logbuf_low,
          "ipa_wdi %s:%d Invalid Handle %d\n",
          "ipa_wdi_set_perf_profile_per_inst",
          948,
          a1);
      }
      return 4294967282LL;
    }
    v2 = ipa_wdi_ctx_list[a1];
    if ( v2 )
    {
      if ( a1 != 1 || *(_DWORD *)(v2 + 144) > 1u )
      {
        if ( *(_BYTE *)(ipa3_ctx + 51102) == 1 )
        {
          result = ipa_pm_wrapper_wdi_set_perf_profile_internal(a2);
          if ( !(_DWORD)result )
            return result;
        }
        else
        {
          result = ((__int64 (__fastcall *)(_QWORD, _QWORD))ipa_pm_set_throughput)(
                     *(unsigned int *)(v2 + 176),
                     *(unsigned int *)(a2 + 4));
          if ( !(_DWORD)result )
            return result;
        }
        printk(&unk_3CB1EC, "ipa_wdi_set_perf_profile_per_inst");
        if ( ipa3_get_ipc_logbuf() )
        {
          v4 = ipa3_get_ipc_logbuf();
          ipc_log_string(v4, "ipa_wdi %s:%d fail to set pm throughput\n", "ipa_wdi_set_perf_profile_per_inst", 973);
        }
        if ( ipa3_get_ipc_logbuf_low() )
        {
          v5 = ipa3_get_ipc_logbuf_low();
          ipc_log_string(v5, "ipa_wdi %s:%d fail to set pm throughput\n", "ipa_wdi_set_perf_profile_per_inst", 973);
        }
        return 4294967282LL;
      }
      printk(&unk_3E2714, "ipa_wdi_set_perf_profile_per_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        v13 = ipa3_get_ipc_logbuf();
        ipc_log_string(
          v13,
          "ipa_wdi %s:%d More than one instance not supported for WDI ver = %d\n",
          "ipa_wdi_set_perf_profile_per_inst",
          961,
          *(_DWORD *)(qword_204E60 + 144));
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v14 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(
          v14,
          "ipa_wdi %s:%d More than one instance not supported for WDI ver = %d\n",
          "ipa_wdi_set_perf_profile_per_inst",
          961,
          *(_DWORD *)(qword_204E60 + 144));
      }
    }
    else
    {
      printk(&unk_3F0CD4, "ipa_wdi_set_perf_profile_per_inst");
      if ( ipa3_get_ipc_logbuf() )
      {
        v11 = ipa3_get_ipc_logbuf();
        ipc_log_string(v11, "ipa_wdi %s:%d wdi ctx is not initialized.\n", "ipa_wdi_set_perf_profile_per_inst", 953);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v12 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v12, "ipa_wdi %s:%d wdi ctx is not initialized.\n", "ipa_wdi_set_perf_profile_per_inst", 953);
      }
    }
    return 0xFFFFFFFFLL;
  }
  else
  {
    printk(&unk_3DA0CE, "ipa_wdi_set_perf_profile_per_inst");
    if ( ipa3_get_ipc_logbuf() )
    {
      v6 = ipa3_get_ipc_logbuf();
      ipc_log_string(v6, "ipa_wdi %s:%d Invalid input\n", "ipa_wdi_set_perf_profile_per_inst", 943);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v7 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v7, "ipa_wdi %s:%d Invalid input\n", "ipa_wdi_set_perf_profile_per_inst", 943);
    }
    return 4294967274LL;
  }
}
