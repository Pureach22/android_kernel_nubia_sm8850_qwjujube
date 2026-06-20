__int64 init_module()
{
  return _platform_driver_register(cpufreq_cdev_driver, &_this_module);
}
