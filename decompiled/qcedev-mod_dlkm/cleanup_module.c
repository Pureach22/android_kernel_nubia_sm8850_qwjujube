__int64 cleanup_module()
{
  debugfs_remove(debug_dent);
  return platform_driver_unregister(qcedev_plat_driver);
}
