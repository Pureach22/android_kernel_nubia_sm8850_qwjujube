__int64 cam_res_mgr_exit()
{
  return platform_driver_unregister(cam_res_mgr_driver);
}
