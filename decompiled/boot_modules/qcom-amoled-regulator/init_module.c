__int64 init_module()
{
  return _platform_driver_register(&amoled_regulator_driver, &_this_module);
}
