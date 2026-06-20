__int64 cleanup_module()
{
  return swr_driver_unregister(&wsa883x_swr_driver);
}
