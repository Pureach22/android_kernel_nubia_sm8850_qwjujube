void _ipa3_dec_client_disable_clks()
{
  unsigned int v1; // w9
  unsigned int v7; // w11
  __int64 v8; // x1
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x1
  __int64 v14; // x0
  unsigned int v17; // w8
  signed int v18; // w8
  unsigned int v21; // w9

  _X8 = (unsigned int *)(ipa3_ctx + 30552);
  if ( *(_DWORD *)(ipa3_ctx + 30552) )
  {
    v1 = *_X8;
    while ( v1 != 1 )
    {
      __asm { PRFM            #0x11, [X8] }
      while ( 1 )
      {
        v7 = __ldxr(_X8);
        if ( v7 != v1 )
          break;
        if ( !__stlxr(v1 - 1, _X8) )
        {
          __dmb(0xBu);
          break;
        }
      }
      _ZF = v7 == v1;
      v1 = v7;
      if ( _ZF )
        goto LABEL_28;
    }
  }
  else
  {
    printk(&unk_3B4637, "__ipa3_dec_client_disable_clks");
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(
          v10,
          "ipa %s:%d trying to disable clocks with refcnt is 0\n",
          "__ipa3_dec_client_disable_clks",
          7058);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(
          v11,
          "ipa %s:%d trying to disable clocks with refcnt is 0\n",
          "__ipa3_dec_client_disable_clks",
          7058);
    }
    printk(&unk_3AED39, v8);
    __break(0x800u);
  }
  v12 = ipa3_ctx;
  if ( *(_DWORD *)(ipa3_ctx + 30552) == 1 && (*(_BYTE *)(ipa3_ctx + 31960) & 1) == 0 )
  {
    ipa3_force_close_coal(1, 1);
    v12 = ipa3_ctx;
    *(_BYTE *)(ipa3_ctx + 31960) = 0;
  }
  mutex_lock(v12 + 30504);
  if ( *(_DWORD *)(ipa3_ctx + 30552) == 1 && *(_BYTE *)(ipa3_ctx + 31960) == 1 )
  {
    v13 = *(_QWORD *)(ipa3_ctx + 31944);
    *(_BYTE *)(ipa3_ctx + 31960) = 0;
    queue_work_on(32, v13, &ipa3_tag_work);
  }
  else
  {
    _X9 = (unsigned int *)(ipa3_ctx + 30552);
    __asm { PRFM            #0x11, [X9] }
    do
    {
      v17 = __ldxr(_X9);
      v18 = v17 - 1;
    }
    while ( __stlxr(v18, _X9) );
    __dmb(0xBu);
    if ( v18 <= 0 )
    {
      if ( (unsigned int)ipa3_suspend_apps_pipes(1) )
      {
        _X8 = (unsigned int *)(ipa3_ctx + 30552);
        __asm { PRFM            #0x11, [X8] }
        do
          v21 = __ldxr(_X8);
        while ( __stxr(v21 + 1, _X8) );
        queue_delayed_work_on(32, *(_QWORD *)(ipa3_ctx + 31944), &ipa_dec_clients_disable_clks_on_wq_work, 3);
      }
      else
      {
        ipa3_disable_clks();
      }
    }
  }
  mutex_unlock(ipa3_ctx + 30504);
LABEL_28:
  if ( ipa3_ctx )
  {
    v14 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v14 )
      ipc_log_string(
        v14,
        "ipa %s:%d active clients = %d\n",
        "__ipa3_dec_client_disable_clks",
        7111,
        *(_DWORD *)(ipa3_ctx + 30552));
  }
}
