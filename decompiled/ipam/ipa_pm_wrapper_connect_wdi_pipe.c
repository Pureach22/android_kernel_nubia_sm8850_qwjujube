__int64 __fastcall ipa_pm_wrapper_connect_wdi_pipe(__int64 a1, _DWORD *a2)
{
  __int64 v2; // x20
  _DWORD *v3; // x21
  __int64 result; // x0
  const void *v5; // x20
  const void *v6; // x19
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  const char *v19; // [xsp+8h] [xbp-28h] BYREF
  __int64 (__fastcall *v20)(); // [xsp+10h] [xbp-20h]
  __int64 v21; // [xsp+18h] [xbp-18h]
  __int64 v22; // [xsp+20h] [xbp-10h]
  __int64 v23; // [xsp+28h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v21 = 0;
  v22 = 0;
  v19 = nullptr;
  v20 = nullptr;
  if ( !a1 || !a2 )
  {
    v5 = (const void *)a1;
    v6 = a2;
    printk(&unk_3C4D9A, "ipa_pm_wrapper_connect_wdi_pipe");
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(
          v8,
          "ipa %s:%d empty parameters. in=%pK out=%pK\n",
          "ipa_pm_wrapper_connect_wdi_pipe",
          3389,
          v5,
          v6);
        v7 = ipa3_ctx;
      }
      v9 = *(_QWORD *)(v7 + 34160);
      if ( v9 )
      {
        ipc_log_string(
          v9,
          "ipa %s:%d empty parameters. in=%pK out=%pK\n",
          "ipa_pm_wrapper_connect_wdi_pipe",
          3389,
          v5,
          v6);
        result = 4294967274LL;
        goto LABEL_8;
      }
    }
LABEL_24:
    result = 4294967274LL;
    goto LABEL_8;
  }
  if ( !ipa_pm_wdi_ctx )
    goto LABEL_7;
  if ( ipa_pm_wdi_ctx != 5 )
  {
    printk(&unk_3E1869, "ipa_pm_wrapper_connect_wdi_pipe");
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d Unexpected current ipa pm state\n", "ipa_pm_wrapper_connect_wdi_pipe", 3394);
        v13 = ipa3_ctx;
      }
      v15 = *(_QWORD *)(v13 + 34160);
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d Unexpected current ipa pm state\n", "ipa_pm_wrapper_connect_wdi_pipe", 3394);
        result = 4294967274LL;
        goto LABEL_8;
      }
    }
    goto LABEL_24;
  }
  v2 = a1;
  v3 = a2;
  v19 = "wdi";
  v20 = ipa_wdi_pm_wrapper_cb;
  v21 = 0;
  v22 = 0;
  if ( (unsigned int)ipa_pm_register((__int64)&v19, (unsigned int *)&dword_E784) )
  {
    printk(&unk_3D8F8C, "ipa_pm_wrapper_connect_wdi_pipe");
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d fail to register ipa pm\n", "ipa_pm_wrapper_connect_wdi_pipe", 3405);
        v16 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v16 + 34160);
      if ( v18 )
        ipc_log_string(v18, "ipa %s:%d fail to register ipa pm\n", "ipa_pm_wrapper_connect_wdi_pipe", 3405);
    }
    goto LABEL_30;
  }
  a2 = v3;
  a1 = v2;
  ipa_pm_wdi_ctx = 0;
LABEL_7:
  result = ipa_connect_wdi_pipe(a1, a2);
  if ( (_DWORD)result )
  {
    printk(&unk_3ECDEA, "ipa_pm_wrapper_connect_wdi_pipe");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d fail to setup pipe\n", "ipa_pm_wrapper_connect_wdi_pipe", 3413);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        ipc_log_string(v12, "ipa %s:%d fail to setup pipe\n", "ipa_pm_wrapper_connect_wdi_pipe", 3413);
    }
LABEL_30:
    result = 4294967282LL;
  }
LABEL_8:
  _ReadStatusReg(SP_EL0);
  return result;
}
