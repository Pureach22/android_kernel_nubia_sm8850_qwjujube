void __fastcall ipa3_uc_wigig_misc_int_handler(__int64 a1, _QWORD *a2)
{
  _QWORD *v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0
  void (__fastcall *v6)(_QWORD); // x9
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x0

  v3 = (_QWORD *)ipa3_ctx;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d \n", "ipa3_uc_wigig_misc_int_handler", 941);
      v3 = (_QWORD *)ipa3_ctx;
    }
    v5 = v3[4270];
    if ( v5 )
    {
      ipc_log_string(v5, "ipa %s:%d \n", "ipa3_uc_wigig_misc_int_handler", 941);
      v3 = (_QWORD *)ipa3_ctx;
    }
  }
  if ( v3 != a2 )
  {
    __break(0x800u);
    v3 = (_QWORD *)ipa3_ctx;
  }
  v6 = (void (__fastcall *)(_QWORD))v3[5406];
  if ( v6 )
  {
    v7 = v3[5404];
    if ( *((_DWORD *)v6 - 1) != 251140989 )
      __break(0x8229u);
    v6(v7);
    v3 = (_QWORD *)ipa3_ctx;
  }
  if ( v3 )
  {
    v8 = v3[4269];
    if ( v8 )
    {
      ipc_log_string(v8, "ipa %s:%d exit\n", "ipa3_uc_wigig_misc_int_handler", 949);
      v3 = (_QWORD *)ipa3_ctx;
    }
    v9 = v3[4270];
    if ( v9 )
      ipc_log_string(v9, "ipa %s:%d exit\n", "ipa3_uc_wigig_misc_int_handler", 949);
  }
}
