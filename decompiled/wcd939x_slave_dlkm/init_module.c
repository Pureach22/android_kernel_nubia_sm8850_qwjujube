__int64 init_module()
{
  return swr_driver_register(wcd939x_slave_driver);
}
