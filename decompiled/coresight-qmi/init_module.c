__int64 init_module()
{
  return _platform_driver_register(coresight_qmi_driver, &_this_module);
}
