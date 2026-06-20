__int64 init_module()
{
  return _platform_driver_register(&regulator_fixed_voltage_driver, &_this_module);
}
