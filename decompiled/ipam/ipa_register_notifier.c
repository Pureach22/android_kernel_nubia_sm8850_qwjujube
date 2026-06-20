__int64 __fastcall ipa_register_notifier(__int64 a1)
{
  _QWORD *v3; // x0
  __int64 v4; // x0
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  unsigned int v10; // w20
  _QWORD *v11; // x1
  __int64 v12; // x9
  _QWORD *v13; // x8
  _QWORD *v14; // x2
  __int64 v15; // x0
  __int64 ipc_logbuf; // x0
  __int64 v17; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v19; // x0
  _QWORD *v20; // x9

  if ( !a1 )
    return 4294967282LL;
  raw_spin_lock(ipa3_ctx + 51256);
  v3 = (_QWORD *)_kmalloc_cache_noprof(ipc_log_string, 2336, 40);
  if ( v3 )
  {
    v3[2] = a1;
    v11 = v3 + 2;
    *v3 = v3;
    v3[1] = v3;
    v12 = ipa3_ctx;
    v13 = (_QWORD *)(ipa3_ctx + 51272);
    v14 = *(_QWORD **)(ipa3_ctx + 51272);
    if ( v14[1] != ipa3_ctx + 51272 || v3 == v14 || v3 == v13 )
    {
      _list_add_valid_or_report(v3, v13);
      v11 = v20;
      v12 = ipa3_ctx;
    }
    else
    {
      v14[1] = v3;
      *v3 = v14;
      v3[1] = v13;
      *v13 = v3;
    }
    raw_notifier_chain_register(*(_QWORD *)(v12 + 51264), v11);
    v15 = printk(&unk_3DE258, "ipa_register_notifier");
    ipc_logbuf = ipa3_get_ipc_logbuf(v15);
    if ( ipc_logbuf )
    {
      v17 = ipa3_get_ipc_logbuf(ipc_logbuf);
      ipc_logbuf = ipc_log_string(
                     v17,
                     "ipa-wan %s:%d Registered noifier for buffer threshold\n",
                     "ipa_register_notifier",
                     3012);
    }
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
    if ( ipc_logbuf_low )
    {
      v19 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
      ipc_log_string(v19, "ipa-wan %s:%d Registered noifier for buffer threshold\n", "ipa_register_notifier", 3012);
    }
    v9 = ipa3_ctx;
    v10 = 0;
    *(_BYTE *)(ipa3_ctx + 51288) = 1;
  }
  else
  {
    v4 = printk(&unk_3F503E, "ipa_register_notifier");
    v5 = ipa3_get_ipc_logbuf(v4);
    if ( v5 )
    {
      v6 = ipa3_get_ipc_logbuf(v5);
      v5 = ipc_log_string(v6, "ipa-wan %s:%d Buffer threshold notifier failure\n", "ipa_register_notifier", 3003);
    }
    v7 = ipa3_get_ipc_logbuf_low(v5);
    if ( v7 )
    {
      v8 = ipa3_get_ipc_logbuf_low(v7);
      ipc_log_string(v8, "ipa-wan %s:%d Buffer threshold notifier failure\n", "ipa_register_notifier", 3003);
    }
    v9 = ipa3_ctx;
    v10 = -14;
  }
  raw_spin_unlock(v9 + 51256);
  return v10;
}
