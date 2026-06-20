__int64 cleanup_module()
{
  return platform_driver_unregister(zte_misc_device_driver);
}
