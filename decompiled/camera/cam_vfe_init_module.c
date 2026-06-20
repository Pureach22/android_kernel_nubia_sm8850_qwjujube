__int64 cam_vfe_init_module()
{
  return _platform_driver_register(cam_vfe_driver, &_this_module);
}
