__int64 __fastcall ipc_log_context_create(int a1, const char *a2, int a3)
{
  const char *v6; // x19
  __int64 v7; // x19
  _QWORD *v8; // x23
  __int64 v9; // x25
  int v10; // w28
  __int64 v11; // x25
  __int64 v12; // x0
  _QWORD *v13; // x8
  _QWORD *v14; // x1
  __int64 v15; // x26
  int v16; // w20
  _QWORD *v17; // x9
  _QWORD *v18; // x8
  __int64 v19; // x10
  size_t v20; // x0
  unsigned __int64 v21; // x2
  __int64 v22; // x8
  __int64 v23; // x9
  _UNKNOWN **v24; // x0
  void *v25; // x2
  _QWORD *v26; // x1
  unsigned __int64 StatusReg; // x23
  __int64 v29; // x24

  raw_read_lock_irq(&context_list_lock_lha1);
  v6 = (const char *)&ipc_log_context_list;
  do
  {
    v6 = *(const char **)v6;
    if ( v6 == (const char *)&ipc_log_context_list )
    {
      raw_read_unlock_irq(&context_list_lock_lha1);
      goto LABEL_7;
    }
  }
  while ( strcmp(v6 - 32, a2) );
  v7 = (__int64)(v6 - 56);
  raw_read_unlock_irq(&context_list_lock_lha1);
  if ( v7 )
    return v7;
LABEL_7:
  v7 = _kmalloc_cache_noprof(strnlen, 3520, 1256);
  if ( !v7 )
    return v7;
  while ( 1 )
  {
    *(_DWORD *)(v7 + 168) = 0;
    _init_swait_queue_head(v7 + 176, "&x->wait", &init_completion___key);
    *(_DWORD *)(v7 + 160) = 0;
    v8 = (_QWORD *)(v7 + 72);
    *(_QWORD *)(v7 + 72) = v7 + 72;
    *(_QWORD *)(v7 + 80) = v7 + 72;
    *(_QWORD *)(v7 + 144) = v7 + 144;
    *(_QWORD *)(v7 + 152) = v7 + 144;
    v9 = raw_spin_lock_irqsave(v7 + 160);
    if ( (a3 & 0x10000) != 0 )
      register_minidump(v7, 1256, "ipc_ctxt", (unsigned int)minidump_buf_cnt);
    raw_spin_unlock_irqrestore(v7 + 160, v9);
    if ( a1 >= 1 )
      break;
    v11 = 0;
LABEL_30:
    *(_QWORD *)(v7 + 16) = v7;
    *(_DWORD *)(v7 + 8) = 3;
    v20 = strnlen(a2, 0x20u);
    if ( v20 == -1 )
    {
      _fortify_panic(2, -1, 0);
    }
    else
    {
      if ( v20 == 32 )
        v21 = 32;
      else
        v21 = v20 + 1;
      if ( v21 < 0x21 )
      {
        sized_strscpy(v7 + 24, a2);
        v22 = *(_QWORD *)(v7 + 72);
        *(_WORD *)(v7 + 12) = a3;
        v22 -= 48;
        *(_QWORD *)(v7 + 88) = v22;
        *(_QWORD *)(v7 + 96) = v11;
        *(_QWORD *)(v7 + 104) = v22;
        *(_QWORD *)(v7 + 112) = v22;
        *(_QWORD *)(v7 + 120) = v22;
        *(_WORD *)(v7 + 14) = 72;
        *(_DWORD *)(v7 + 128) = 4024 * a1;
        *(_DWORD *)(v7 + 200) = 1;
        *(_BYTE *)(v7 + 204) = 0;
        create_ctx_debugfs(v7, a2);
        *(_QWORD *)v7 = 0xDA78BBAD25874452LL;
        v23 = raw_write_lock_irqsave(&context_list_lock_lha1);
        v24 = (_UNKNOWN **)(v7 + 56);
        if ( (a3 & 0x10000) != 0 && minidump_buf_cnt <= 15 )
        {
          v25 = ipc_log_context_list;
          if ( *(_UNKNOWN ***)((char *)&unk_8 + (_QWORD)ipc_log_context_list) != &ipc_log_context_list
            || ipc_log_context_list == (_UNKNOWN *)v24 )
          {
            _list_add_valid_or_report(v24, &ipc_log_context_list);
          }
          else
          {
            *(_QWORD *)((char *)&unk_8 + (_QWORD)ipc_log_context_list) = v24;
            *(_QWORD *)(v7 + 56) = v25;
            *(_QWORD *)(v7 + 64) = &ipc_log_context_list;
            ipc_log_context_list = (_UNKNOWN *)(v7 + 56);
          }
        }
        else
        {
          v26 = off_278;
          if ( off_278 == v24 || *off_278 != (_UNKNOWN *)&ipc_log_context_list )
          {
            _list_add_valid_or_report(v24, off_278);
          }
          else
          {
            off_278 = (_UNKNOWN **)(v7 + 56);
            *(_QWORD *)(v7 + 56) = &ipc_log_context_list;
            *(_QWORD *)(v7 + 64) = v26;
            *v26 = v24;
          }
        }
        raw_write_unlock_irqrestore(&context_list_lock_lha1, v23);
        return v7;
      }
    }
    _fortify_panic(7, 32, v21);
    StatusReg = _ReadStatusReg(SP_EL0);
    v29 = *(_QWORD *)(StatusReg + 80);
    *(_QWORD *)(StatusReg + 80) = &ipc_log_context_create__alloc_tag;
    v7 = _kmalloc_cache_noprof(strnlen, 3520, 1256);
    *(_QWORD *)(StatusReg + 80) = v29;
    if ( !v7 )
      return v7;
  }
  v10 = 0;
  _ReadStatusReg(SP_EL0);
  while ( 1 )
  {
    v11 = _kmalloc_cache_noprof(sized_strscpy, 3520, 4096);
    if ( !v11 )
      break;
    *(_QWORD *)(v11 + 16) = v7;
    *(_DWORD *)(v11 + 8) = v10 + 0x80000000;
    *(_QWORD *)(v11 + 40) = v7 - v11;
    *(_QWORD *)v11 = 0xAD87BBDA52784425LL;
    v12 = raw_spin_lock_irqsave(v7 + 160);
    v13 = (_QWORD *)(v11 + 48);
    v14 = *(_QWORD **)(v7 + 80);
    v15 = v12;
    if ( (_QWORD *)(v11 + 48) == v8 || v14 == v13 || (_QWORD *)*v14 != v8 )
    {
      _list_add_valid_or_report(v11 + 48, v14);
      if ( (a3 & 0x10000) == 0 )
        goto LABEL_12;
LABEL_18:
      register_minidump(v11, 4096, a2, (unsigned int)minidump_buf_cnt);
      goto LABEL_12;
    }
    *(_QWORD *)(v7 + 80) = v13;
    *(_QWORD *)(v11 + 48) = v8;
    *(_QWORD *)(v11 + 56) = v14;
    *v14 = v13;
    if ( (a3 & 0x10000) != 0 )
      goto LABEL_18;
LABEL_12:
    raw_spin_unlock_irqrestore(v7 + 160, v15);
    if ( a1 == ++v10 )
      goto LABEL_30;
  }
  if ( v10 )
  {
    v16 = v10 + 1;
    do
    {
      v17 = (_QWORD *)*v8;
      v18 = *(_QWORD **)(*v8 + 8LL);
      if ( *v18 == *v8 && (v19 = *v17, *(_QWORD **)(*v17 + 8LL) == v17) )
      {
        *(_QWORD *)(v19 + 8) = v18;
        *v18 = v19;
      }
      else
      {
        _list_del_entry_valid_or_report(*v8);
      }
      *v17 = 0xDEAD000000000100LL;
      v17[1] = 0xDEAD000000000122LL;
      kfree(v17 - 6);
      --v16;
    }
    while ( v16 > 1 );
  }
  kfree(v7);
  return 0;
}
