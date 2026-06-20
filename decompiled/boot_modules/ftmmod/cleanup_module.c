__int64 cleanup_module()
{
  platform_driver_unregister(&ftm_driver);
  return platform_device_unregister(&ftm_dev);
}
