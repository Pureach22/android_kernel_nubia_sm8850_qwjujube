__int64 cleanup_module()
{
  return platform_driver_unregister(thermal_pause_driver);
}
