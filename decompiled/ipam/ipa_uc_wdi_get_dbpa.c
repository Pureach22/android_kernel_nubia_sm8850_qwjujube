__int64 __fastcall ipa_uc_wdi_get_dbpa(_DWORD *a1, __int64 a2, __int64 a3)
{
  int v4; // w21
  int v5; // w20
  int v6; // w20
  __int64 v7; // x2
  int v8; // w8
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0

  if ( a1 && (v4 = *a1, *a1 < 0x86u) )
  {
    v5 = *(_DWORD *)(ipa3_ctx + 28640);
    v6 = ipahal_get_reg_base(a1, a2, a3) + v5;
    if ( (v4 & 1) != 0 )
      v7 = 18;
    else
      v7 = 16;
    v8 = ((__int64 (__fastcall *)(__int64, __int64, __int64))ipahal_get_reg_mn_ofst)(66, 1, v7);
    result = 0;
    *((_QWORD *)a1 + 1) = (unsigned int)(v6 + v8);
  }
  else
  {
    printk(&unk_3A44FF, "ipa_uc_wdi_get_dbpa");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d bad parm. param=%pK ", "ipa_uc_wdi_get_dbpa", 3250, a1);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        ipc_log_string(v12, "ipa %s:%d bad parm. param=%pK ", "ipa_uc_wdi_get_dbpa", 3250, a1);
    }
    if ( a1 )
    {
      printk(&unk_3B8B46, "ipa_uc_wdi_get_dbpa");
      v13 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v14 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v14 )
        {
          ipc_log_string(v14, "ipa %s:%d client = %d\n", "ipa_uc_wdi_get_dbpa", 3252, *a1);
          v13 = ipa3_ctx;
        }
        v15 = *(_QWORD *)(v13 + 34160);
        if ( v15 )
          ipc_log_string(v15, "ipa %s:%d client = %d\n", "ipa_uc_wdi_get_dbpa", 3252, *a1);
      }
    }
    return 4294967274LL;
  }
  return result;
}
