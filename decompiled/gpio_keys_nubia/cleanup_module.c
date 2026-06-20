__int64 cleanup_module()
{
  return platform_driver_unregister(&gpio_keys_device_driver);
}
