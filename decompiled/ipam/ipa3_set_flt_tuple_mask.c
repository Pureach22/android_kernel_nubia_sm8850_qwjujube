__int64 __fastcall ipa3_set_flt_tuple_mask(unsigned int a1, int *a2)
{
  int v4; // w8
  int v5; // w9
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  __int64 v20; // [xsp+0h] [xbp-20h] BYREF
  __int64 v21; // [xsp+8h] [xbp-18h]
  __int64 v22; // [xsp+10h] [xbp-10h]
  __int64 v23; // [xsp+18h] [xbp-8h]

  v23 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_set_flt_tuple_mask__rs, "ipa3_set_flt_tuple_mask") )
      printk(&unk_3CC90B, "ipa3_set_flt_tuple_mask");
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d bad tuple\n", "ipa3_set_flt_tuple_mask", 2105);
        v7 = ipa3_ctx;
      }
      v9 = *(_QWORD *)(v7 + 34160);
      if ( v9 )
        ipc_log_string(v9, "ipa %s:%d bad tuple\n", "ipa3_set_flt_tuple_mask", 2105);
    }
    goto LABEL_15;
  }
  if ( (a1 & 0x80000000) != 0 || *(_DWORD *)(ipa3_ctx + 34308) <= a1 )
  {
    printk(&unk_3F5323, "ipa3_set_flt_tuple_mask");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d bad pipe index!\n", "ipa3_set_flt_tuple_mask", 2110);
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
        ipc_log_string(v13, "ipa %s:%d bad pipe index!\n", "ipa3_set_flt_tuple_mask", 2110);
    }
    goto LABEL_15;
  }
  if ( (ipa_is_ep_support_flt(a1) & 1) == 0 )
  {
    printk(&unk_3E3B88, "ipa3_set_flt_tuple_mask");
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d pipe %d not filtering pipe\n", "ipa3_set_flt_tuple_mask", 2115, a1);
        v14 = ipa3_ctx;
      }
      v16 = *(_QWORD *)(v14 + 34160);
      if ( v16 )
        ipc_log_string(v16, "ipa %s:%d pipe %d not filtering pipe\n", "ipa3_set_flt_tuple_mask", 2115, a1);
    }
    goto LABEL_15;
  }
  if ( (ipa_is_modem_pipe(a1) & 1) != 0 )
  {
    printk(&unk_3F21AA, "ipa3_set_flt_tuple_mask");
    v17 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v18 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v18 )
      {
        ipc_log_string(v18, "ipa %s:%d modem pipe tuple is not configured by AP\n", "ipa3_set_flt_tuple_mask", 2120);
        v17 = ipa3_ctx;
      }
      v19 = *(_QWORD *)(v17 + 34160);
      if ( v19 )
        ipc_log_string(v19, "ipa %s:%d modem pipe tuple is not configured by AP\n", "ipa3_set_flt_tuple_mask", 2120);
    }
LABEL_15:
    result = 4294967274LL;
    goto LABEL_18;
  }
  if ( *(_DWORD *)(ipa3_ctx + 32240) < 0x15u )
  {
    v21 = 0;
    v22 = 0;
    v20 = 0;
    ipahal_read_reg_n_fields(75, a1, &v20);
    v4 = *a2;
    v5 = *(int *)((char *)a2 + 3);
    v6 = 75;
  }
  else
  {
    LODWORD(v21) = 0;
    v20 = 0;
    ipahal_read_reg_n_fields(141, a1, &v20);
    v4 = *a2;
    v5 = *(int *)((char *)a2 + 3);
    v6 = 141;
  }
  LODWORD(v20) = v4;
  *(_DWORD *)((char *)&v20 + 3) = v5;
  ((void (__fastcall *)(__int64, _QWORD, __int64 *))ipahal_write_reg_n_fields)(v6, a1, &v20);
  result = 0;
LABEL_18:
  _ReadStatusReg(SP_EL0);
  return result;
}
