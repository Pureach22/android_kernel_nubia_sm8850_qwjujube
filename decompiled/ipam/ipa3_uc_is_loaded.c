__int64 ipa3_uc_is_loaded()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0

  v0 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d \n", "ipa3_uc_is_loaded", 7689);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
    {
      ipc_log_string(v2, "ipa %s:%d \n", "ipa3_uc_is_loaded", 7689);
      v0 = ipa3_ctx;
    }
  }
  return complete_all(v0 + 43688);
}
