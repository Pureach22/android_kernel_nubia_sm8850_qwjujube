__int64 qcom_dma_iommu_generic_driver_init()
{
  return _platform_driver_register(qcom_dma_iommu_driver, &_this_module);
}
