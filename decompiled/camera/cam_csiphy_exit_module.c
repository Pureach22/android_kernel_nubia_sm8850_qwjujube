__int64 cam_csiphy_exit_module()
{
  return platform_driver_unregister(csiphy_driver);
}
