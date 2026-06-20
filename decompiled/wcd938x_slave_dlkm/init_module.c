__int64 init_module()
{
  return swr_driver_register(wcd938x_slave_driver);
}
