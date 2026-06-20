__int64 cleanup_module()
{
  return platform_driver_unregister(swr_mstr_driver);
}
