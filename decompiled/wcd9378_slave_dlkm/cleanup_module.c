__int64 cleanup_module()
{
  return swr_driver_unregister(wcd9378_slave_driver);
}
