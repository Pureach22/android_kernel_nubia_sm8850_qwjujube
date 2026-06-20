__int64 init_module()
{
  return _platform_driver_register(secure_etr_driver, &_this_module);
}
