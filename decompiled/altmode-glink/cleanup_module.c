__int64 cleanup_module()
{
  return platform_driver_unregister(altmode_driver);
}
