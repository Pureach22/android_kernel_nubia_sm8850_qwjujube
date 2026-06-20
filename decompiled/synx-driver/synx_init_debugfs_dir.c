__int64 __fastcall synx_init_debugfs_dir(__int64 a1)
{
  __int64 dir; // x0
  __int64 v3; // x4
  __int64 v4; // x5
  __int64 v5; // x19
  void *v6; // x0
  __int64 v7; // x3

  dir = debugfs_create_dir("synx_debug", 0);
  if ( !dir )
  {
    if ( (synx_debug & 1) != 0 )
    {
      v6 = &unk_2B545;
      v7 = 174;
      goto LABEL_13;
    }
    return 0;
  }
  v5 = dir;
  debugfs_create_u32("debug_level", 420, dir, &synx_debug);
  debugfs_create_ulong("column_level", 420, v5, &synx_columns);
  if ( !debugfs_create_file("synx_table", 420, v5, a1, &synx_table_fops) )
  {
    if ( (synx_debug & 1) != 0 )
    {
      v6 = &unk_27AE3;
      v7 = 182;
      goto LABEL_13;
    }
    return 0;
  }
  if ( !debugfs_create_file("help", 292, v5, a1, &synx_help_fops) )
  {
    if ( (synx_debug & 1) != 0 )
    {
      v6 = &unk_287A1;
      v7 = 188;
      goto LABEL_13;
    }
    return 0;
  }
  if ( !debugfs_create_file("synx_test_ioctl", 420, v5, a1, &synx_test_fops) )
  {
    if ( (synx_debug & 1) != 0 )
    {
      v6 = &unk_287E3;
      v7 = 194;
LABEL_13:
      printk(v6, &unk_29207, "synx_init_debugfs_dir", v7, v3, v4);
      return 0;
    }
    return 0;
  }
  return v5;
}
