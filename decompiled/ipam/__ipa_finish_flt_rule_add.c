__int64 __fastcall _ipa_finish_flt_rule_add(__int64 a1, __int64 a2, _DWORD *a3)
{
  unsigned int v3; // w8
  __int64 v7; // x8
  int v8; // w0
  __int64 v9; // x8
  __int64 result; // x0
  __int64 v11; // x8
  __int64 v12; // x0
  __int64 v13; // x0
  __int64 v14; // x8

  v3 = *(_DWORD *)(a1 + 16);
  if ( v3 > 0x1FF )
    return 4294967274LL;
  *(_DWORD *)(a1 + 16) = v3 + 1;
  v7 = *(_QWORD *)(a2 + 400);
  if ( v7 )
    ++*(_DWORD *)(v7 + 80);
  v8 = ipa3_id_alloc(a2);
  if ( v8 < 0 )
  {
    if ( (unsigned int)__ratelimit(&_ipa_finish_flt_rule_add__rs, "__ipa_finish_flt_rule_add") )
      printk(&unk_3CC99F, "__ipa_finish_flt_rule_add");
    v11 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v12 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v12 )
      {
        ipc_log_string(v12, "ipa %s:%d failed to add to tree\n", "__ipa_finish_flt_rule_add", 1018);
        v11 = ipa3_ctx;
      }
      v13 = *(_QWORD *)(v11 + 34160);
      if ( v13 )
        ipc_log_string(v13, "ipa %s:%d failed to add to tree\n", "__ipa_finish_flt_rule_add", 1018);
    }
    v14 = *(_QWORD *)(a2 + 400);
    if ( v14 )
      --*(_DWORD *)(v14 + 80);
    --*(_DWORD *)(a1 + 16);
    return 0xFFFFFFFFLL;
  }
  else
  {
    *a3 = v8;
    v9 = ipa3_ctx;
    *(_DWORD *)(a2 + 412) = v8;
    if ( v9 )
    {
      result = *(_QWORD *)(v9 + 34160);
      if ( !result )
        return result;
      ipc_log_string(
        result,
        "ipa %s:%d add flt rule rule_cnt=%d\n",
        "__ipa_finish_flt_rule_add",
        1024,
        *(_DWORD *)(a1 + 16));
    }
    return 0;
  }
}
