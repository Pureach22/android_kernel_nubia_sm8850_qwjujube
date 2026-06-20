__int64 __fastcall ipa3_deregister_pull_msg(unsigned __int8 *a1)
{
  __int64 v2; // x8
  _QWORD *v3; // x9
  _QWORD *v4; // x10
  _QWORD *v5; // x8
  _QWORD *v6; // x0
  unsigned int v7; // w19
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0
  _QWORD *v12; // x10

  if ( a1 )
  {
    mutex_lock(ipa3_ctx + 32104);
    v2 = ipa3_ctx;
    v3 = *(_QWORD **)(ipa3_ctx + 32088);
    if ( v3 == (_QWORD *)(ipa3_ctx + 32088) )
    {
LABEL_11:
      v7 = -22;
    }
    else
    {
      while ( 1 )
      {
        v4 = (_QWORD *)*v3;
        if ( *((unsigned __int16 *)v3 - 7) == *((unsigned __int16 *)a1 + 1) && *((unsigned __int8 *)v3 - 16) == *a1 )
          break;
        v3 = (_QWORD *)*v3;
        if ( v4 == (_QWORD *)(ipa3_ctx + 32088) )
          goto LABEL_11;
      }
      v5 = (_QWORD *)v3[1];
      v6 = v3 - 2;
      if ( (_QWORD *)*v5 == v3 && (_QWORD *)v4[1] == v3 )
      {
        v4[1] = v5;
        *v5 = v4;
      }
      else
      {
        _list_del_entry_valid_or_report(v3);
        v6 = v12;
      }
      *v3 = 0xDEAD000000000100LL;
      v3[1] = 0xDEAD000000000122LL;
      kfree(v6);
      v2 = ipa3_ctx;
      v7 = 0;
    }
    mutex_unlock(v2 + 32104);
  }
  else
  {
    if ( (unsigned int)__ratelimit(&ipa3_deregister_pull_msg__rs, "ipa3_deregister_pull_msg") )
      printk(&unk_3E67F7, "ipa3_deregister_pull_msg");
    v8 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v9 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v9 )
      {
        ipc_log_string(v9, "ipa %s:%d null arg: meta\n", "ipa3_deregister_pull_msg", 672);
        v8 = ipa3_ctx;
      }
      v10 = *(_QWORD *)(v8 + 34160);
      if ( v10 )
        ipc_log_string(v10, "ipa %s:%d null arg: meta\n", "ipa3_deregister_pull_msg", 672);
    }
    return (unsigned int)-22;
  }
  return v7;
}
