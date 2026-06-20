__int64 cam_ipe_exit_module()
{
  return platform_driver_unregister(cam_ipe_driver);
}
