__int64 init_module()
{
  return _platform_driver_register(&qcom_secure_buffer_driver, &_this_module);
}
