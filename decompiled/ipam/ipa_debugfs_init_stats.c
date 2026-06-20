__int64 __fastcall ipa_debugfs_init_stats(__int64 a1)
{
  _BYTE *v1; // x8
  unsigned __int64 dir; // x0
  unsigned __int64 v3; // x19
  unsigned __int64 file; // x0
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x0
  __int64 v10; // x8
  __int64 v11; // x0
  __int64 v12; // x0
  __int64 v13; // x8
  __int64 v14; // x0
  __int64 v15; // x0
  __int64 v16; // x8
  __int64 v17; // x0
  __int64 v18; // x0
  __int64 v19; // x8
  __int64 v20; // x0
  __int64 v21; // x0
  __int64 v22; // x8
  __int64 v23; // x0
  __int64 v24; // x0
  __int64 v25; // x8
  __int64 v26; // x0
  __int64 v27; // x0

  v1 = *(_BYTE **)(ipa3_ctx + 43800);
  if ( !v1 || *v1 != 1 )
    return 0;
  dir = debugfs_create_dir("hw_stats", a1);
  if ( !dir || (v3 = dir, dir >= 0xFFFFFFFFFFFFF001LL) )
  {
    printk(&unk_3FE0E1, "ipa_debugfs_init_stats");
    v10 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v11 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v11 )
      {
        ipc_log_string(v11, "ipa %s:%d fail to create folder in debug_fs\n", "ipa_debugfs_init_stats", 2888);
        v10 = ipa3_ctx;
      }
      v12 = *(_QWORD *)(v10 + 34160);
      if ( v12 )
        ipc_log_string(v12, "ipa %s:%d fail to create folder in debug_fs\n", "ipa_debugfs_init_stats", 2888);
    }
    return 4294967282LL;
  }
  file = debugfs_create_file("quota", 436, dir, 0, &ipa3_quota_ops);
  if ( !file || file >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_3C6F40, "ipa_debugfs_init_stats");
    v13 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v14 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v14 )
      {
        ipc_log_string(v14, "ipa %s:%d fail to create file %s\n", "ipa_debugfs_init_stats", 2895, "quota");
        v13 = ipa3_ctx;
      }
      v15 = *(_QWORD *)(v13 + 34160);
      if ( v15 )
        ipc_log_string(v15, "ipa %s:%d fail to create file %s\n", "ipa_debugfs_init_stats", 2895, "quota");
    }
    goto LABEL_47;
  }
  v5 = debugfs_create_file("drop", 436, v3, 0, &ipa3_drop_ops);
  if ( !v5 || v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_3C6F40, "ipa_debugfs_init_stats");
    v16 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v17 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v17 )
      {
        ipc_log_string(v17, "ipa %s:%d fail to create file %s\n", "ipa_debugfs_init_stats", 2902, "drop");
        v16 = ipa3_ctx;
      }
      v18 = *(_QWORD *)(v16 + 34160);
      if ( v18 )
        ipc_log_string(v18, "ipa %s:%d fail to create file %s\n", "ipa_debugfs_init_stats", 2902, "drop");
    }
    goto LABEL_47;
  }
  v6 = debugfs_create_file("enable_drop_stats", 144, v3, 0, &ipa3_enable_drop_ops);
  if ( !v6 || v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_3C6F40, "ipa_debugfs_init_stats");
    v19 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v20 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v20 )
      {
        ipc_log_string(v20, "ipa %s:%d fail to create file %s\n", "ipa_debugfs_init_stats", 2909, "enable_drop_stats");
        v19 = ipa3_ctx;
      }
      v21 = *(_QWORD *)(v19 + 34160);
      if ( v21 )
        ipc_log_string(v21, "ipa %s:%d fail to create file %s\n", "ipa_debugfs_init_stats", 2909, "enable_drop_stats");
    }
    goto LABEL_47;
  }
  v7 = debugfs_create_file("tethering", 436, v3, 0, &ipa3_tethering_ops);
  if ( !v7 || v7 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_3C6F40, "ipa_debugfs_init_stats");
    v22 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v23 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v23 )
      {
        ipc_log_string(v23, "ipa %s:%d fail to create file %s\n", "ipa_debugfs_init_stats", 2916, "tethering");
        v22 = ipa3_ctx;
      }
      v24 = *(_QWORD *)(v22 + 34160);
      if ( v24 )
        ipc_log_string(v24, "ipa %s:%d fail to create file %s\n", "ipa_debugfs_init_stats", 2916, "tethering");
    }
    goto LABEL_47;
  }
  v8 = debugfs_create_file("flt_rt", 436, v3, 0, &ipa3_flt_rt_ops);
  if ( !v8 || v8 >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_3C0F2C, "ipa_debugfs_init_stats");
    v25 = ipa3_ctx;
    if ( ipa3_ctx )
    {
      v26 = *(_QWORD *)(ipa3_ctx + 34152);
      if ( v26 )
      {
        ipc_log_string(v26, "ipa %s:%d fail to create file flt_rt\n", "ipa_debugfs_init_stats", 2923);
        v25 = ipa3_ctx;
      }
      v27 = *(_QWORD *)(v25 + 34160);
      if ( v27 )
        ipc_log_string(v27, "ipa %s:%d fail to create file flt_rt\n", "ipa_debugfs_init_stats", 2923);
    }
LABEL_47:
    debugfs_remove(v3);
    return 4294967282LL;
  }
  return 0;
}
