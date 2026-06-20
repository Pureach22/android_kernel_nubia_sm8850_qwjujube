__int64 cam_bps_init_module()
{
  return _platform_driver_register(cam_bps_driver, &_this_module);
}
