__int64 cam_icp_v2_init_module()
{
  return _platform_driver_register(cam_icp_v2_driver, &_this_module);
}
