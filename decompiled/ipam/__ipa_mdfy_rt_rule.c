__int64 __fastcall _ipa_mdfy_rt_rule(_BYTE *a1)
{
  __int64 result; // x0
  __int64 v3; // x0
  __int64 v4; // x20
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  _DWORD *v20; // x8
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  __int64 v24; // x8
  __int64 v25; // x8
  __int64 v26; // x9
  __int64 v27; // [xsp+8h] [xbp-18h] BYREF
  _QWORD v28[2]; // [xsp+10h] [xbp-10h] BYREF

  v28[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v27 = 0;
  v28[0] = 0;
  if ( (unsigned int)_ipa_rt_validate_hndls(a1 + 8, v28, &v27) )
  {
LABEL_2:
    result = 0xFFFFFFFFLL;
    goto LABEL_3;
  }
  v3 = ipa3_id_find(*(unsigned int *)a1);
  if ( !v3 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_mdfy_rt_rule__rs, "__ipa_mdfy_rt_rule") )
      printk(&unk_3DE445, "__ipa_mdfy_rt_rule");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d lookup failed\n", "__ipa_mdfy_rt_rule", 2208);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d lookup failed\n", "__ipa_mdfy_rt_rule", 2208);
    }
    goto LABEL_2;
  }
  v4 = v3;
  if ( *(_DWORD *)(v3 + 16) != 1468208644 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_mdfy_rt_rule__rs_247, "__ipa_mdfy_rt_rule") )
      printk(&unk_3EC4EF, "__ipa_mdfy_rt_rule");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d bad params\n", "__ipa_mdfy_rt_rule", 2213);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d bad params\n", "__ipa_mdfy_rt_rule", 2213);
    }
    goto LABEL_2;
  }
  if ( (ipa3_check_idr_if_freed(v3) & 1) != 0 || strcmp((const char *)(*(_QWORD *)(v4 + 200) + 40LL), "ipa_dflt_rt") )
  {
    if ( *(_QWORD *)(v4 + 208) )
    {
      v5 = ipa3_id_find(*(unsigned int *)(v4 + 24));
      if ( !v5 || *(_DWORD *)(v5 + 16) != 1468208647 || (ipa3_check_idr_if_freed(*(_QWORD *)(v4 + 208)) & 1) != 0 )
      {
        if ( (unsigned int)__ratelimit(&_ipa_mdfy_rt_rule__rs_251, "__ipa_mdfy_rt_rule") )
          printk(&unk_3D352B, "__ipa_mdfy_rt_rule");
        v6 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v7 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v7 )
          {
            ipc_log_string(v7, "ipa %s:%d Header entry already deleted\n", "__ipa_mdfy_rt_rule", 2230);
            v6 = ipa3_ctx;
          }
          v8 = *(_QWORD *)(v6 + 34160);
          if ( v8 )
            ipc_log_string(v8, "ipa %s:%d Header entry already deleted\n", "__ipa_mdfy_rt_rule", 2230);
        }
        goto LABEL_2;
      }
    }
    else if ( *(_QWORD *)(v4 + 216) )
    {
      v15 = ipa3_id_find(*(unsigned int *)(v4 + 28));
      if ( !v15 || *(_DWORD *)(v15 + 16) != 1468208648 || (ipa3_check_idr_if_freed(*(_QWORD *)(v4 + 216)) & 1) != 0 )
      {
        if ( (unsigned int)__ratelimit(&_ipa_mdfy_rt_rule__rs_252, "__ipa_mdfy_rt_rule") )
          printk(&unk_3DEBEF, "__ipa_mdfy_rt_rule");
        v16 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v17 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v17 )
          {
            ipc_log_string(v17, "ipa %s:%d Proc header entry already deleted\n", "__ipa_mdfy_rt_rule", 2238);
            v16 = ipa3_ctx;
          }
          v18 = *(_QWORD *)(v16 + 34160);
          if ( v18 )
            ipc_log_string(v18, "ipa %s:%d Proc header entry already deleted\n", "__ipa_mdfy_rt_rule", 2238);
        }
        goto LABEL_2;
      }
    }
    v19 = *(_QWORD *)(v4 + 208);
    if ( v19 )
    {
      v20 = (_DWORD *)(v19 + 336);
    }
    else
    {
      v24 = *(_QWORD *)(v4 + 216);
      if ( !v24 )
      {
LABEL_57:
        memcpy((void *)(v4 + 20), a1 + 8, 0xB0u);
        v25 = v27;
        v26 = v28[0];
        *(_QWORD *)(v4 + 208) = v28[0];
        *(_QWORD *)(v4 + 216) = v25;
        if ( v26 )
        {
          ++*(_DWORD *)(v26 + 336);
          v25 = *(_QWORD *)(v4 + 216);
        }
        if ( v25 )
          ++*(_DWORD *)(v25 + 72);
        *(_DWORD *)(v4 + 224) = 0;
        *(_WORD *)(v4 + 232) = 0;
        result = 0;
        if ( a1[176] )
          *(_BYTE *)(v4 + 238) = a1[177];
        else
          *(_BYTE *)(v4 + 238) = 0;
        goto LABEL_3;
      }
      v20 = (_DWORD *)(v24 + 72);
    }
    --*v20;
    goto LABEL_57;
  }
  if ( (unsigned int)__ratelimit(&_ipa_mdfy_rt_rule__rs_248, "__ipa_mdfy_rt_rule") )
    printk(&unk_3E4251, "__ipa_mdfy_rt_rule");
  v21 = ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_53;
  v22 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v22 )
  {
    ipc_log_string(v22, "ipa %s:%d Default tbl rule cannot be modified\n", "__ipa_mdfy_rt_rule", 2219);
    v21 = ipa3_ctx;
  }
  v23 = *(_QWORD *)(v21 + 34160);
  if ( v23 )
  {
    ipc_log_string(v23, "ipa %s:%d Default tbl rule cannot be modified\n", "__ipa_mdfy_rt_rule", 2219);
    result = 4294967274LL;
  }
  else
  {
LABEL_53:
    result = 4294967274LL;
  }
LABEL_3:
  _ReadStatusReg(SP_EL0);
  return result;
}
