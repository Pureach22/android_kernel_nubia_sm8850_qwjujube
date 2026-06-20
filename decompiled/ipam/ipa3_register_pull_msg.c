__int64 __fastcall ipa3_register_pull_msg(int *a1, const void *a2)
{
  __int64 v4; // x0
  __int64 v5; // x21
  int v6; // w8
  __int64 v7; // x9
  _QWORD *v8; // x0
  __int64 v9; // x2
  _QWORD *v10; // x1
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0

  if ( a1 && a2 )
  {
    v4 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 32);
    v5 = v4;
    if ( v4 )
    {
      v6 = *a1;
      *(_QWORD *)(v4 + 8) = a2;
      v7 = ipa3_ctx;
      *(_DWORD *)v4 = v6;
      mutex_lock(v7 + 32104);
      v8 = (_QWORD *)(v5 + 16);
      v9 = ipa3_ctx + 32088;
      v10 = *(_QWORD **)(ipa3_ctx + 32096);
      if ( v5 + 16 == ipa3_ctx + 32088 || v10 == v8 || *v10 != v9 )
      {
        _list_add_valid_or_report(v8, v10);
      }
      else
      {
        *(_QWORD *)(ipa3_ctx + 32096) = v8;
        *(_QWORD *)(v5 + 16) = v9;
        *(_QWORD *)(v5 + 24) = v10;
        *v10 = v8;
      }
      mutex_unlock(ipa3_ctx + 32104);
      return 0;
    }
    else
    {
      return 4294967284LL;
    }
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa3_register_pull_msg__rs, "ipa3_register_pull_msg") )
      printk(&unk_3F54DB, "ipa3_register_pull_msg");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d invalid param meta=%pK callback=%pK\n", "ipa3_register_pull_msg", 637, a1, a2);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d invalid param meta=%pK callback=%pK\n", "ipa3_register_pull_msg", 637, a1, a2);
    }
    return 4294967274LL;
  }
}
