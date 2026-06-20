__int64 walt_register_debugfs()
{
  debugfs_walt = debugfs_create_dir("walt", 0);
  debugfs_create_u32("walt_features", 420, debugfs_walt, &debugfs_walt_features);
  debugfs_create_file("debug_counters", 292, debugfs_walt, 0, &counter_fops);
  return debugfs_create_file("smart_freq_status", 292, debugfs_walt, 0, &smart_freq_fops);
}
