__int64 ipa3_debugfs_init()
{
  unsigned __int64 dir; // x0
  _QWORD *v1; // x20
  __int64 v2; // x23
  const char *v3; // x19
  unsigned __int64 file; // x0
  __int64 result; // x0
  __int64 v6; // x8
  __int64 v7; // x0
  __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x0

  dir = debugfs_create_dir("ipa", 0);
  dent = dir;
  if ( dir >= 0xFFFFFFFFFFFFF001LL )
  {
    result = printk(&unk_3E09A4, "ipa3_debugfs_init");
    v6 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v7 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v7 )
      {
        ipc_log_string(v7, "ipa %s:%d fail to create folder in debug_fs.\n", "ipa3_debugfs_init", 3810);
        v6 = ipa3_ctx;
      }
      result = *(_QWORD *)(v6 + 34160);
      if ( result )
        return ipc_log_string(result, "ipa %s:%d fail to create folder in debug_fs.\n", "ipa3_debugfs_init", 3810);
    }
  }
  else
  {
    debugfs_create_u32("hw_type", 292, dir, ipa3_ctx + 32240);
    v1 = &unk_1B1F00;
    v2 = 53;
    do
    {
      v3 = (const char *)*(v1 - 3);
      file = debugfs_create_file(v3, *((unsigned __int16 *)v1 - 8), dent, *(v1 - 1), v1);
      if ( !file || file >= 0xFFFFFFFFFFFFF001LL )
      {
        printk(&unk_3E09D4, "ipa3_debugfs_init");
        v8 = ipa3_ctx;
        if ( ipa3_ctx )
        {
          v9 = *(_QWORD *)(ipa3_ctx + 34152);
          if ( v9 )
          {
            ipc_log_string(v9, "ipa %s:%d fail to create file for debug_fs %s\n", "ipa3_debugfs_init", 3824, v3);
            v8 = ipa3_ctx;
          }
          v10 = *(_QWORD *)(v8 + 34160);
          if ( v10 )
            ipc_log_string(v10, "ipa %s:%d fail to create file for debug_fs %s\n", "ipa3_debugfs_init", 3824, v3);
        }
        return debugfs_remove(dent);
      }
      --v2;
      v1 += 36;
    }
    while ( v2 );
    active_clients_buf = 0;
    active_clients_buf = _kmalloc_large_noprof(15616, 3520);
    if ( active_clients_buf )
    {
      debugfs_create_u32("enable_clock_scaling", 436, dent, ipa3_ctx + 34236);
      debugfs_create_u32("tx_wrapper_cache_max_size", 436, dent, ipa3_ctx + 48776);
      debugfs_create_u32("enable_napi_chain", 436, dent, ipa3_ctx + 34240);
      debugfs_create_u32("clock_scaling_bw_threshold_nominal_mbps", 436, dent, *(_QWORD *)(ipa3_ctx + 34176) + 28LL);
      debugfs_create_u32("clock_scaling_bw_threshold_turbo_mbps", 436, dent, *(_QWORD *)(ipa3_ctx + 34176) + 24LL);
      debugfs_create_u32("clk_rate", 292, dent, ipa3_ctx + 34244);
      ipa_debugfs_init_stats(dent);
      return ipa3_wigig_init_debugfs_i(dent);
    }
    return debugfs_remove(dent);
  }
  return result;
}
