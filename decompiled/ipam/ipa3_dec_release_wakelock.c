__int64 ipa3_dec_release_wakelock()
{
  __int64 v0; // x0
  __int64 v1; // x8
  __int64 v2; // x19
  int v3; // w4
  __int64 v4; // x0

  v0 = raw_spin_lock_irqsave(ipa3_ctx + 43336);
  v1 = ipa3_ctx;
  v2 = v0;
  v3 = *(_DWORD *)(ipa3_ctx + 43340) - 1;
  *(_DWORD *)(ipa3_ctx + 43340) = v3;
  if ( v1 )
  {
    v4 = *(_QWORD *)(v1 + 34160);
    if ( v4 )
    {
      ipc_log_string(v4, "ipa %s:%d active wakelock ref cnt = %d\n", "ipa3_dec_release_wakelock", 7239, v3);
      v1 = ipa3_ctx;
      v3 = *(_DWORD *)(ipa3_ctx + 43340);
    }
  }
  if ( !v3 )
  {
    _pm_relax(*(_QWORD *)(v1 + 43328));
    v1 = ipa3_ctx;
  }
  return raw_spin_unlock_irqrestore(v1 + 43336, v2);
}
