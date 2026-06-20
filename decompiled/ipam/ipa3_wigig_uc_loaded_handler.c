__int64 __fastcall ipa3_wigig_uc_loaded_handler(__int64 a1, __int64 a2, _QWORD *a3)
{
  _QWORD *v3; // x8
  __int64 v6; // x0
  __int64 v7; // x0
  void (__fastcall *v8)(_QWORD); // x9
  __int64 v9; // x0
  __int64 v10; // x0
  __int64 result; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0

  v3 = (_QWORD *)ipa3_ctx;
  if ( !ipa3_ctx )
    goto LABEL_20;
  v6 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v6 )
  {
    ipc_log_string(v6, "ipa %s:%d val %ld\n", "ipa3_wigig_uc_loaded_handler", 56, a2);
    v3 = (_QWORD *)ipa3_ctx;
  }
  v7 = v3[4270];
  if ( v7 )
  {
    ipc_log_string(v7, "ipa %s:%d val %ld\n", "ipa3_wigig_uc_loaded_handler", 56, a2);
    v3 = (_QWORD *)ipa3_ctx;
  }
  if ( v3 )
  {
    if ( v3 != a3 )
    {
      __break(0x800u);
      v3 = (_QWORD *)ipa3_ctx;
    }
    v8 = (void (__fastcall *)(_QWORD))v3[5405];
    if ( v8 )
    {
      v9 = v3[5404];
      if ( *((_DWORD *)v8 - 1) != 251140989 )
        __break(0x8229u);
      v8(v9);
      v3 = (_QWORD *)ipa3_ctx;
      *(_QWORD *)(ipa3_ctx + 43232) = 0;
      v3[5405] = 0;
    }
    if ( !v3 )
      return 0;
    v10 = v3[4269];
    if ( v10 )
    {
      ipc_log_string(v10, "ipa %s:%d exit\n", "ipa3_wigig_uc_loaded_handler", 74);
      v3 = (_QWORD *)ipa3_ctx;
    }
    result = v3[4270];
    if ( result )
    {
      ipc_log_string(result, "ipa %s:%d exit\n", "ipa3_wigig_uc_loaded_handler", 74);
      return 0;
    }
  }
  else
  {
LABEL_20:
    printk(&unk_3A437D, "ipa3_wigig_uc_loaded_handler");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d IPA ctx is null\n", "ipa3_wigig_uc_loaded_handler", 59);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d IPA ctx is null\n", "ipa3_wigig_uc_loaded_handler", 59);
    }
    return 4294967274LL;
  }
  return result;
}
