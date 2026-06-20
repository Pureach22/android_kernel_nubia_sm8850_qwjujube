__int64 ipa_adpl_release()
{
  unsigned int v0; // w19
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x0

  mutex_lock(ipa3_odl_ctx + 384);
  v0 = ((__int64 (__fastcall *)(_QWORD))ipa_pm_deactivate_sync)(*(unsigned int *)(ipa3_odl_ctx + 716));
  if ( v0 )
  {
    printk(&unk_3D5D44, "ipa_adpl_release");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d failed to activate pm\n", "ipa_adpl_release", 458);
        v2 = ipa3_ctx;
      }
      v4 = *(_QWORD *)(v2 + 34160);
      if ( v4 )
        ipc_log_string(v4, "ipa %s:%d failed to activate pm\n", "ipa_adpl_release", 458);
    }
  }
  ipa3_odl_pipe_cleanup(0);
  mutex_unlock(ipa3_odl_ctx + 384);
  return v0;
}
