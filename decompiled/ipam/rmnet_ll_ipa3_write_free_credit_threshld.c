__int64 __fastcall rmnet_ll_ipa3_write_free_credit_threshld(__int64 a1, __int64 a2, unsigned __int64 a3)
{
  __int64 v3; // x19
  int v4; // w0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  int v11; // [xsp+4h] [xbp-Ch] BYREF
  __int64 v12; // [xsp+8h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v11 = 0;
  if ( a3 > 0x1000 )
  {
    v3 = -14;
    goto LABEL_5;
  }
  v3 = a3;
  v4 = kstrtouint_from_user(a2, a3, 0, &v11);
  if ( v4 )
  {
    v3 = v4;
    goto LABEL_5;
  }
  if ( (unsigned int)(v11 - 1) > 0x7F )
  {
    printk(&unk_3A31F8, "rmnet_ll_ipa3_write_free_credit_threshld");
    v6 = ipa3_ctx;
    if ( !ipa3_ctx )
      goto LABEL_5;
    v9 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v9 )
    {
      ipc_log_string(v9, "ipa %s:%d Invalid value \n", "rmnet_ll_ipa3_write_free_credit_threshld", 165);
      v6 = ipa3_ctx;
    }
    v10 = *(_QWORD *)(v6 + 34160);
    if ( !v10 )
      goto LABEL_9;
    ipc_log_string(v10, "ipa %s:%d Invalid value \n", "rmnet_ll_ipa3_write_free_credit_threshld", 165);
  }
  else
  {
    *(_DWORD *)(rmnet_ll_ipa3_ctx + 644) = v11;
  }
  v6 = ipa3_ctx;
LABEL_9:
  if ( v6 )
  {
    v7 = *(_QWORD *)(v6 + 34152);
    if ( v7 )
    {
      ipc_log_string(
        v7,
        "ipa %s:%d Updated free credit threshold = %d",
        "rmnet_ll_ipa3_write_free_credit_threshld",
        168,
        *(_DWORD *)(rmnet_ll_ipa3_ctx + 644));
      v6 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v6 + 34160);
    if ( v8 )
      ipc_log_string(
        v8,
        "ipa %s:%d Updated free credit threshold = %d",
        "rmnet_ll_ipa3_write_free_credit_threshld",
        168,
        *(_DWORD *)(rmnet_ll_ipa3_ctx + 644));
  }
LABEL_5:
  _ReadStatusReg(SP_EL0);
  return v3;
}
