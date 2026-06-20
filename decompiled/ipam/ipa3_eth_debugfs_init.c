__int64 ipa3_eth_debugfs_init()
{
  __int64 dir; // x0
  __int64 result; // x0
  __int64 v2; // x8
  __int64 v3; // x0
  __int64 v4; // x8
  __int64 v5; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x0

  if ( dent && (unsigned __int64)dent < 0xFFFFFFFFFFFFF001LL )
  {
    dir = debugfs_create_dir("eth", dent);
    dent_eth = dir;
    if ( (unsigned __int64)dent >= 0xFFFFFFFFFFFFF001LL )
    {
      result = printk(&unk_3E09A4, "ipa3_eth_debugfs_init");
      v4 = ipa3_ctx;
      if ( ipa3_ctx )
      {
        v5 = *(_QWORD *)(ipa3_ctx + 34152);
        if ( v5 )
        {
          ipc_log_string(v5, "ipa %s:%d fail to create folder in debug_fs.\n", "ipa3_eth_debugfs_init", 3943);
          v4 = ipa3_ctx;
        }
        result = *(_QWORD *)(v4 + 34160);
        if ( result )
          return ipc_log_string(result, "ipa %s:%d fail to create folder in debug_fs.\n", "ipa3_eth_debugfs_init", 3943);
      }
    }
    else
    {
      result = debugfs_create_file("status", 292, dir, 0, &fops_ipa_eth_status);
      if ( !result )
      {
        printk(&unk_3E9236, "ipa3_eth_debugfs_init");
        v6 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v7 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v7 )
          {
            ipc_log_string(v7, "ipa %s:%d could not create status\n", "ipa3_eth_debugfs_init", 3949);
            v6 = ipa3_ctx;
          }
          v8 = *(_QWORD *)(v6 + 34160);
          if ( v8 )
            ipc_log_string(v8, "ipa %s:%d could not create status\n", "ipa3_eth_debugfs_init", 3949);
        }
        return debugfs_remove(dent_eth);
      }
    }
  }
  else
  {
    result = printk(&unk_3DE02B, "ipa3_eth_debugfs_init");
    v2 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v3 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v3 )
      {
        ipc_log_string(v3, "ipa %s:%d debugs root not created\n", "ipa3_eth_debugfs_init", 3938);
        v2 = ipa3_ctx;
      }
      result = *(_QWORD *)(v2 + 34160);
      if ( result )
        return ipc_log_string(result, "ipa %s:%d debugs root not created\n", "ipa3_eth_debugfs_init", 3938);
    }
  }
  return result;
}
