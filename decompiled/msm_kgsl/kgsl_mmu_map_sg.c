__int64 __fastcall kgsl_mmu_map_sg(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  return iommu_map_sg(a1, a2, a3, a4, a5, 3264);
}
