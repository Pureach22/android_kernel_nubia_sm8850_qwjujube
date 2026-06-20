__int64 init_module()
{
  return _platform_driver_register(platform_mpam_driver, &_this_module);
}
