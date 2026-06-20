__int64 cam_ipe_init_module()
{
  return _platform_driver_register(cam_ipe_driver, &_this_module);
}
