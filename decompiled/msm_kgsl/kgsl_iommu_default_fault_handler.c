__int64 __fastcall kgsl_iommu_default_fault_handler(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  return kgsl_iommu_fault_handler(a5, a5 + 64);
}
