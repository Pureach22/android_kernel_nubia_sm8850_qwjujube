__int64 cleanup_module()
{
  return platform_driver_unregister(cpufreq_cdev_driver);
}
