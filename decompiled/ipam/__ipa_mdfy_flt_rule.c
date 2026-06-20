__int64 __fastcall _ipa_mdfy_flt_rule(_BYTE *a1, unsigned int a2)
{
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x21
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  _QWORD v16[2]; // [xsp+0h] [xbp-10h] BYREF

  v16[1] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = *(unsigned int *)a1;
  v16[0] = 0;
  v5 = ipa3_id_find(v4);
  if ( !v5 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_mdfy_flt_rule__rs, "__ipa_mdfy_flt_rule") )
      printk(&unk_3DE445, "__ipa_mdfy_flt_rule");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d lookup failed\n", "__ipa_mdfy_flt_rule", 1167);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        ipc_log_string(v12, "ipa %s:%d lookup failed\n", "__ipa_mdfy_flt_rule", 1167);
    }
    goto LABEL_24;
  }
  if ( *(_DWORD *)(v5 + 16) != 1468208646 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_mdfy_flt_rule__rs_216, "__ipa_mdfy_flt_rule") )
      printk(&unk_3EC4EF, "__ipa_mdfy_flt_rule");
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d bad params\n", "__ipa_mdfy_flt_rule", 1172);
        v13 = ipa3_ctx;
      }
      v15 = *(_QWORD *)(v13 + 34160);
      if ( v15 )
        ipc_log_string(v15, "ipa %s:%d bad params\n", "__ipa_mdfy_flt_rule", 1172);
    }
    goto LABEL_24;
  }
  v6 = v5;
  if ( (unsigned int)_ipa_validate_flt_rule(a1 + 8, v16, a2) )
  {
LABEL_24:
    result = 0xFFFFFFFFLL;
    goto LABEL_25;
  }
  v7 = *(_QWORD *)(v6 + 400);
  if ( v7 )
    --*(_DWORD *)(v7 + 80);
  memcpy((void *)(v6 + 20), a1 + 8, 0x170u);
  v8 = v16[0];
  *(_QWORD *)(v6 + 400) = v16[0];
  if ( v8 )
    ++*(_DWORD *)(v8 + 80);
  *(_DWORD *)(v6 + 408) = 0;
  *(_WORD *)(v6 + 416) = 0;
  result = 0;
  if ( a1[368] )
    *(_BYTE *)(v6 + 420) = a1[369];
  else
    *(_BYTE *)(v6 + 420) = 0;
LABEL_25:
  _ReadStatusReg(SP_EL0);
  return result;
}
