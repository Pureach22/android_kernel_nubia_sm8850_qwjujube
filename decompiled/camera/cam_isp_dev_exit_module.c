__int64 cam_isp_dev_exit_module()
{
  return platform_driver_unregister(isp_driver);
}
