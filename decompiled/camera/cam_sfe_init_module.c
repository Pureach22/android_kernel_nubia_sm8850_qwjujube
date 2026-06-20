__int64 cam_sfe_init_module()
{
  return _platform_driver_register(cam_sfe_driver, &_this_module);
}
