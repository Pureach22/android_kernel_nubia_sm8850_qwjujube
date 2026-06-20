__int64 init_module()
{
  return swr_driver_register(&wsa883x_swr_driver);
}
