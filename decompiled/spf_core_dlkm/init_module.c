__int64 init_module()
{
  return _platform_driver_register(spf_core_driver, &_this_module);
}
