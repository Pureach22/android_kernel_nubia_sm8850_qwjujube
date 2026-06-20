__int64 __fastcall kgsl_iommu_clear_fsr(__int64 a1)
{
  __int64 result; // x0

  result = ((__int64 (*)(void))kgsl_iommu_context_clear_fsr)();
  if ( *(_QWORD *)(a1 + 696) )
    return kgsl_iommu_context_clear_fsr(a1, a1 + 624);
  return result;
}
