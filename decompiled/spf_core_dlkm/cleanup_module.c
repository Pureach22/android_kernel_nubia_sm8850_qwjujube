__int64 cleanup_module()
{
  return platform_driver_unregister(spf_core_driver);
}
