__int64 __fastcall fast_smmu_mmap_attrs(__int64 a1, _QWORD *a2, unsigned __int64 a3, __int64 a4, __int64 a5)
{
  return qcom_iommu_dma_mmap(a1, a2, a3, a4, a5);
}
