__int64 init_module()
{
  return _platform_driver_register(&pmic_mpp_driver, &_this_module);
}
