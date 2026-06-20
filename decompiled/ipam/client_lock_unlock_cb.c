__int64 __fastcall client_lock_unlock_cb(int a1, char a2)
{
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 result; // x0
  __int64 v8; // x8
  __int64 (__fastcall *v9)(_QWORD); // x9
  __int64 v10; // x0

  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v5 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d entry\n", "client_lock_unlock_cb", 577);
      v4 = ipa3_ctx;
    }
    v6 = *(_QWORD *)(v4 + 34160);
    if ( v6 )
      ipc_log_string(v6, "ipa %s:%d entry\n", "client_lock_unlock_cb", 577);
  }
  result = ipa_get_client_cb_type(a1);
  if ( (_DWORD)result != 2 )
  {
    v8 = ipa3_ctx;
    v9 = *(__int64 (__fastcall **)(_QWORD))(ipa3_ctx + 8LL * (unsigned int)result + 45128);
    if ( v9 )
    {
      if ( *((_DWORD *)v9 - 1) != -2115900739 )
        __break(0x8229u);
      result = v9(a2 & 1);
      v8 = ipa3_ctx;
    }
    if ( v8 )
    {
      v10 = *(_QWORD *)(v8 + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d exit\n", "client_lock_unlock_cb", 586);
        v8 = ipa3_ctx;
      }
      result = *(_QWORD *)(v8 + 34160);
      if ( result )
        return ipc_log_string(result, "ipa %s:%d exit\n", "client_lock_unlock_cb", 586);
    }
  }
  return result;
}
