__int64 cleanup_module()
{
  return debugfs_remove(thermal_debugfs_parent);
}
