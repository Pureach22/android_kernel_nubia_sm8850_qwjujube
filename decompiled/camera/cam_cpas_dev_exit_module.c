__int64 cam_cpas_dev_exit_module()
{
  return platform_driver_unregister(cam_cpas_driver);
}
