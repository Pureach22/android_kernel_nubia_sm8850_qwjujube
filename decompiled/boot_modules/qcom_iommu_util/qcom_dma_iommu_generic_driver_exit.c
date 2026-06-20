__int64 qcom_dma_iommu_generic_driver_exit()
{
  return platform_driver_unregister(qcom_dma_iommu_driver);
}
