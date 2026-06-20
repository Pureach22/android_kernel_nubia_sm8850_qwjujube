__int64 init_module()
{
  return _platform_driver_register(ddr_cdev_driver, &_this_module);
}
