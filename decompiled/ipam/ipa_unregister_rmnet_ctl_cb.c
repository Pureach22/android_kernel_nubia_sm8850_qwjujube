__int64 ipa_unregister_rmnet_ctl_cb()
{
  __int64 v0; // x8
  __int64 v1; // x8
  int v2; // w9
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 result; // x0
  __int64 v7; // x0
  __int64 v8; // x0
  __int64 v9; // x8
  __int64 v10; // x0
  __int64 v11; // x0
  __int64 v12; // x8
  __int64 v13; // x0
  __int64 v14; // x0

  v0 = ipa3_ctx;
  if ( !ipa3_ctx )
    return 4294967285LL;
  if ( (*(_BYTE *)(ipa3_ctx + 48858) & 1) == 0 )
  {
    printk(&unk_3E1D62, "ipa_unregister_rmnet_ctl_cb");
    v12 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v13 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v13 )
      {
        ipc_log_string(v13, "ipa %s:%d low lat pipe is disabled", "ipa_unregister_rmnet_ctl_cb", 182);
        v12 = ipa3_ctx;
      }
      v14 = *(_QWORD *)(v12 + 34160);
      if ( v14 )
        ipc_log_string(v14, "ipa %s:%d low lat pipe is disabled", "ipa_unregister_rmnet_ctl_cb", 182);
    }
    return 4294967290LL;
  }
  if ( !rmnet_ctl_ipa3_ctx )
  {
    v7 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v7 )
    {
      ipc_log_string(v7, "ipa %s:%d rmnet_ctl_ctx haven't initialized\n", "ipa_unregister_rmnet_ctl_cb", 187);
      v0 = ipa3_ctx;
    }
    v8 = *(_QWORD *)(v0 + 34160);
    if ( v8 )
      ipc_log_string(v8, "ipa %s:%d rmnet_ctl_ctx haven't initialized\n", "ipa_unregister_rmnet_ctl_cb", 187);
    return 4294967285LL;
  }
  mutex_lock(rmnet_ctl_ipa3_ctx + 672);
  v1 = rmnet_ctl_ipa3_ctx;
  v2 = *(_DWORD *)(rmnet_ctl_ipa3_ctx + 56);
  if ( (v2 | 2) != 3 )
  {
    v9 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v10 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v10 )
      {
        ipc_log_string(v10, "ipa %s:%d rmnet_ctl unregistered already\n", "ipa_unregister_rmnet_ctl_cb", 194);
        v9 = ipa3_ctx;
      }
      v11 = *(_QWORD *)(v9 + 34160);
      if ( v11 )
        ipc_log_string(v11, "ipa %s:%d rmnet_ctl unregistered already\n", "ipa_unregister_rmnet_ctl_cb", 194);
    }
    mutex_unlock(rmnet_ctl_ipa3_ctx + 672);
    return 0;
  }
  v3 = *(unsigned int *)(rmnet_ctl_ipa3_ctx + 664);
  *(_QWORD *)(rmnet_ctl_ipa3_ctx + 632) = 0;
  *(_QWORD *)(v1 + 624) = 0;
  *(_QWORD *)(v1 + 616) = 0;
  *(_QWORD *)(v1 + 608) = 0;
  *(_QWORD *)(v1 + 600) = 0;
  *(_QWORD *)(v1 + 592) = 0;
  *(_DWORD *)(v1 + 56) = 2 * (v2 != 1);
  ((void (__fastcall *)(__int64))ipa_pm_deactivate_sync)(v3);
  ((void (__fastcall *)(_QWORD))ipa_pm_deregister)(*(unsigned int *)(rmnet_ctl_ipa3_ctx + 664));
  mutex_unlock(rmnet_ctl_ipa3_ctx + 672);
  v4 = ipa3_ctx;
  if ( !ipa3_ctx )
    return 0;
  v5 = *(_QWORD *)(ipa3_ctx + 34152);
  if ( v5 )
  {
    ipc_log_string(v5, "ipa %s:%d rmnet_ctl unregistered successfually\n", "ipa_unregister_rmnet_ctl_cb", 212);
    v4 = ipa3_ctx;
  }
  result = *(_QWORD *)(v4 + 34160);
  if ( result )
  {
    ipc_log_string(result, "ipa %s:%d rmnet_ctl unregistered successfually\n", "ipa_unregister_rmnet_ctl_cb", 212);
    return 0;
  }
  return result;
}
