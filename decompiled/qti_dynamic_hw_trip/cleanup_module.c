__int64 cleanup_module()
{
  return platform_driver_unregister(qcom_dynamic_hw_thermal_trip_driver);
}
