__int64 cleanup_module()
{
  return platform_driver_unregister(tz_log_driver);
}
