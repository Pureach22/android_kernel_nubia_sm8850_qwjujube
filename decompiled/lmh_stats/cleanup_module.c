__int64 cleanup_module()
{
  return platform_driver_unregister(lmh_stats_driver);
}
