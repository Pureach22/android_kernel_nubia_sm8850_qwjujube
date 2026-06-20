__int64 init_module()
{
  return _platform_driver_register(&qcom_soc_wdt_driver, &_this_module);
}
