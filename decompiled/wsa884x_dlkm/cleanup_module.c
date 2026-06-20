__int64 cleanup_module()
{
  return swr_driver_unregister(&wsa884x_swr_driver);
}
