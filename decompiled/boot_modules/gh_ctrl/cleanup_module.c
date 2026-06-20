__int64 cleanup_module()
{
  gh_sysfs_unregister();
  return debugfs_remove(gh_dbgfs_dir);
}
