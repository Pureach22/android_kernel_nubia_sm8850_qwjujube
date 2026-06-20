__int64 cam_sfe_exit_module()
{
  return platform_driver_unregister(cam_sfe_driver);
}
