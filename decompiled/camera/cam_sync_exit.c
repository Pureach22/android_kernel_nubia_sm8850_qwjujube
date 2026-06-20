__int64 cam_sync_exit()
{
  return platform_driver_unregister(cam_sync_driver);
}
