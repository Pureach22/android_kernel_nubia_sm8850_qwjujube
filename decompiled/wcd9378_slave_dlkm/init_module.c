__int64 init_module()
{
  return swr_driver_register(wcd9378_slave_driver);
}
