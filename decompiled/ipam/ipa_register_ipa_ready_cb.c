__int64 __fastcall ipa_register_ipa_ready_cb(__int64 a1, __int64 a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 *v8; // x0
  __int64 v9; // x9
  __int64 v10; // x2
  __int64 *v11; // x1
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0

  if ( ipa3_ctx )
  {
    mutex_lock(ipa3_ctx + 29472);
    v4 = ipa3_ctx;
    if ( *(_BYTE *)(ipa3_ctx + 43637) == 1 )
    {
      if ( ipa3_ctx )
      {
        v5 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v5 )
        {
          ipc_log_string(
            v5,
            "ipa %s:%d IPA driver finished initialization already\n",
            "ipa_register_ipa_ready_cb",
            7837);
          v4 = ipa3_ctx;
        }
        v6 = *(_QWORD *)(v4 + 34160);
        if ( v6 )
        {
          ipc_log_string(
            v6,
            "ipa %s:%d IPA driver finished initialization already\n",
            "ipa_register_ipa_ready_cb",
            7837);
          v4 = ipa3_ctx;
        }
      }
      mutex_unlock(v4 + 29472);
      return 4294967279LL;
    }
    else
    {
      v8 = (__int64 *)_kmalloc_cache_noprof(of_property_read_variable_u32_array, 3264, 32);
      if ( v8 )
      {
        v9 = ipa3_ctx;
        v8[2] = a1;
        v8[3] = a2;
        v10 = v9 + 43640;
        v11 = *(__int64 **)(v9 + 43648);
        if ( v8 == (__int64 *)(v9 + 43640) || v11 == v8 || *v11 != v10 )
        {
          _list_add_valid_or_report();
        }
        else
        {
          *(_QWORD *)(v9 + 43648) = v8;
          *v8 = v10;
          v8[1] = (__int64)v11;
          *v11 = (__int64)v8;
        }
        mutex_unlock(ipa3_ctx + 29472);
        return 0;
      }
      else
      {
        mutex_unlock(ipa3_ctx + 29472);
        return 4294967284LL;
      }
    }
  }
  else
  {
    printk(&unk_3E2E08, "ipa_register_ipa_ready_cb");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d ipa framework hasn't been initialized yet\n", "ipa_register_ipa_ready_cb", 7831);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d ipa framework hasn't been initialized yet\n", "ipa_register_ipa_ready_cb", 7831);
    }
    return 0xFFFFFFFFLL;
  }
}
