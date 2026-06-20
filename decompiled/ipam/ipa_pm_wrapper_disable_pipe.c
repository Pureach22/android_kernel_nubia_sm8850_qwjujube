__int64 __fastcall ipa_pm_wrapper_disable_pipe(_QWORD *a1)
{
  int v2; // w8
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0

  if ( (unsigned int)ipa_pm_wdi_ctx > 5 || ((1 << ipa_pm_wdi_ctx) & 0x31) == 0 )
  {
    if ( (unsigned int)ipa_disable_wdi_pipe(a1) )
    {
      printk(&unk_3EFBBB, "ipa_pm_wrapper_disable_pipe");
      v7 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v8 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v8 )
        {
          ipc_log_string(v8, "ipa %s:%d fail to disable wdi pipe\n", "ipa_pm_wrapper_disable_pipe", 3487);
          v7 = ipa3_ctx;
        }
        v9 = *(_QWORD *)(v7 + 34160);
        if ( v9 )
          ipc_log_string(v9, "ipa %s:%d fail to disable wdi pipe\n", "ipa_pm_wrapper_disable_pipe", 3487);
      }
      return 4294967282LL;
    }
    if ( ipa_pm_wdi_ctx == 2 )
    {
      if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)((unsigned int)dword_E784) )
      {
        printk(&unk_3D8FD8, "ipa_pm_wrapper_disable_pipe");
        v10 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v11 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v11 )
          {
            ipc_log_string(v11, "ipa %s:%d fail to deactivate ipa pm\n", "ipa_pm_wrapper_disable_pipe", 3496);
            v10 = ipa3_ctx;
          }
          v12 = *(_QWORD *)(v10 + 34160);
          if ( v12 )
            ipc_log_string(v12, "ipa %s:%d fail to deactivate ipa pm\n", "ipa_pm_wrapper_disable_pipe", 3496);
        }
        return 4294967282LL;
      }
      v2 = 3;
    }
    else
    {
      v2 = 2;
    }
    ipa_pm_wdi_ctx = v2;
    return 0;
  }
  printk(&unk_3E1869, "ipa_pm_wrapper_disable_pipe");
  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d Unexpected current ipa pm state\n", "ipa_pm_wrapper_disable_pipe", 3482);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d Unexpected current ipa pm state\n", "ipa_pm_wrapper_disable_pipe", 3482);
  }
  return 4294967282LL;
}
