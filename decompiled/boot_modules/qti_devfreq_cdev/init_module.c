__int64 init_module()
{
  return _platform_driver_register(devfreq_cdev_driver, &_this_module);
}
