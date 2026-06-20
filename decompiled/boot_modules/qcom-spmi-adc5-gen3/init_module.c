__int64 init_module()
{
  return _platform_driver_register(adc5_gen3_driver, &_this_module);
}
