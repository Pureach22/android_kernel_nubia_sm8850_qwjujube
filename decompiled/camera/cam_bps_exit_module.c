__int64 cam_bps_exit_module()
{
  return platform_driver_unregister(cam_bps_driver);
}
