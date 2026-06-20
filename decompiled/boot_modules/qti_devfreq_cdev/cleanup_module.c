__int64 cleanup_module()
{
  return platform_driver_unregister(devfreq_cdev_driver);
}
