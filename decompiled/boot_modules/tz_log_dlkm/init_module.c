__int64 init_module()
{
  return _platform_driver_register(tz_log_driver, &_this_module);
}
