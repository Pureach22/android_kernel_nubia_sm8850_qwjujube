__int64 init_module()
{
  return _platform_driver_register(pmic_pon_log_driver, &_this_module);
}
