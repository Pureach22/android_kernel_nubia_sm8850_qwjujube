__int64 msm_smmu_driver_cleanup()
{
  return platform_driver_unregister(msm_smmu_driver);
}
