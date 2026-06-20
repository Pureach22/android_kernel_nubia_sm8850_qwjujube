__int64 cam_ife_csid_exit_module()
{
  return platform_driver_unregister(cam_ife_csid_driver);
}
