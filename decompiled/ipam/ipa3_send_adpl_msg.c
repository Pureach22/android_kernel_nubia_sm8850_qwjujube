__int64 __fastcall ipa3_send_adpl_msg(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x19
  _QWORD *v4; // x21
  void *v5; // x0
  size_t v6; // x2
  void *v7; // x21
  __int64 v8; // x0
  _QWORD *v9; // x9
  _QWORD *v10; // x20
  _QWORD *v11; // x8
  __int64 v12; // x10
  __int64 v13; // x0
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x2
  __int64 *v20; // x1
  __int64 v21; // x8
  __int64 v22; // x0
  __int64 v23; // x0
  unsigned int v27; // w9
  unsigned int v34; // w10

  if ( ipa3_ctx )
  {
    v2 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v2 )
      ipc_log_string(v2, "ipa %s:%d Processing DPL data\n", "ipa3_send_adpl_msg", 232);
  }
  v3 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 32);
  if ( !v3 )
  {
    v21 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v22 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v22 )
      {
        ipc_log_string(v22, "ipa %s:%d Memory allocation failed\n", "ipa3_send_adpl_msg", 235);
        v21 = ipa3_ctx;
      }
      v23 = *(_QWORD *)(v21 + 34160);
      if ( v23 )
        ipc_log_string(v23, "ipa %s:%d Memory allocation failed\n", "ipa3_send_adpl_msg", 235);
    }
    return 4294967284LL;
  }
  v4 = (_QWORD *)*(unsigned int *)(a1 + 112);
  v5 = (void *)kmemdup_noprof(*(_QWORD *)(a1 + 224), v4, 3264);
  if ( !v5 )
  {
    kfree(v3);
    return 4294967284LL;
  }
  v6 = *(unsigned int *)(a1 + 112);
  if ( (unsigned __int64)v4 < v6 )
  {
    v18 = _fortify_panic(17, v4, v6);
  }
  else
  {
    v7 = v5;
    memcpy(v5, *(const void **)(a1 + 224), v6);
    *(_QWORD *)v3 = v7;
    v4 = &unk_200000;
    v8 = ipa3_odl_ctx + 336;
    *(_DWORD *)(v3 + 8) = *(_DWORD *)(a1 + 112);
    mutex_lock(v8);
    if ( *(int *)(ipa3_odl_ctx + 712) >= 1024 )
    {
      v9 = *(_QWORD **)(ipa3_odl_ctx + 320);
      if ( v9 == (_QWORD *)(ipa3_odl_ctx + 320) )
      {
        v15 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v16 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v16 )
          {
            ipc_log_string(v16, "ipa %s:%d List Empty\n", "delete_first_node", 222);
            v15 = ipa3_ctx;
          }
          v17 = *(_QWORD *)(v15 + 34160);
          if ( v17 )
            ipc_log_string(v17, "ipa %s:%d List Empty\n", "delete_first_node", 222);
        }
      }
      else
      {
        v10 = v9 - 2;
        if ( v9 != &qword_10 )
        {
          v11 = (_QWORD *)v9[1];
          if ( (_QWORD *)*v11 == v9 && (v12 = *v9, *(_QWORD **)(*v9 + 8LL) == v9) )
          {
            *(_QWORD *)(v12 + 8) = v11;
            *v11 = v12;
          }
          else
          {
            _list_del_entry_valid_or_report(v9);
          }
          v13 = *(v9 - 2);
          *v9 = 0xDEAD000000000100LL;
          v9[1] = 0xDEAD000000000122LL;
          kfree(v13);
          kfree(v10);
          v14 = ipa3_odl_ctx;
          ++*(_DWORD *)(ipa3_odl_ctx + 708);
          if ( *(_DWORD *)(v14 + 712) )
          {
            _X8 = (unsigned int *)(v14 + 712);
            __asm { PRFM            #0x11, [X8] }
            do
              v34 = __ldxr(_X8);
            while ( __stxr(v34 - 1, _X8) );
          }
        }
      }
    }
    v18 = v3 + 16;
    v19 = ipa3_odl_ctx + 320;
    v20 = *(__int64 **)(ipa3_odl_ctx + 328);
    if ( v3 + 16 != ipa3_odl_ctx + 320 && v20 != (__int64 *)v18 && *v20 == v19 )
    {
      *(_QWORD *)(ipa3_odl_ctx + 328) = v18;
      *(_QWORD *)(v3 + 16) = v19;
      *(_QWORD *)(v3 + 24) = v20;
      *v20 = v18;
      goto LABEL_24;
    }
  }
  _list_add_valid_or_report(v18, v20);
LABEL_24:
  _X8 = (unsigned int *)(v4[213] + 712LL);
  __asm { PRFM            #0x11, [X8] }
  do
    v27 = __ldxr(_X8);
  while ( __stxr(v27 + 1, _X8) );
  mutex_unlock(v4[213] + 336LL);
  _wake_up(v4[213] + 720LL, 3, 1, 0);
  ++*(_DWORD *)(v4[213] + 700LL);
  return 0;
}
