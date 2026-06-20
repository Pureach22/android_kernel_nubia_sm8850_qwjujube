__int64 cleanup_module()
{
  return platform_driver_unregister(&userspace_cdev_driver);
}
