__int64 cam_hw_cdm_exit_module()
{
  return platform_driver_unregister(cam_hw_cdm_driver);
}
