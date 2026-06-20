__int64 ipa3_wigig_deinit_i()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 v3; // x8
  __int64 v4; // x0
  __int64 v5; // x0

  v0 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d \n", "ipa3_wigig_deinit_i", 95);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
      ipc_log_string(v2, "ipa %s:%d \n", "ipa3_wigig_deinit_i", 95);
  }
  ipa3_uc_unregister_ready_cb((__int64)&uc_loaded_notifier_0);
  v3 = ipa3_ctx;
  if ( ipa3_ctx )
  {
    v4 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d exit\n", "ipa3_wigig_deinit_i", 99);
      v3 = ipa3_ctx;
    }
    v5 = *(_QWORD *)(v3 + 34160);
    if ( v5 )
      ipc_log_string(v5, "ipa %s:%d exit\n", "ipa3_wigig_deinit_i", 99);
  }
  return 0;
}
