__int64 init_module()
{
  return _platform_driver_register(qcom_ramoops_drv, &_this_module);
}
