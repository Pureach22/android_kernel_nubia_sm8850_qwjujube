__int64 cleanup_module()
{
  platform_driver_unregister(arm_smmu_driver);
  return platform_driver_unregister(&qsmmuv500_tbu_driver);
}
