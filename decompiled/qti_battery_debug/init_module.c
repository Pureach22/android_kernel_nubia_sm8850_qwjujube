__int64 init_module()
{
  return _platform_driver_register(battery_dbg_driver, &_this_module);
}
