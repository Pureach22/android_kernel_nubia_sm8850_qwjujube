__int64 ipa3_uc_state_check()
{
  __int64 v1; // x8
  __int64 v2; // x0
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x0
  __int64 v7; // x8
  __int64 v8; // x0
  __int64 v9; // x0

  if ( (*(_BYTE *)(ipa3_ctx + 34656) & 1) == 0 )
  {
    printk(&unk_3FBC46, "ipa3_uc_state_check");
    v1 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v2 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v2 )
      {
        ipc_log_string(v2, "ipa %s:%d uC interface not initialized\n", "ipa3_uc_state_check", 651);
        v1 = ipa3_ctx;
      }
      v3 = *(_QWORD *)(v1 + 34160);
      if ( v3 )
        ipc_log_string(v3, "ipa %s:%d uC interface not initialized\n", "ipa3_uc_state_check", 651);
    }
    return 4294967282LL;
  }
  if ( (*(_BYTE *)(ipa3_ctx + 34657) & 1) == 0 )
  {
    printk(&unk_3CA366, "ipa3_uc_state_check");
    v4 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v5 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v5 )
      {
        ipc_log_string(v5, "ipa %s:%d uC is not loaded\n", "ipa3_uc_state_check", 656);
        v4 = ipa3_ctx;
      }
      v6 = *(_QWORD *)(v4 + 34160);
      if ( v6 )
        ipc_log_string(v6, "ipa %s:%d uC is not loaded\n", "ipa3_uc_state_check", 656);
    }
    return 4294967282LL;
  }
  if ( *(_BYTE *)(ipa3_ctx + 34658) == 1 )
  {
    printk(&unk_3D0358, "ipa3_uc_state_check");
    v7 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v8 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v8 )
      {
        ipc_log_string(v8, "ipa %s:%d uC has failed its last command\n", "ipa3_uc_state_check", 661);
        v7 = ipa3_ctx;
      }
      v9 = *(_QWORD *)(v7 + 34160);
      if ( v9 )
        ipc_log_string(v9, "ipa %s:%d uC has failed its last command\n", "ipa3_uc_state_check", 661);
    }
    return 4294967282LL;
  }
  return 0;
}
