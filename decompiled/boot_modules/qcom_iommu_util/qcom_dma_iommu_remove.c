__int64 __fastcall qcom_dma_iommu_remove(__int64 a1)
{
  return qcom_dma_atomic_pool_exit(a1 + 16);
}
