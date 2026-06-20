__int64 init_module()
{
  return _platform_driver_register(&geni_i2c_driver, &_this_module);
}
