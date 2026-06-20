__int64 cleanup_module()
{
  cnss_genl_exit();
  platform_driver_unregister(cnss_platform_driver);
  return cnss_debug_deinit();
}
