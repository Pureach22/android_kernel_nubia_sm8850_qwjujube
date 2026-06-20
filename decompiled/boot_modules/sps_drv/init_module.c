__int64 init_module()
{
  unsigned __int64 dir; // x0
  __int64 v1; // x1
  __int64 v2; // x2
  __int64 v3; // x1
  __int64 v4; // x2
  unsigned __int64 file; // x8
  void *v6; // x0
  unsigned __int64 v7; // x8
  unsigned __int64 v8; // x8
  __int64 v9; // x0
  __int64 v10; // x1
  __int64 v11; // x2
  __int64 v12; // x0
  __int64 v13; // x1
  __int64 v14; // x2
  __int64 v15; // x0
  __int64 v16; // x1
  __int64 v17; // x2
  __int64 v18; // x0
  __int64 v19; // x1
  __int64 v20; // x2
  __int64 v21; // x0
  __int64 v22; // x1
  __int64 v23; // x2

  debugfs_record_enabled = 0;
  debug_level_option = 0;
  print_limit_option = 0;
  reg_dump_option = 0;
  testbus_sel = 0;
  bam_pipe_sel = 0;
  desc_option = 0;
  debugfs_buf_size = 0;
  debugfs_buf_used = 0;
  logging_option = 0;
  wraparound = 0;
  log_level_sel = 5;
  dir = debugfs_create_dir(&unk_237F7, 0);
  dent = dir;
  if ( dir >= 0xFFFFFFFFFFFFF001LL )
  {
    printk(&unk_23497, v1, v2);
  }
  else
  {
    file = debugfs_create_file("info", 436, dir, 0, &sps_info_ops);
    dfile_info = file;
    v6 = &unk_27912;
    if ( !file )
      goto LABEL_22;
    if ( file > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_22;
    v7 = debugfs_create_file("logging_option", 436, dent, 0, &sps_logging_option_ops);
    dfile_logging_option = v7;
    v6 = &unk_28E68;
    if ( !v7 )
      goto LABEL_22;
    if ( v7 > 0xFFFFFFFFFFFFF000LL )
      goto LABEL_22;
    debugfs_create_u8("debug_level_option", 436, dent, &debug_level_option);
    debugfs_create_u8("print_limit_option", 436, dent, &print_limit_option);
    debugfs_create_u8("reg_dump_option", 436, dent, &reg_dump_option);
    debugfs_create_u32("testbus_sel", 436, dent, &testbus_sel);
    debugfs_create_u32("bam_pipe_sel", 436, dent, &bam_pipe_sel);
    debugfs_create_u32("desc_option", 436, dent, &desc_option);
    v8 = debugfs_create_file("bam_addr", 436, dent, 0, &sps_bam_addr_ops);
    dfile_bam_addr = v8;
    v6 = &unk_2623D;
    if ( !v8 )
      goto LABEL_22;
    if ( v8 <= 0xFFFFFFFFFFFFF000LL )
    {
      debugfs_create_u32("log_level_sel", 436, dent, &log_level_sel);
      _mutex_init(&sps_debugfs_lock, "&sps_debugfs_lock", &sps_debugfs_init___key);
    }
    else
    {
LABEL_22:
      printk(v6, v3, v4);
      debugfs_remove(dent);
    }
  }
  sps = _kmalloc_cache_noprof(_list_add_valid_or_report, 3520, 296);
  if ( !sps )
    return 4294967284LL;
  v9 = ipc_log_context_create(10, "sps_ipc_log0", 0);
  *(_QWORD *)(sps + 248) = v9;
  if ( !v9 )
    printk(&unk_280D4, v10, v11);
  v12 = ipc_log_context_create(10, "sps_ipc_log1", 0);
  *(_QWORD *)(sps + 256) = v12;
  if ( !v12 )
    printk(&unk_24FEB, v13, v14);
  v15 = ipc_log_context_create(10, "sps_ipc_log2", 0);
  *(_QWORD *)(sps + 264) = v15;
  if ( !v15 )
    printk(&unk_25008, v16, v17);
  v18 = ipc_log_context_create(10, "sps_ipc_log3", 0);
  *(_QWORD *)(sps + 272) = v18;
  if ( !v18 )
    printk(&unk_237DA, v19, v20);
  v21 = ipc_log_context_create(30, "sps_ipc_log4", 0);
  *(_QWORD *)(sps + 280) = v21;
  if ( !v21 )
    printk(&unk_278F5, v22, v23);
  return _platform_driver_register(msm_sps_driver, &_this_module);
}
