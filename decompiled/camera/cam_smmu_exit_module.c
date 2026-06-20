__int64 cam_smmu_exit_module()
{
  return platform_driver_unregister(cam_smmu_driver);
}
