__int64 cleanup_module()
{
  return platform_driver_unregister(&qti_btl_driver);
}
