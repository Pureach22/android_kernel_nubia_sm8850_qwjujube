__int64 cleanup_module()
{
  return platform_driver_unregister(qmi_sens_device_driver);
}
