__int64 cam_res_mgr_init()
{
  return _platform_driver_register(cam_res_mgr_driver, &_this_module);
}
