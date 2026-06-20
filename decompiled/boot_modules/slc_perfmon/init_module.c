__int64 init_module()
{
  return _platform_driver_register(slc_perfmon_driver, &_this_module);
}
