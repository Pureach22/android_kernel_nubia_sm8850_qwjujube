__int64 init_module()
{
  return _platform_driver_register(mpam_msc_driver, &_this_module);
}
