__int64 cam_req_mgr_init()
{
  return _platform_driver_register(cam_req_mgr_driver, &_this_module);
}
