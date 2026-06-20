__int64 init_module()
{
  return _platform_driver_register(dcc_driver, &_this_module);
}
