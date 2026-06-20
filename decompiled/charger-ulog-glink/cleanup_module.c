__int64 cleanup_module()
{
  return platform_driver_unregister(chg_ulog_driver);
}
