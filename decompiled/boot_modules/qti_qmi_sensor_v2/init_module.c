__int64 init_module()
{
  return _platform_driver_register(qmi_sens_device_driver, &_this_module);
}
