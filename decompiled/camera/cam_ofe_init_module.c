__int64 cam_ofe_init_module()
{
  return _platform_driver_register(cam_ofe_driver, &_this_module);
}
