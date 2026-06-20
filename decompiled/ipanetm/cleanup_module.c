__int64 __fastcall cleanup_module(__int64 a1)
{
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 v3; // x0

  v1 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v2 = *(_QWORD *)(ipa3_ctx + 34152LL);
    if ( v2 )
    {
      ipc_log_string(v2, "ipa %s:%d IPA late exit\n", "ipa_late_exit", 52);
      v1 = ipa3_ctx;
    }
    a1 = *(_QWORD *)(v1 + 34160);
    if ( a1 )
      a1 = ipc_log_string(a1, "ipa %s:%d IPA late exit\n", "ipa_late_exit", 52);
  }
  v3 = ipa3_wwan_cleanup(a1);
  return rndis_ipa_cleanup_module(v3);
}
