__int64 cleanup_module()
{
  return platform_driver_unregister(&remote_etm_driver);
}
