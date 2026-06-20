__int64 __fastcall _ipa_finish_rt_rule_add(__int64 *a1, _DWORD *a2, __int64 a3)
{
  unsigned int v3; // w8
  __int64 v7; // x8
  _DWORD *v8; // x8
  unsigned int v9; // w22
  __int64 v10; // x8
  int v11; // w0
  int v12; // w23
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  _DWORD *v20; // x8
  __int64 v21; // x8
  __int64 **v22; // x8
  __int64 *v23; // x9

  v3 = *(_DWORD *)(a3 + 76);
  if ( v3 > 0x1FF )
  {
    v9 = -22;
    goto LABEL_28;
  }
  *(_DWORD *)(a3 + 76) = v3 + 1;
  v7 = a1[26];
  if ( v7 )
  {
    v8 = (_DWORD *)(v7 + 336);
  }
  else
  {
    v10 = a1[27];
    if ( !v10 )
      goto LABEL_8;
    v8 = (_DWORD *)(v10 + 72);
  }
  ++*v8;
LABEL_8:
  v11 = ipa3_id_alloc(a1);
  if ( v11 < 0 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_finish_rt_rule_add__rs, "__ipa_finish_rt_rule_add") )
      printk(&unk_3CC99F, "__ipa_finish_rt_rule_add");
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d failed to add to tree\n", "__ipa_finish_rt_rule_add", 1122);
        v16 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v16 + 34160);
      if ( v18 )
        ipc_log_string(v18, "ipa %s:%d failed to add to tree\n", "__ipa_finish_rt_rule_add", 1122);
    }
    v19 = a1[26];
    if ( v19 )
    {
      v20 = (_DWORD *)(v19 + 336);
    }
    else
    {
      v21 = a1[27];
      if ( !v21 )
      {
LABEL_27:
        v9 = -1;
LABEL_28:
        idr_remove(*(_QWORD *)(a3 + 216), *((unsigned __int16 *)a1 + 117));
        v22 = (__int64 **)a1[1];
        if ( *v22 == a1 && (v23 = (__int64 *)*a1, *(__int64 **)(*a1 + 8) == a1) )
        {
          v23[1] = (__int64)v22;
          *v22 = v23;
        }
        else
        {
          _list_del_entry_valid_or_report(a1);
        }
        *a1 = 0xDEAD000000000100LL;
        a1[1] = 0xDEAD000000000122LL;
        kmem_cache_free(*(_QWORD *)(ipa3_ctx + 29384), a1);
        return v9;
      }
      v20 = (_DWORD *)(v21 + 72);
    }
    --*v20;
    goto LABEL_27;
  }
  v12 = v11;
  v13 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v14 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v14 )
    {
      ipc_log_string(
        v14,
        "ipa %s:%d add rt rule tbl_idx=%d rule_cnt=%d rule_id=%d\n",
        "__ipa_finish_rt_rule_add",
        1128,
        *(_DWORD *)(a3 + 72),
        *(_DWORD *)(a3 + 76),
        *((unsigned __int16 *)a1 + 117));
      v13 = ipa3_ctx;
    }
    v15 = *(_QWORD *)(v13 + 34160);
    if ( v15 )
      ipc_log_string(
        v15,
        "ipa %s:%d add rt rule tbl_idx=%d rule_cnt=%d rule_id=%d\n",
        "__ipa_finish_rt_rule_add",
        1128,
        *(_DWORD *)(a3 + 72),
        *(_DWORD *)(a3 + 76),
        *((unsigned __int16 *)a1 + 117));
  }
  v9 = 0;
  *a2 = v12;
  *((_DWORD *)a1 + 57) = v12;
  return v9;
}
