__int64 init_module()
{
  return _platform_driver_register(chg_ulog_driver, &_this_module);
}
