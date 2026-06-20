__int64 ipa3_inc_acquire_wakelock()
{
  __int64 v0; // x0
  __int64 v1; // x8
  __int64 v2; // x19
  int v3; // w10
  __int64 v4; // x0

  v0 = raw_spin_lock_irqsave(ipa3_ctx + 43336);
  v1 = ipa3_ctx;
  v2 = v0;
  v3 = *(_DWORD *)(ipa3_ctx + 43340);
  *(_DWORD *)(ipa3_ctx + 43340) = v3 + 1;
  if ( !v3 )
  {
    _pm_stay_awake(*(_QWORD *)(v1 + 43328));
    v1 = ipa3_ctx;
  }
  if ( v1 )
  {
    v4 = *(_QWORD *)(v1 + 34160);
    if ( v4 )
    {
      ipc_log_string(
        v4,
        "ipa %s:%d active wakelock ref cnt = %d\n",
        "ipa3_inc_acquire_wakelock",
        7220,
        *(_DWORD *)(v1 + 43340));
      v1 = ipa3_ctx;
    }
  }
  return raw_spin_unlock_irqrestore(v1 + 43336, v2);
}
