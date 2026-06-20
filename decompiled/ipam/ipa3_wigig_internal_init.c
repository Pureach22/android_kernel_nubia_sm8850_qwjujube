__int64 __fastcall ipa3_wigig_internal_init(__int64 a1, __int64 a2, _QWORD *a3)
{
  __int64 v5; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x8
  __int64 v13; // x10
  int v14; // w21
  int reg_base; // w20
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 result; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0

  v5 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d \n", "ipa3_wigig_internal_init", 111);
      v5 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v5 + 34160);
    if ( v8 )
      ipc_log_string(v8, "ipa %s:%d \n", "ipa3_wigig_internal_init", 111);
  }
  if ( !a1 )
  {
    printk(&unk_3E74FD, "ipa3_wigig_internal_init");
    v19 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v20 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v20 )
      {
        ipc_log_string(v20, "ipa %s:%d inout is NULL", "ipa3_wigig_internal_init", 114);
        v19 = ipa3_ctx;
      }
      v21 = *(_QWORD *)(v19 + 34160);
      if ( v21 )
        ipc_log_string(v21, "ipa %s:%d inout is NULL", "ipa3_wigig_internal_init", 114);
    }
    return 4294967274LL;
  }
  if ( !a2 )
  {
    printk(&unk_3E7517, "ipa3_wigig_internal_init");
    v22 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v23 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d int_notify is NULL", "ipa3_wigig_internal_init", 119);
        v22 = ipa3_ctx;
      }
      v24 = *(_QWORD *)(v22 + 34160);
      if ( v24 )
        ipc_log_string(v24, "ipa %s:%d int_notify is NULL", "ipa3_wigig_internal_init", 119);
    }
    return 4294967274LL;
  }
  v9 = ipa3_uc_state_check();
  if ( (_DWORD)v9 )
  {
    *(_BYTE *)a1 = 0;
    v12 = ipa3_ctx;
    *(_QWORD *)(ipa3_ctx + 43240) = *(_QWORD *)(a1 + 16);
  }
  else
  {
    *(_BYTE *)a1 = 1;
    v12 = ipa3_ctx;
  }
  v13 = *(_QWORD *)(a1 + 8);
  v14 = *(_DWORD *)(v12 + 28640);
  *(_QWORD *)(v12 + 43232) = v13;
  *(_QWORD *)(v12 + 43248) = a2;
  reg_base = ipahal_get_reg_base(v9, v10, v11);
  *a3 = reg_base
      + (unsigned int)((__int64 (__fastcall *)(__int64, __int64, __int64))ipahal_get_reg_mn_ofst)(66, 1, 1)
      + v14;
  v16 = ipa3_ctx;
  if ( !ipa3_ctx )
    return 0;
  v17 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v17 )
  {
    ipc_log_string(v17, "ipa %s:%d exit\n", "ipa3_wigig_internal_init", 140);
    v16 = ipa3_ctx;
  }
  result = *(_QWORD *)(v16 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_wigig_internal_init", 140);
    return 0;
  }
  return result;
}
