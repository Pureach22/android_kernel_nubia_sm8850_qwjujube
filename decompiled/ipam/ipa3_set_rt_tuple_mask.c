__int64 __fastcall ipa3_set_rt_tuple_mask(unsigned int a1, _DWORD *a2)
{
  _DWORD *v2; // x9
  unsigned int v3; // w10
  int v6; // w9
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 result; // x0
  int v15; // w9
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int128 v22; // [xsp+0h] [xbp-20h] BYREF
  __int64 v23; // [xsp+10h] [xbp-10h]
  __int64 v24; // [xsp+18h] [xbp-8h]

  v24 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  if ( !a2 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_set_rt_tuple_mask__rs, "ipa3_set_rt_tuple_mask") )
      printk(&unk_3CC90B, "ipa3_set_rt_tuple_mask");
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d bad tuple\n", "ipa3_set_rt_tuple_mask", 2375);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
        ipc_log_string(v10, "ipa %s:%d bad tuple\n", "ipa3_set_rt_tuple_mask", 2375);
    }
    goto LABEL_25;
  }
  v2 = **(_DWORD ***)(ipa3_ctx + 34176);
  v3 = v2[24];
  if ( v3 <= v2[13] )
    v3 = v2[13];
  if ( (a1 & 0x80000000) != 0 || v3 <= a1 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_set_rt_tuple_mask__rs_115, "ipa3_set_rt_tuple_mask") )
    {
      printk(&unk_3ECABA, "ipa3_set_rt_tuple_mask");
      v11 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_25;
    }
    else
    {
      v11 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_25;
    }
    v12 = *(_QWORD *)(v11 + 34152);
    if ( v12 )
    {
      ipc_log_string(v12, "ipa %s:%d bad table index\n", "ipa3_set_rt_tuple_mask", 2383);
      v11 = ipa3_ctx;
    }
    v13 = *(_QWORD *)(v11 + 34160);
    if ( v13 )
      ipc_log_string(v13, "ipa %s:%d bad table index\n", "ipa3_set_rt_tuple_mask", 2383);
    goto LABEL_25;
  }
  if ( v2[14] <= a1 && v2[15] >= a1 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_set_rt_tuple_mask__rs_118, "ipa3_set_rt_tuple_mask") )
    {
      printk(&unk_3D0322, "ipa3_set_rt_tuple_mask");
      v16 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_25;
    }
    else
    {
      v16 = ipa3_ctx;
      if ( !ipa3_ctx )
        goto LABEL_25;
    }
    v17 = *(_QWORD *)(v16 + 34152);
    if ( v17 )
    {
      ipc_log_string(v17, "ipa %s:%d cannot configure modem v4 rt tuple by AP\n", "ipa3_set_rt_tuple_mask", 2389);
      v16 = ipa3_ctx;
    }
    v18 = *(_QWORD *)(v16 + 34160);
    if ( v18 )
      ipc_log_string(v18, "ipa %s:%d cannot configure modem v4 rt tuple by AP\n", "ipa3_set_rt_tuple_mask", 2389);
    goto LABEL_25;
  }
  if ( v2[25] <= a1 && v2[26] >= a1 )
  {
    if ( (unsigned int)__ratelimit(&ipa3_set_rt_tuple_mask__rs_121, "ipa3_set_rt_tuple_mask") )
    {
      printk(&unk_3CD1BC, "ipa3_set_rt_tuple_mask");
      v19 = ipa3_ctx;
      if ( ipa3_ctx )
        goto LABEL_37;
    }
    else
    {
      v19 = ipa3_ctx;
      if ( ipa3_ctx )
      {
LABEL_37:
        v20 = *(_QWORD *)(v19 + 34152);
        if ( v20 )
        {
          ipc_log_string(v20, "ipa %s:%d cannot configure modem v6 rt tuple by AP\n", "ipa3_set_rt_tuple_mask", 2395);
          v19 = ipa3_ctx;
        }
        v21 = *(_QWORD *)(v19 + 34160);
        if ( v21 )
          ipc_log_string(v21, "ipa %s:%d cannot configure modem v6 rt tuple by AP\n", "ipa3_set_rt_tuple_mask", 2395);
      }
    }
LABEL_25:
    result = 4294967274LL;
    goto LABEL_26;
  }
  if ( *(_DWORD *)(ipa3_ctx + 32240) < 0x15u )
  {
    v23 = 0;
    v22 = 0u;
    ipahal_read_reg_n_fields(75, a1, &v22);
    v15 = *(_DWORD *)((char *)a2 + 3);
    v7 = 75;
    *(_DWORD *)((char *)&v22 + 7) = *a2;
    *(_DWORD *)((char *)&v22 + 10) = v15;
  }
  else
  {
    DWORD2(v22) = 0;
    *(_QWORD *)&v22 = 0;
    ipahal_read_reg_n_fields(142, a1, &v22);
    v6 = *(_DWORD *)((char *)a2 + 3);
    v7 = 142;
    LODWORD(v22) = *a2;
    *(_DWORD *)((char *)&v22 + 3) = v6;
  }
  ((void (__fastcall *)(__int64, _QWORD, __int128 *))ipahal_write_reg_n_fields)(v7, a1, &v22);
  result = 0;
LABEL_26:
  _ReadStatusReg(SP_EL0);
  return result;
}
