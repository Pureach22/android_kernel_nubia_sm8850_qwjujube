__int64 cam_req_mgr_exit()
{
  return platform_driver_unregister(cam_req_mgr_driver);
}
