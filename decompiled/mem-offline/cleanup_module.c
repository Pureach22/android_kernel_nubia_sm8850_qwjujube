__int64 cleanup_module()
{
  return platform_driver_unregister(&mem_offline_driver);
}
