__int64 __fastcall ipa3_add_flt_rule_usr(__int64 a1, char a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 result; // x0
  unsigned __int64 v8; // x21
  __int64 v9; // x19
  int v10; // w8
  __int64 v11; // x0
  __int64 v12; // x1
  __int64 v13; // x3
  int v14; // w26
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x8
  __int64 v19; // x0
  __int64 v20; // x0
  __int64 v21; // x0
  unsigned int (__fastcall *v22)(_QWORD); // x8
  unsigned int v23; // w19
  _QWORD v24[48]; // [xsp+0h] [xbp-180h] BYREF

  v24[46] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  memset(v24, 0, 0x170u);
  if ( a1 && *(_BYTE *)(a1 + 13) && *(_DWORD *)(a1 + 4) < 2u )
  {
    mutex_lock(ipa3_ctx + 29472);
    if ( *(_BYTE *)(a1 + 13) )
    {
      v8 = 0;
      v9 = a1;
      do
      {
        if ( !*(_BYTE *)(a1 + 12) )
        {
          if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
            *(_BYTE *)(v9 + 370) = 0;
          memcpy(v24, (const void *)(v9 + 16), 0x168u);
          v11 = *(unsigned int *)(a1 + 4);
          v12 = *(unsigned int *)(a1 + 8);
          v13 = *(unsigned __int8 *)(v9 + 376);
          v24[45] = 0;
          v14 = _ipa_add_ep_flt_rule(v11, v12, v24, v13, v9 + 380, a2 & 1);
          memcpy((void *)(v9 + 16), v24, 0x168u);
          if ( !v14 )
          {
            v10 = 0;
            goto LABEL_16;
          }
        }
        if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_usr__rs_24, "ipa3_add_flt_rule_usr") )
        {
          printk(&unk_3A36F0, "ipa3_add_flt_rule_usr");
          v15 = ipa3_ctx;
          if ( ipa3_ctx )
          {
LABEL_23:
            v16 = *(_QWORD *)(v15 + 34152);
            if ( v16 )
            {
              ipc_log_string(v16, "ipa %s:%d failed to add flt rule %d\n", "ipa3_add_flt_rule_usr", 1378, v8);
              v15 = ipa3_ctx;
            }
            v17 = *(_QWORD *)(v15 + 34160);
            if ( v17 )
              ipc_log_string(v17, "ipa %s:%d failed to add flt rule %d\n", "ipa3_add_flt_rule_usr", 1378, v8);
          }
        }
        else
        {
          v15 = ipa3_ctx;
          if ( ipa3_ctx )
            goto LABEL_23;
        }
        v10 = -1;
LABEL_16:
        *(_DWORD *)(v9 + 384) = v10;
        ++v8;
        v9 += 372;
      }
      while ( v8 < *(unsigned __int8 *)(a1 + 13) );
    }
    if ( *(_BYTE *)(a1 + 12) )
    {
      if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_usr__rs_27, "ipa3_add_flt_rule_usr") )
      {
        printk(&unk_3B4EE9, "ipa3_add_flt_rule_usr");
        v18 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_33;
      }
      else
      {
        v18 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_33:
          v19 = *(_QWORD *)(v18 + 34152);
          if ( v19 )
          {
            ipc_log_string(v19, "ipa %s:%d no support for global filter rules\n", "ipa3_add_flt_rule_usr", 1386);
            v18 = ipa3_ctx;
          }
          v20 = *(_QWORD *)(v18 + 34160);
          if ( v20 )
            ipc_log_string(v20, "ipa %s:%d no support for global filter rules\n", "ipa3_add_flt_rule_usr", 1386);
        }
      }
    }
    else
    {
      if ( !*(_BYTE *)a1 )
        goto LABEL_42;
      v21 = *(unsigned int *)(a1 + 4);
      v22 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 112LL);
      if ( *((_DWORD *)v22 - 1) != 1856640366 )
        __break(0x8228u);
      if ( !v22(v21) )
      {
LABEL_42:
        v23 = 0;
        goto LABEL_43;
      }
    }
    v23 = -1;
LABEL_43:
    mutex_unlock(ipa3_ctx + 29472);
    result = v23;
    goto LABEL_12;
  }
  if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_usr__rs, "ipa3_add_flt_rule_usr") )
    printk(&unk_3FB3F2, "ipa3_add_flt_rule_usr");
  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d bad parm\n", "ipa3_add_flt_rule_usr", 1353);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d bad parm\n", "ipa3_add_flt_rule_usr", 1353);
  }
  result = 4294967274LL;
LABEL_12:
  _ReadStatusReg(SP_EL0);
  return result;
}
