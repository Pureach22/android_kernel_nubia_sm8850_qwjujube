__int64 cleanup_module()
{
  return platform_driver_unregister(cache_allocation_driver);
}
