__int64 __fastcall ipa_eth_unregister_ready_cb(__int64 a1)
{
  __int64 v2; // x0
  __int64 v3; // x0
  _QWORD *v4; // x9
  _QWORD *v5; // x8
  _QWORD *v6; // x10
  _QWORD *v7; // x8
  __int64 v9; // x8
  _QWORD *v10; // x0
  _QWORD *v11; // x8
  _QWORD *v12; // x19
  _QWORD *v13; // x9
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v16; // x0
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x0

  if ( !a1 )
  {
    printk(&unk_3CE0D5, "ipa_eth_unregister_ready_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      ipc_logbuf = ipa3_get_ipc_logbuf();
      ipc_log_string(ipc_logbuf, "ipa_eth %s:%d null ready_info", "ipa_eth_unregister_ready_cb", 292);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
      ipc_log_string(ipc_logbuf_low, "ipa_eth %s:%d null ready_info", "ipa_eth_unregister_ready_cb", 292);
    }
    return 4294967282LL;
  }
  if ( !ipa_eth_ctx )
  {
    printk(&unk_3CE0F5, "ipa_eth_unregister_ready_cb");
    if ( ipa3_get_ipc_logbuf() )
    {
      v16 = ipa3_get_ipc_logbuf();
      ipc_log_string(v16, "ipa_eth %s:%d unregister called before register\n", "ipa_eth_unregister_ready_cb", 297);
    }
    if ( ipa3_get_ipc_logbuf_low() )
    {
      v17 = ipa3_get_ipc_logbuf_low();
      ipc_log_string(v17, "ipa_eth %s:%d unregister called before register\n", "ipa_eth_unregister_ready_cb", 297);
    }
    return 4294967282LL;
  }
  if ( ipa3_get_ipc_logbuf() )
  {
    v2 = ipa3_get_ipc_logbuf();
    ipc_log_string(v2, "ipa_eth %s:%d ipa_eth unregister ready cb\n", "ipa_eth_unregister_ready_cb", 301);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    v3 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v3, "ipa_eth %s:%d ipa_eth unregister ready cb\n", "ipa_eth_unregister_ready_cb", 301);
  }
  mutex_lock(ipa_eth_ctx + 192);
  v4 = (_QWORD *)ipa_eth_ctx;
  do
  {
    v4 = (_QWORD *)*v4;
    if ( v4 == (_QWORD *)ipa_eth_ctx || !v4 )
    {
      printk(&unk_3CE128, "ipa_eth_unregister_ready_cb");
      if ( ipa3_get_ipc_logbuf() )
      {
        v18 = ipa3_get_ipc_logbuf();
        ipc_log_string(v18, "ipa_eth %s:%d unable to unregsiter, no ready_info\n", "ipa_eth_unregister_ready_cb", 314);
      }
      if ( ipa3_get_ipc_logbuf_low() )
      {
        v19 = ipa3_get_ipc_logbuf_low();
        ipc_log_string(v19, "ipa_eth %s:%d unable to unregsiter, no ready_info\n", "ipa_eth_unregister_ready_cb", 314);
      }
      mutex_unlock(ipa_eth_ctx + 192);
      return 4294967282LL;
    }
  }
  while ( v4[2] != a1 );
  v5 = (_QWORD *)v4[1];
  if ( (_QWORD *)*v5 == v4 && (v6 = (_QWORD *)*v4, *(_QWORD **)(*v4 + 8LL) == v4) )
  {
    v6[1] = v5;
    *v5 = v6;
  }
  else
  {
    _list_del_entry_valid_or_report(v4);
  }
  *v4 = 0xDEAD000000000100LL;
  v4[1] = 0xDEAD000000000122LL;
  v7 = (_QWORD *)ipa_eth_ctx;
  if ( (_QWORD *)*v7 != v7 )
  {
    *(_BYTE *)(a1 + 16) = 0;
    mutex_unlock(v7 + 24);
    return 0;
  }
  mutex_unlock(ipa_eth_ctx + 192);
  v9 = ipa_eth_ctx;
  if ( !ipa_eth_ctx )
    return 0;
  v10 = *(_QWORD **)(ipa_eth_ctx + 288);
  if ( v10 != (_QWORD *)(ipa_eth_ctx + 288) )
  {
    do
    {
      v12 = (_QWORD *)*v10;
      v11 = (_QWORD *)v10[1];
      if ( (_QWORD *)*v11 == v10 && (_QWORD *)v12[1] == v10 )
      {
        v12[1] = v11;
        *v11 = v12;
      }
      else
      {
        _list_del_entry_valid_or_report(v10);
        v10 = v13;
      }
      *v10 = 0xDEAD000000000100LL;
      v10[1] = 0xDEAD000000000122LL;
      kfree(v10);
      v9 = ipa_eth_ctx;
      v10 = v12;
    }
    while ( v12 != (_QWORD *)(ipa_eth_ctx + 288) );
  }
  destroy_workqueue(*(_QWORD *)(v9 + 240));
  kfree(ipa_eth_ctx);
  ipa_eth_ctx = 0;
  return 0;
}
