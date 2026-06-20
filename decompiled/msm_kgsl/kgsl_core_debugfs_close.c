__int64 kgsl_core_debugfs_close()
{
  return debugfs_remove(kgsl_debugfs_dir);
}
