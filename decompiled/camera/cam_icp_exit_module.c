__int64 cam_icp_exit_module()
{
  return platform_driver_unregister(cam_icp_driver);
}
