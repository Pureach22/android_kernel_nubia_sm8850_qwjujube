__int64 __fastcall ipa3_mdfy_flt_rule_v2(__int64 a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 v6; // x26
  unsigned __int64 v7; // x20
  int v8; // w8
  __int64 v9; // x9
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x0
  unsigned int (__fastcall *v14)(_QWORD); // x8
  unsigned int v15; // w19

  if ( !a1 || !*(_BYTE *)(a1 + 8) || *(_DWORD *)(a1 + 4) >= 2u )
  {
    if ( (unsigned int)__ratelimit(&ipa3_mdfy_flt_rule_v2__rs, "ipa3_mdfy_flt_rule_v2") )
      printk(&unk_3FB3F2, "ipa3_mdfy_flt_rule_v2");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d bad parm\n", "ipa3_mdfy_flt_rule_v2", 1813);
        v2 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v2 + 34160);
      if ( v4 )
        ipc_log_string(v4, "ipa %s:%d bad parm\n", "ipa3_mdfy_flt_rule_v2", 1813);
    }
    return 4294967274LL;
  }
  mutex_lock(ipa3_ctx + 29472);
  if ( *(_BYTE *)(a1 + 8) )
  {
    v6 = 0;
    v7 = 0;
    do
    {
      if ( *(_BYTE *)(ipa3_ctx + 32270) == 1 )
        *(_BYTE *)(*(_QWORD *)(a1 + 24) + v6 + 362) = 0;
      if ( !(unsigned int)_ipa_mdfy_flt_rule((_BYTE *)(*(_QWORD *)(a1 + 24) + v6), *(_DWORD *)(a1 + 4)) )
      {
        v8 = 0;
        goto LABEL_15;
      }
      if ( (unsigned int)__ratelimit(&ipa3_mdfy_flt_rule_v2__rs_69, "ipa3_mdfy_flt_rule_v2") )
      {
        printk(&unk_3C6DEA, "ipa3_mdfy_flt_rule_v2");
        v10 = ipa3_ctx;
        if ( ipa3_ctx )
        {
LABEL_21:
          v11 = *(_QWORD *)(v10 + 34152);
          if ( v11 )
          {
            ipc_log_string(v11, "ipa %s:%d failed to mdfy flt rule %i\n", "ipa3_mdfy_flt_rule_v2", 1825, v7);
            v10 = ipa3_ctx;
          }
          v12 = *(_QWORD *)(v10 + 34160);
          if ( v12 )
            ipc_log_string(v12, "ipa %s:%d failed to mdfy flt rule %i\n", "ipa3_mdfy_flt_rule_v2", 1825, v7);
        }
      }
      else
      {
        v10 = ipa3_ctx;
        if ( ipa3_ctx )
          goto LABEL_21;
      }
      v8 = -1;
LABEL_15:
      ++v7;
      v9 = *(_QWORD *)(a1 + 24) + v6;
      v6 += 376;
      *(_DWORD *)(v9 + 4) = v8;
    }
    while ( v7 < *(unsigned __int8 *)(a1 + 8) );
  }
  if ( !*(_BYTE *)a1 )
    goto LABEL_33;
  v13 = *(unsigned int *)(a1 + 4);
  v14 = *(unsigned int (__fastcall **)(_QWORD))(*(_QWORD *)(ipa3_ctx + 34176) + 112LL);
  if ( *((_DWORD *)v14 - 1) != 1856640366 )
    __break(0x8228u);
  if ( v14(v13) )
    v15 = -1;
  else
LABEL_33:
    v15 = 0;
  mutex_unlock(ipa3_ctx + 29472);
  return v15;
}
