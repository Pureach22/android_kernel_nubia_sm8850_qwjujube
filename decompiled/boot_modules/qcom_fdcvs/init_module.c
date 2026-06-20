__int64 init_module()
{
  return _platform_driver_register(fdcvs_driver, &_this_module);
}
