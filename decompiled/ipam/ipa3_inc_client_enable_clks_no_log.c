void ipa3_inc_client_enable_clks_no_log()
{
  unsigned int v1; // w9
  unsigned int v7; // w11
  __int64 v8; // x0
  __int64 v9; // x0
  unsigned int v11; // w9
  unsigned int v13; // w11
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x8
  unsigned int v19; // w9

  _X8 = (unsigned int *)(ipa3_ctx + 30552);
  v1 = *(_DWORD *)(ipa3_ctx + 30552);
  while ( v1 )
  {
    __asm { PRFM            #0x11, [X8] }
    while ( 1 )
    {
      v7 = __ldxr(_X8);
      if ( v7 != v1 )
        break;
      if ( !__stlxr(v1 + 1, _X8) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v7 == v1;
    v1 = v7;
    if ( _ZF )
    {
      if ( ipa3_ctx )
      {
        v8 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v8 )
          ipc_log_string(
            v8,
            "ipa %s:%d active clients = %d\n",
            "ipa3_inc_client_enable_clks_no_log",
            6976,
            *(unsigned int *)(ipa3_ctx + 30552));
      }
      return;
    }
  }
  v9 = mutex_lock(ipa3_ctx + 30504);
  _X8 = (unsigned int *)(ipa3_ctx + 30552);
  v11 = *(_DWORD *)(ipa3_ctx + 30552);
  while ( v11 )
  {
    __asm { PRFM            #0x11, [X8] }
    while ( 1 )
    {
      v13 = __ldxr(_X8);
      if ( v13 != v11 )
        break;
      if ( !__stlxr(v11 + 1, _X8) )
      {
        __dmb(0xBu);
        break;
      }
    }
    _ZF = v13 == v11;
    v11 = v13;
    if ( _ZF )
    {
      mutex_unlock(ipa3_ctx + 30504);
      if ( ipa3_ctx )
      {
        v14 = *(_QWORD *)(ipa3_ctx + 34160);
        if ( v14 )
          ipc_log_string(
            v14,
            "ipa %s:%d active clients = %d\n",
            "ipa3_inc_client_enable_clks_no_log",
            6987,
            *(unsigned int *)(ipa3_ctx + 30552));
      }
      return;
    }
  }
  ((void (__fastcall *)(__int64))ipa3_enable_clks)(v9);
  ipa3_suspend_apps_pipes(0);
  _X8 = (unsigned int *)(ipa3_ctx + 30552);
  __asm { PRFM            #0x11, [X8] }
  do
    v19 = __ldxr(_X8);
  while ( __stxr(v19 + 1, _X8) );
  v16 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v15 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v15 )
    {
      ipc_log_string(
        v15,
        "ipa %s:%d active clients = %d\n",
        "ipa3_inc_client_enable_clks_no_log",
        6995,
        *(_DWORD *)(ipa3_ctx + 30552));
      v16 = ipa3_ctx;
    }
  }
  mutex_unlock(v16 + 30504);
}
