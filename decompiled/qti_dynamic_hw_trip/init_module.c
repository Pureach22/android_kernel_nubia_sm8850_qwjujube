__int64 init_module()
{
  return _platform_driver_register(qcom_dynamic_hw_thermal_trip_driver, &_this_module);
}
