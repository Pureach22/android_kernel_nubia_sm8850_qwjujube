__int64 ipa3_uc_mhi_cleanup()
{
  __int64 v0; // x8
  __int64 v1; // x0
  __int64 v2; // x0
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  void *v8[6]; // [xsp+0h] [xbp-30h] BYREF

  v8[5] = *(void **)(_ReadStatusReg(SP_EL0) + 1808);
  v0 = ipa3_ctx;
  memset(v8, 0, 40);
  if ( ipa3_ctx )
  {
    v1 = *(_QWORD *)(ipa3_ctx + 34152);
    if ( v1 )
    {
      ipc_log_string(v1, "ipa %s:%d Enter\n", "ipa3_uc_mhi_cleanup", 603);
      v0 = ipa3_ctx;
    }
    v2 = *(_QWORD *)(v0 + 34160);
    if ( v2 )
      ipc_log_string(v2, "ipa %s:%d Enter\n", "ipa3_uc_mhi_cleanup", 603);
  }
  if ( ipa3_uc_mhi_ctx )
  {
    ipa3_uc_register_handlers(1u, v8);
    result = kfree(ipa3_uc_mhi_ctx);
    v4 = ipa3_ctx;
    ipa3_uc_mhi_ctx = 0;
    if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d Done\n", "ipa3_uc_mhi_cleanup", 613);
        v4 = ipa3_ctx;
      }
      result = *(_QWORD *)(v4 + 34160);
      if ( result )
        result = ipc_log_string(result, "ipa %s:%d Done\n", "ipa3_uc_mhi_cleanup", 613);
    }
  }
  else
  {
    result = printk(&unk_3BBAD1, "ipa3_uc_mhi_cleanup");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d ipa3_uc_mhi_ctx is not initialized\n", "ipa3_uc_mhi_cleanup", 606);
        v6 = ipa3_ctx;
      }
      result = *(_QWORD *)(v6 + 34160);
      if ( result )
        result = ipc_log_string(result, "ipa %s:%d ipa3_uc_mhi_ctx is not initialized\n", "ipa3_uc_mhi_cleanup", 606);
    }
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
