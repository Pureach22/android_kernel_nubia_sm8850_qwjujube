__int64 init_module()
{
  return _platform_driver_register(pm8941_pwrkey_driver, &_this_module);
}
