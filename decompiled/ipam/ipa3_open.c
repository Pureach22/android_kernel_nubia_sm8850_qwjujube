__int64 __fastcall ipa3_open(__int64 a1, __int64 a2)
{
  __int64 v3; // x8
  __int64 v4; // x0

  v3 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34160);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d ENTER\n", "ipa3_open", 1001);
      v3 = ipa3_ctx;
    }
  }
  *(_QWORD *)(a2 + 32) = v3;
  return 0;
}
