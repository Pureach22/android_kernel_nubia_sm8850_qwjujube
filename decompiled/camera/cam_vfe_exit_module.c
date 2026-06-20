__int64 cam_vfe_exit_module()
{
  return platform_driver_unregister(cam_vfe_driver);
}
