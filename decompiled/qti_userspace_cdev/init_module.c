__int64 init_module()
{
  return _platform_driver_register(&userspace_cdev_driver, &_this_module);
}
