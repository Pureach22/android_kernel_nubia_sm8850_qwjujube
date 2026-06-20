__int64 init_module()
{
  return _platform_driver_register(&pm8916_pon_driver, &_this_module);
}
