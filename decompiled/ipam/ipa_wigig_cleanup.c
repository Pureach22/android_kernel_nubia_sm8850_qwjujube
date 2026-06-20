__int64 ipa_wigig_cleanup()
{
  __int64 ipc_logbuf; // x0
  __int64 ipc_logbuf_low; // x0
  __int64 v2; // x8
  _QWORD *v3; // x9
  _QWORD *v4; // x8
  _QWORD *v5; // x21
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x0

  if ( ipa3_get_ipc_logbuf() )
  {
    ipc_logbuf = ipa3_get_ipc_logbuf();
    ipc_log_string(ipc_logbuf, "ipa_wigig %s:%d \n", "ipa_wigig_cleanup", 193);
  }
  if ( ipa3_get_ipc_logbuf_low() )
  {
    ipc_logbuf_low = ipa3_get_ipc_logbuf_low();
    ipc_log_string(ipc_logbuf_low, "ipa_wigig %s:%d \n", "ipa_wigig_cleanup", 193);
  }
  v2 = ipa_wigig_ctx;
  if ( !ipa_wigig_ctx )
    return 4294967277LL;
  v3 = *(_QWORD **)ipa_wigig_ctx;
  if ( *(_QWORD *)ipa_wigig_ctx != ipa_wigig_ctx )
  {
    do
    {
      v5 = (_QWORD *)*v3;
      v4 = (_QWORD *)v3[1];
      if ( (_QWORD *)*v4 == v3 && (_QWORD *)v5[1] == v3 )
      {
        v5[1] = v4;
        *v4 = v5;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
      }
      *v3 = 0xDEAD000000000100LL;
      v3[1] = 0xDEAD000000000122LL;
      kfree(v3 - 6);
      v2 = ipa_wigig_ctx;
      v3 = v5;
    }
    while ( v5 != (_QWORD *)ipa_wigig_ctx );
  }
  debugfs_remove(*(_QWORD *)(v2 + 920));
  debugfs_remove(*(_QWORD *)(ipa_wigig_ctx + 928));
  kfree(ipa_wigig_ctx);
  ipa_wigig_ctx = 0;
  if ( ipa3_get_ipc_logbuf() )
  {
    v6 = ipa3_get_ipc_logbuf();
    ipc_log_string(v6, "ipa_wigig %s:%d exit\n", "ipa_wigig_cleanup", 212);
  }
  result = ipa3_get_ipc_logbuf_low();
  if ( result )
  {
    v8 = ipa3_get_ipc_logbuf_low();
    ipc_log_string(v8, "ipa_wigig %s:%d exit\n", "ipa_wigig_cleanup", 212);
    return 0;
  }
  return result;
}
