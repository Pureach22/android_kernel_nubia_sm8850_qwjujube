__int64 __fastcall ipa3_deregister_client_callback(int a1)
{
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0
  __int64 result; // x0
  __int64 v6; // x9
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0

  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v3 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v3 )
    {
      ipc_log_string(v3, "ipa %s:%d entry\n", "ipa3_deregister_client_callback", 555);
      v2 = ipa3_ctx;
    }
    v4 = *(_QWORD *)(v2 + 34160);
    if ( v4 )
      ipc_log_string(v4, "ipa %s:%d entry\n", "ipa3_deregister_client_callback", 555);
  }
  result = ipa_get_client_cb_type(a1);
  if ( (_DWORD)result != 2 )
  {
    if ( *(_QWORD *)(ipa3_ctx + 45128 + 8LL * (unsigned int)result)
      || *(_QWORD *)(ipa3_ctx + 8LL * (unsigned int)result + 45200) )
    {
      v6 = 8LL * (unsigned int)result;
      *(_QWORD *)(ipa3_ctx + 45128 + v6) = 0;
      *(_QWORD *)(ipa3_ctx + v6 + 45200) = 0;
      v7 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v8 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v8 )
        {
          ipc_log_string(v8, "ipa %s:%d exit\n", "ipa3_deregister_client_callback", 569);
          v7 = ipa3_ctx;
        }
        result = *(_QWORD *)(v7 + 34160);
        if ( result )
          return ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_deregister_client_callback", 569);
      }
    }
    else
    {
      result = printk(&unk_3C687A, "ipa3_deregister_client_callback");
      v9 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v10 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v10 )
        {
          ipc_log_string(v10, "ipa %s:%d client_lock_unlock is already NULL", "ipa3_deregister_client_callback", 563);
          v9 = ipa3_ctx;
        }
        result = *(_QWORD *)(v9 + 34160);
        if ( result )
          return ipc_log_string(
                   result,
                   "ipa %s:%d client_lock_unlock is already NULL",
                   "ipa3_deregister_client_callback",
                   563);
      }
    }
  }
  return result;
}
