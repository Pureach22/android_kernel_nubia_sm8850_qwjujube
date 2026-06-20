__int64 init_module()
{
  return _platform_driver_register(glink_adc_driver, &_this_module);
}
