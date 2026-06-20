__int64 mdss_iommu_present()
{
  return iommu_present(&platform_bus_type) & 1;
}
