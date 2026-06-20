__int64 init_module()
{
  return _platform_driver_register(spcom_driver, &_this_module);
}
