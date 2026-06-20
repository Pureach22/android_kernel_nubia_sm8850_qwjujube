__int64 init_module()
{
  return _platform_driver_register(qpt_hw_device_driver, &_this_module);
}
