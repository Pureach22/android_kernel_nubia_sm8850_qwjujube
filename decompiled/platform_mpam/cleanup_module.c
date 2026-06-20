__int64 cleanup_module()
{
  return platform_driver_unregister(platform_mpam_driver);
}
