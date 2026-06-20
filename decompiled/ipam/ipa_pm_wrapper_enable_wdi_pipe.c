__int64 __fastcall ipa_pm_wrapper_enable_wdi_pipe(unsigned __int64 a1)
{
  unsigned int v1; // w20
  __int64 result; // x0
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0

  if ( ipa_pm_wdi_ctx != 1 )
  {
    if ( (unsigned int)(ipa_pm_wdi_ctx - 4) < 2 || ipa_pm_wdi_ctx == 2 )
    {
      printk(&unk_3E1869, "ipa_pm_wrapper_enable_wdi_pipe");
      v3 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v4 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v4 )
        {
          ipc_log_string(v4, "ipa %s:%d Unexpected current ipa pm state\n", "ipa_pm_wrapper_enable_wdi_pipe", 3456);
          v3 = ipa3_ctx;
        }
        v5 = *(_QWORD *)(v3 + 34160);
        if ( v5 )
          ipc_log_string(v5, "ipa %s:%d Unexpected current ipa pm state\n", "ipa_pm_wrapper_enable_wdi_pipe", 3456);
      }
      return 4294967282LL;
    }
    v1 = a1;
    if ( (unsigned int)ipa_pm_activate_sync(dword_E784) )
    {
      printk(&unk_3BBCF9, "ipa_pm_wrapper_enable_wdi_pipe");
      v9 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v10 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v10 )
        {
          ipc_log_string(v10, "ipa %s:%d fail to activate ipa pm\n", "ipa_pm_wrapper_enable_wdi_pipe", 3462);
          v9 = ipa3_ctx;
        }
        v11 = *(_QWORD *)(v9 + 34160);
        if ( v11 )
          ipc_log_string(v11, "ipa %s:%d fail to activate ipa pm\n", "ipa_pm_wrapper_enable_wdi_pipe", 3462);
      }
      return 4294967282LL;
    }
    a1 = v1;
    ipa_pm_wdi_ctx = 1;
  }
  result = ipa_enable_wdi_pipe((_QWORD *)a1);
  if ( (_DWORD)result )
  {
    printk(&unk_3B5A7D, "ipa_pm_wrapper_enable_wdi_pipe");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d fail to enable wdi pipe\n", "ipa_pm_wrapper_enable_wdi_pipe", 3469);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(v8, "ipa %s:%d fail to enable wdi pipe\n", "ipa_pm_wrapper_enable_wdi_pipe", 3469);
    }
    return 4294967282LL;
  }
  return result;
}
