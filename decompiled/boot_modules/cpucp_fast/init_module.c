__int64 init_module()
{
  return _platform_driver_register(qcom_cpucp_fast_driver, &_this_module);
}
