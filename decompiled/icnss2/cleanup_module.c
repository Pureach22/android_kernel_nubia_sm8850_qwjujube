__int64 cleanup_module()
{
  platform_driver_unregister(icnss_driver);
  platform_driver_unregister(icnss_direct_link_driver);
  return icnss_debug_deinit();
}
