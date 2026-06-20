__int64 cam_cci_exit_module()
{
  return platform_driver_unregister(cci_driver);
}
