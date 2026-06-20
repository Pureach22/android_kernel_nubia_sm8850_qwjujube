__int64 cam_ofe_exit_module()
{
  return platform_driver_unregister(cam_ofe_driver);
}
