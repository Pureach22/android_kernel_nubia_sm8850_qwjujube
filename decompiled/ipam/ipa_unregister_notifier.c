__int64 __fastcall ipa_unregister_notifier(__int64 a1)
{
  __int64 result; // x0
  __int64 v3; // x9
  _QWORD *v4; // x19
  _QWORD *v5; // x8
  _QWORD *v6; // x9
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 ipc_logbuf; // x0
  __int64 v13; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v15; // x0

  if ( !a1 )
    return 4294967282LL;
  raw_spin_lock(ipa3_ctx + 51256);
  v3 = a1;
  v4 = (_QWORD *)(ipa3_ctx + 51272);
  while ( 1 )
  {
    v4 = (_QWORD *)*v4;
    if ( v4 == (_QWORD *)(ipa3_ctx + 51272) )
      break;
    if ( v4[2] == v3 )
    {
      raw_notifier_chain_unregister(*(_QWORD *)(ipa3_ctx + 51264), v4 + 2);
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
      kfree(v4);
      v11 = printk(&unk_3F5071, "ipa_unregister_notifier");
      ipc_logbuf = ipa3_get_ipc_logbuf(v11);
      if ( ipc_logbuf )
      {
        v13 = ipa3_get_ipc_logbuf(ipc_logbuf);
        ipc_logbuf = ipc_log_string(
                       v13,
                       "ipa-wan %s:%d Client removed from list and unregistered succesfully\n",
                       "ipa_unregister_notifier",
                       3033);
      }
      ipc_logbuf_low = ipa3_get_ipc_logbuf_low(ipc_logbuf);
      if ( ipc_logbuf_low )
      {
        v15 = ipa3_get_ipc_logbuf_low(ipc_logbuf_low);
        ipc_log_string(
          v15,
          "ipa-wan %s:%d Client removed from list and unregistered succesfully\n",
          "ipa_unregister_notifier",
          3033);
      }
      raw_spin_unlock(ipa3_ctx + 51256);
      return 0;
    }
  }
  raw_spin_unlock(ipa3_ctx + 51256);
  v7 = printk(&unk_3A6983, "ipa_unregister_notifier");
  v8 = ipa3_get_ipc_logbuf(v7);
  if ( v8 )
  {
    v9 = ipa3_get_ipc_logbuf(v8);
    v8 = ipc_log_string(v9, "ipa-wan %s:%d Unable to find the client in the list\n", "ipa_unregister_notifier", 3039);
  }
  result = ipa3_get_ipc_logbuf_low(v8);
  if ( result )
  {
    v10 = ipa3_get_ipc_logbuf_low(result);
    ipc_log_string(v10, "ipa-wan %s:%d Unable to find the client in the list\n", "ipa_unregister_notifier", 3039);
    return 0;
  }
  return result;
}
