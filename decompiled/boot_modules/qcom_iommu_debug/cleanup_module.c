__int64 cleanup_module()
{
  platform_driver_unregister(&iommu_debug_usecase_driver);
  return platform_driver_unregister(iommu_debug_driver);
}
