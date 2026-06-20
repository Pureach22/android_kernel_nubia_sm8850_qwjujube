__int64 cam_cdm_intf_exit_module()
{
  return platform_driver_unregister(cam_cdm_intf_driver);
}
