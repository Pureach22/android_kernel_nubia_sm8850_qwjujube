__int64 __fastcall ipa3_send_opt_log_msg(char *s)
{
  __int64 v3; // x0
  size_t v4; // x21
  __int64 v5; // x19
  __int64 v6; // x0
  __int64 v7; // x8
  _QWORD *v8; // x9
  _QWORD *v9; // x20
  _QWORD *v10; // x8
  __int64 v11; // x10
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x0
  __int64 v16; // x0
  __int64 v17; // x8
  __int64 v18; // x0
  __int64 v19; // x0
  _QWORD *v20; // x0
  __int64 v21; // x2
  _QWORD *v22; // x1
  __int64 v23; // x8
  __int64 v24; // x0
  __int64 v25; // x0
  unsigned int v28; // w9
  unsigned int v35; // w10

  if ( (*(_BYTE *)(ipa3_opt_log_ctx + 272) & 2) == 0 )
    return 4294967290LL;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v3 )
      ipc_log_string(v3, "ipa %s:%d Processing wdi message data\n", "ipa3_send_opt_log_msg", 42);
  }
  if ( s )
  {
    v4 = strlen(s);
    v5 = _kmalloc_cache_noprof(of_property_read_variable_u32_array, 3520, 32);
    if ( v5 )
    {
      v6 = kmemdup_noprof(s, v4 + 1, 3264);
      if ( v6 )
      {
        v7 = ipa3_opt_log_ctx;
        *(_QWORD *)v5 = v6;
        *(_DWORD *)(v5 + 8) = v4;
        mutex_lock(v7 + 176);
        if ( *(int *)(ipa3_opt_log_ctx + 288) >= 128 )
        {
          v8 = *(_QWORD **)(ipa3_opt_log_ctx + 160);
          if ( v8 == (_QWORD *)(ipa3_opt_log_ctx + 160) )
          {
            v17 = ipa3_ctx;
            if ( ipa3_ctx )
            {
              v18 = *(_QWORD *)(ipa3_ctx + 34152);
              if ( v18 )
              {
                ipc_log_string(v18, "ipa %s:%d List Empty\n", "delete_first_node", 30);
                v17 = ipa3_ctx;
              }
              v19 = *(_QWORD *)(v17 + 34160);
              if ( v19 )
                ipc_log_string(v19, "ipa %s:%d List Empty\n", "delete_first_node", 30);
            }
          }
          else
          {
            v9 = v8 - 2;
            if ( v8 != &qword_10 )
            {
              v10 = (_QWORD *)v8[1];
              if ( (_QWORD *)*v10 == v8 && (v11 = *v8, *(_QWORD **)(*v8 + 8LL) == v8) )
              {
                *(_QWORD *)(v11 + 8) = v10;
                *v10 = v11;
              }
              else
              {
                _list_del_entry_valid_or_report(v8);
              }
              v12 = *(v8 - 2);
              *v8 = 0xDEAD000000000100LL;
              v8[1] = 0xDEAD000000000122LL;
              kfree(v12);
              kfree(v9);
              v13 = ipa3_opt_log_ctx;
              ++*(_DWORD *)(ipa3_opt_log_ctx + 284);
              if ( *(_DWORD *)(v13 + 288) )
              {
                _X8 = (unsigned int *)(v13 + 288);
                __asm { PRFM            #0x11, [X8] }
                do
                  v35 = __ldxr(_X8);
                while ( __stxr(v35 - 1, _X8) );
              }
            }
          }
        }
        v20 = (_QWORD *)(v5 + 16);
        v21 = ipa3_opt_log_ctx + 160;
        v22 = *(_QWORD **)(ipa3_opt_log_ctx + 168);
        if ( v5 + 16 == ipa3_opt_log_ctx + 160 || v22 == v20 || *v22 != v21 )
        {
          _list_add_valid_or_report(v20, v22);
        }
        else
        {
          *(_QWORD *)(ipa3_opt_log_ctx + 168) = v20;
          *(_QWORD *)(v5 + 16) = v21;
          *(_QWORD *)(v5 + 24) = v22;
          *v22 = v20;
        }
        _X8 = (unsigned int *)(ipa3_opt_log_ctx + 288);
        __asm { PRFM            #0x11, [X8] }
        do
          v28 = __ldxr(_X8);
        while ( __stxr(v28 + 1, _X8) );
        mutex_unlock(ipa3_opt_log_ctx + 176);
        _wake_up(ipa3_opt_log_ctx + 296, 3, 1, 0);
        ++*(_DWORD *)(ipa3_opt_log_ctx + 276);
        return 0;
      }
      else
      {
        kfree(v5);
        return 4294967284LL;
      }
    }
    else
    {
      v23 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v24 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v24 )
        {
          ipc_log_string(v24, "ipa %s:%d Memory allocation failed\n", "ipa3_send_opt_log_msg", 51);
          v23 = ipa3_ctx;
        }
        v25 = *(_QWORD *)(v23 + 34160);
        if ( v25 )
          ipc_log_string(v25, "ipa %s:%d Memory allocation failed\n", "ipa3_send_opt_log_msg", 51);
      }
      return 4294967284LL;
    }
  }
  else
  {
    v14 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v15 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v15 )
      {
        ipc_log_string(v15, "ipa %s:%d Input string is NULL\n", "ipa3_send_opt_log_msg", 44);
        v14 = ipa3_ctx;
      }
      v16 = *(_QWORD *)(v14 + 34160);
      if ( v16 )
        ipc_log_string(v16, "ipa %s:%d Input string is NULL\n", "ipa3_send_opt_log_msg", 44);
    }
    return 4294967274LL;
  }
}
