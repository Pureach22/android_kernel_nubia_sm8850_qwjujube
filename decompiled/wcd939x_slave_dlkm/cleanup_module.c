__int64 cleanup_module()
{
  return swr_driver_unregister(wcd939x_slave_driver);
}
