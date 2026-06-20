unsigned __int64 gsi_debugfs_init()
{
  unsigned __int64 dir; // x0
  unsigned __int64 file; // x0
  unsigned __int64 v2; // x0
  unsigned __int64 v3; // x0
  unsigned __int64 v4; // x0
  unsigned __int64 v5; // x0
  unsigned __int64 v6; // x0
  unsigned __int64 v7; // x0
  unsigned __int64 v8; // x0
  unsigned __int64 v9; // x0
  unsigned __int64 result; // x0
  void *v11; // x0
  __int64 v12; // x2

  dir = debugfs_create_dir("gsi", 0);
  dent = dir;
  if ( dir >= 0xFFFFFFFFFFFFF001LL )
    return printk(&unk_2AB48, "gsi_debugfs_init", 730);
  file = debugfs_create_file("ev_dump", 144, dir, 0, &gsi_ev_dump_ops);
  gsi_debugfs_init_dfile = file;
  if ( !file || file >= 0xFFFFFFFFFFFFF001LL )
  {
    v11 = &unk_2E015;
    v12 = 737;
    goto LABEL_33;
  }
  v2 = debugfs_create_file("ch_dump", 144, dent, 0, &gsi_ch_dump_ops);
  gsi_debugfs_init_dfile = v2;
  if ( !v2 || v2 >= 0xFFFFFFFFFFFFF001LL )
  {
    v11 = &unk_2A890;
    v12 = 744;
    goto LABEL_33;
  }
  v3 = debugfs_create_file("stats", 144, dent, 0, &gsi_stats_ops);
  gsi_debugfs_init_dfile = v3;
  if ( !v3 || v3 >= 0xFFFFFFFFFFFFF001LL )
  {
    v11 = &unk_2E03A;
    v12 = 751;
    goto LABEL_33;
  }
  v4 = debugfs_create_file("enable_dp_stats", 144, dent, 0, &gsi_enable_dp_stats_ops);
  gsi_debugfs_init_dfile = v4;
  if ( !v4 || v4 >= 0xFFFFFFFFFFFFF001LL )
  {
    v11 = &unk_2E03A;
    v12 = 758;
    goto LABEL_33;
  }
  v5 = debugfs_create_file("max_elem_dp_stats", 144, dent, 0, &gsi_max_elem_dp_stats_ops);
  gsi_debugfs_init_dfile = v5;
  if ( !v5 || v5 >= 0xFFFFFFFFFFFFF001LL )
  {
    v11 = &unk_2E03A;
    v12 = 765;
    goto LABEL_33;
  }
  v6 = debugfs_create_file("rst_stats", 144, dent, 0, &gsi_rst_stats_ops);
  gsi_debugfs_init_dfile = v6;
  if ( !v6 || v6 >= 0xFFFFFFFFFFFFF001LL )
  {
    v11 = &unk_2E03A;
    v12 = 772;
    goto LABEL_33;
  }
  v7 = debugfs_create_file("print_dp_stats", 144, dent, 0, &gsi_print_dp_stats_ops);
  gsi_debugfs_init_dfile = v7;
  if ( !v7 || v7 >= 0xFFFFFFFFFFFFF001LL )
  {
    v11 = &unk_2E03A;
    v12 = 779;
    goto LABEL_33;
  }
  v8 = debugfs_create_file("ipc_low", 144, dent, 0, &gsi_ipc_low_ops);
  gsi_debugfs_init_dfile = v8;
  if ( !v8 || v8 >= 0xFFFFFFFFFFFFF001LL )
  {
    v11 = &unk_2AC23;
    v12 = 786;
    goto LABEL_33;
  }
  v9 = debugfs_create_file("gsi_hw_profiling_stats", 288, dent, 0, &gsi_hw_profiling_ops);
  gsi_debugfs_init_dfile = v9;
  if ( !v9 || v9 >= 0xFFFFFFFFFFFFF001LL )
  {
    v11 = &unk_2DD26;
    v12 = 793;
    goto LABEL_33;
  }
  result = debugfs_create_file("gsi_fw_version", 288, dent, 0, &gsi_ver_ops);
  gsi_debugfs_init_dfile = result;
  if ( !result || result >= 0xFFFFFFFFFFFFF001LL )
  {
    v11 = &unk_2B798;
    v12 = 800;
LABEL_33:
    printk(v11, "gsi_debugfs_init", v12);
    return debugfs_remove(dent);
  }
  return result;
}
