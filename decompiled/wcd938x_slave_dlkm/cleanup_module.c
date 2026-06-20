__int64 cleanup_module()
{
  return swr_driver_unregister(wcd938x_slave_driver);
}
