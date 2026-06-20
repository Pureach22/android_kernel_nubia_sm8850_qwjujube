__int64 init_module()
{
  return _platform_driver_register(swr_mstr_driver, &_this_module);
}
