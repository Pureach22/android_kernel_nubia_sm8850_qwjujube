long double __fastcall ipa_wigig_free_msg(const void *a1, int a2, int a3)
{
  __int64 v4; // x8
  __int64 v7; // x0
  __int64 v8; // x0
  long double result; // q0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0

  v4 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d free msg type:%d, len:%d, buff %pK", "ipa_wigig_free_msg", 1905, a3, a2, a1);
      v4 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v4 + 34160);
    if ( v8 )
      ipc_log_string(v8, "ipa %s:%d free msg type:%d, len:%d, buff %pK", "ipa_wigig_free_msg", 1905, a3, a2, a1);
  }
  kfree(a1);
  v10 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v11 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v11 )
    {
      result = ipc_log_string(v11, "ipa %s:%d exit\n", "ipa_wigig_free_msg", 1907);
      v10 = ipa3_ctx;
    }
    v12 = *(_QWORD *)(v10 + 34160);
    if ( v12 )
      return ipc_log_string(v12, "ipa %s:%d exit\n", "ipa_wigig_free_msg", 1907);
  }
  return result;
}
