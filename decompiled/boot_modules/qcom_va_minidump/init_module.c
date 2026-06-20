__int64 init_module()
{
  return _platform_driver_register(qcom_va_md_driver, &_this_module);
}
