__int64 cleanup_module()
{
  return platform_driver_unregister(pm8xxx_rtc_driver);
}
