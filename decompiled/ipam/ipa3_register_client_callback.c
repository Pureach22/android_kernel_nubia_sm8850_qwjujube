__int64 __fastcall ipa3_register_client_callback(__int64 a1, __int64 a2, unsigned int a3)
{
  __int64 v5; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 result; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0

  v5 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d entry\n", "ipa3_register_client_callback", 532);
      v5 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v5 + 34160);
    if ( v8 )
      ipc_log_string(v8, "ipa %s:%d entry\n", "ipa3_register_client_callback", 532);
  }
  result = ipa_get_client_cb_type(a3);
  if ( (_DWORD)result != 2 )
  {
    if ( a1 )
    {
      v10 = ipa3_ctx;
      if ( !*(_QWORD *)(ipa3_ctx + 45128 + 8LL * (unsigned int)result) )
      {
        *(_QWORD *)(ipa3_ctx + 45128 + 8LL * (unsigned int)result) = a1;
        v10 = ipa3_ctx;
      }
      if ( !*(_QWORD *)(v10 + 45200 + 8LL * (unsigned int)result) )
      {
        *(_QWORD *)(v10 + 45200 + 8LL * (unsigned int)result) = a2;
        v10 = ipa3_ctx;
      }
      if ( v10 )
      {
        v11 = *(_QWORD *)(v10 + 34152);
        if ( v11 )
        {
          ipc_log_string(v11, "ipa %s:%d exit\n", "ipa3_register_client_callback", 547);
          v10 = ipa3_ctx;
        }
        result = *(_QWORD *)(v10 + 34160);
        if ( result )
          return ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_register_client_callback", 547);
      }
    }
    else
    {
      result = printk(&unk_3D530C, "ipa3_register_client_callback");
      v12 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v13 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v13 )
        {
          ipc_log_string(v13, "ipa %s:%d Bad Param", "ipa3_register_client_callback", 539);
          v12 = ipa3_ctx;
        }
        result = *(_QWORD *)(v12 + 34160);
        if ( result )
          return ipc_log_string(result, "ipa %s:%d Bad Param", "ipa3_register_client_callback", 539);
      }
    }
  }
  return result;
}
