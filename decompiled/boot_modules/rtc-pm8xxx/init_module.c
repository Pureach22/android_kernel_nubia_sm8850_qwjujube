__int64 init_module()
{
  return _platform_driver_register(pm8xxx_rtc_driver, &_this_module);
}
