__int64 init_module()
{
  return _platform_driver_register(&gpio_keys_device_driver, &_this_module);
}
