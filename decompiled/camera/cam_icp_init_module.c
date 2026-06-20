__int64 cam_icp_init_module()
{
  return _platform_driver_register(cam_icp_driver, &_this_module);
}
