__int64 ipa_eth_ready_notify_work()
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v2; // x8
  _QWORD *v3; // x19
  __int64 v4; // x8
  _QWORD *v5; // x22
  void (__fastcall *v6)(_QWORD); // x9
  __int64 v7; // x0
  _QWORD *v8; // x8
  _QWORD *v9; // x9

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_eth %s:%d ipa_eth ready notify\n", "ipa_eth_ready_notify_work", 204);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_eth %s:%d ipa_eth ready notify\n", "ipa_eth_ready_notify_work", 204);
  }
  mutex_lock(ipa_eth_ctx + 192);
  v2 = ipa_eth_ctx;
  v3 = *(_QWORD **)ipa_eth_ctx;
  *(_BYTE *)(ipa_eth_ctx + 248) = 1;
  if ( v3 != (_QWORD *)v2 )
  {
    do
    {
      v4 = v3[2];
      v5 = (_QWORD *)*v3;
      if ( v4 )
      {
        v6 = *(void (__fastcall **)(_QWORD))v4;
        if ( *(_QWORD *)v4 )
        {
          v7 = *(_QWORD *)(v4 + 8);
          if ( *((_DWORD *)v6 - 1) != 251140989 )
            __break(0x8229u);
          v6(v7);
        }
      }
      v8 = (_QWORD *)v3[1];
      if ( (_QWORD *)*v8 == v3 && (v9 = (_QWORD *)*v3, *(_QWORD **)(*v3 + 8LL) == v3) )
      {
        v9[1] = v8;
        *v8 = v9;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      *v3 = 0xDEAD000000000100LL;
      v3[1] = 0xDEAD000000000122LL;
      kfree(v3);
      v2 = ipa_eth_ctx;
      v3 = v5;
    }
    while ( v5 != (_QWORD *)ipa_eth_ctx );
  }
  return mutex_unlock(v2 + 192);
}
