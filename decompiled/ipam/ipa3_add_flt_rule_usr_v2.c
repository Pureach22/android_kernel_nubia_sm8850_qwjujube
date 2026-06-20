__int64 __fastcall ipa3_add_flt_rule_usr_v2(__int64 a1, char a2)
{
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v8; // x27
  unsigned __int64 v9; // x21
  int v10; // w8
  __int64 v11; // x9
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  unsigned int (__fastcall *v19)(_QWORD); // x8
  unsigned int v20; // w19

  if ( a1 && *(_BYTE *)(a1 + 13) && *(_DWORD *)(a1 + 4) < 2u )
  {
    mutex_lock(ipa3_ctx + 29472);
    if ( *(_BYTE *)(a1 + 13) )
    {
      v8 = 0;
      v9 = 0;
      do
      {
        if ( !*(_BYTE *)(a1 + 12) )
        {
          if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
            *(_BYTE *)(*(_QWORD *)(a1 + 32) + v8 + 366) = 0;
          if ( !(unsigned int)_ipa_add_ep_flt_rule(
                                *(unsigned int *)(a1 + 4),
                                *(unsigned int *)(a1 + 8),
                                *(_QWORD *)(a1 + 32) + v8 + 12,
                                *(unsigned __int8 *)(*(_QWORD *)(a1 + 32) + v8),
                                *(_QWORD *)(a1 + 32) + v8 + 4,
                                a2 & 1) )
          {
            v10 = 0;
            goto LABEL_15;
          }
        }
        if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_usr_v2__rs_30, "ipa3_add_flt_rule_usr_v2") )
        {
          printk(&unk_3A36F0, "ipa3_add_flt_rule_usr_v2");
          v12 = ipa3_ctx;
          if ( ipa3_ctx )
          {
LABEL_22:
            v13 = *(_QWORD *)(v12 + 34152);
            if ( v13 )
            {
              ipc_log_string(v13, "ipa %s:%d failed to add flt rule %d\n", "ipa3_add_flt_rule_usr_v2", 1447, v9);
              v12 = ipa3_ctx;
            }
            v14 = *(_QWORD *)(v12 + 34160);
            if ( v14 )
              ipc_log_string(v14, "ipa %s:%d failed to add flt rule %d\n", "ipa3_add_flt_rule_usr_v2", 1447, v9);
          }
        }
        else
        {
          v12 = ipa3_ctx;
          if ( ipa3_ctx )
            goto LABEL_22;
        }
        v10 = -1;
LABEL_15:
        ++v9;
        v11 = *(_QWORD *)(a1 + 32) + v8;
        v8 += 380;
        *(_DWORD *)(v11 + 8) = v10;
      }
      while ( v9 < *(unsigned __int8 *)(a1 + 13) );
    }
    if ( *(_BYTE *)(a1 + 12) )
    {
      if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_usr_v2__rs_31, "ipa3_add_flt_rule_usr_v2") )
      {
        printk(&unk_3B4EE9, "ipa3_add_flt_rule_usr_v2");
        v15 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_32;
      }
      else
      {
        v15 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_32:
          v16 = *(_QWORD *)(v15 + 34152);
          if ( v16 )
          {
            ipc_log_string(v16, "ipa %s:%d no support for global filter rules\n", "ipa3_add_flt_rule_usr_v2", 1457);
            v15 = ipa3_ctx;
          }
          v17 = *(_QWORD *)(v15 + 34160);
          if ( v17 )
            ipc_log_string(v17, "ipa %s:%d no support for global filter rules\n", "ipa3_add_flt_rule_usr_v2", 1457);
        }
      }
    }
    else
    {
      if ( !*(_BYTE *)a1 )
        goto LABEL_41;
      v18 = *(unsigned int *)(a1 + 4);
      v19 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 112LL);
      if ( *((_DWORD *)v19 - 1) != 1856640366 )
        __break(0x8228u);
      if ( !v19(v18) )
      {
LABEL_41:
        v20 = 0;
        goto LABEL_42;
      }
    }
    v20 = -1;
LABEL_42:
    mutex_unlock(ipa3_ctx + 29472);
    return v20;
  }
  if ( (unsigned int)__ratelimit(&ipa3_add_flt_rule_usr_v2__rs, "ipa3_add_flt_rule_usr_v2") )
    printk(&unk_3FB3F2, "ipa3_add_flt_rule_usr_v2");
  v3 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d bad parm\n", "ipa3_add_flt_rule_usr_v2", 1421);
      v3 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v3 + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d bad parm\n", "ipa3_add_flt_rule_usr_v2", 1421);
  }
  return 4294967274LL;
}
