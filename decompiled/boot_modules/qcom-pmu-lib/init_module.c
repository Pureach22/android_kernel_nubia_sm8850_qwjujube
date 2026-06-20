__int64 init_module()
{
  return _platform_driver_register(&qcom_pmu_driver, &_this_module);
}
