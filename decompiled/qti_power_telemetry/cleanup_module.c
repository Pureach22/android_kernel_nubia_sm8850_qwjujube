__int64 cleanup_module()
{
  return platform_driver_unregister(qpt_hw_device_driver);
}
