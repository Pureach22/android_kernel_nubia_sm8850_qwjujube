__int64 init_module()
{
  return _platform_driver_register(qcom_ipcc_driver, &_this_module);
}
