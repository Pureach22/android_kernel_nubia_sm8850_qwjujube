void __fastcall ipa_wdi_pm_wrapper_cb(__int64 a1, int a2)
{
  __int64 v2; // x8
  __int64 v4; // x0
  __int64 v5; // x0

  v2 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d received pm event %d\n", "ipa_wdi_pm_wrapper_cb", 3359, a2);
      v2 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v2 + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d received pm event %d\n", "ipa_wdi_pm_wrapper_cb", 3359, a2);
  }
}
