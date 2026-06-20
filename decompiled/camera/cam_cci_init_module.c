__int64 cam_cci_init_module()
{
  return _platform_driver_register(cci_driver, &_this_module);
}
