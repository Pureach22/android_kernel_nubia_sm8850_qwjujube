__int64 __fastcall ipa_pm_wrapper_disconnect_wdi_pipe(_QWORD *a1)
{
  int v1; // w8
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

  if ( (unsigned int)(ipa_pm_wdi_ctx - 1) <= 1 )
  {
    printk(&unk_3E1869, "ipa_pm_wrapper_disconnect_wdi_pipe");
    v3 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v4 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v4 )
      {
        ipc_log_string(v4, "ipa %s:%d Unexpected current ipa pm state\n", "ipa_pm_wrapper_disconnect_wdi_pipe", 3427);
        v3 = ipa3_ctx;
      }
      v5 = *(_QWORD *)(v3 + 34160);
      if ( v5 )
        ipc_log_string(v5, "ipa %s:%d Unexpected current ipa pm state\n", "ipa_pm_wrapper_disconnect_wdi_pipe", 3427);
    }
    return 4294967282LL;
  }
  if ( (unsigned int)ipa_disconnect_wdi_pipe(a1) )
  {
    printk(&unk_3E7086, "ipa_pm_wrapper_disconnect_wdi_pipe");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d fail to tear down pipe\n", "ipa_pm_wrapper_disconnect_wdi_pipe", 3431);
        v6 = ipa3_ctx;
      }
      v8 = *(_QWORD *)(v6 + 34160);
      if ( v8 )
        ipc_log_string(v8, "ipa %s:%d fail to tear down pipe\n", "ipa_pm_wrapper_disconnect_wdi_pipe", 3431);
    }
    return 4294967282LL;
  }
  if ( ipa_pm_wdi_ctx != 4 )
  {
    v1 = 4;
    goto LABEL_7;
  }
  if ( (unsigned int)((__int64 (__fastcall *)(_QWORD))ipa_pm_deregister)((unsigned int)dword_E784) )
  {
    printk(&unk_3D8FB1, "ipa_pm_wrapper_disconnect_wdi_pipe");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d fail to deregister ipa pm\n", "ipa_pm_wrapper_disconnect_wdi_pipe", 3440);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d fail to deregister ipa pm\n", "ipa_pm_wrapper_disconnect_wdi_pipe", 3440);
    }
    return 4294967282LL;
  }
  v1 = 5;
LABEL_7:
  result = 0;
  ipa_pm_wdi_ctx = v1;
  return result;
}
