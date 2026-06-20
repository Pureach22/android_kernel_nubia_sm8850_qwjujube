__int64 cleanup_module()
{
  return platform_driver_unregister(smmu_pmu_driver);
}
