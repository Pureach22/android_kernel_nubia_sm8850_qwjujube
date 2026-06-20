__int64 init_module()
{
  return _platform_driver_register(lmh_stats_driver, &_this_module);
}
