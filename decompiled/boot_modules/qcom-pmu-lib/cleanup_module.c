__int64 cleanup_module()
{
  return platform_driver_unregister(&qcom_pmu_driver);
}
