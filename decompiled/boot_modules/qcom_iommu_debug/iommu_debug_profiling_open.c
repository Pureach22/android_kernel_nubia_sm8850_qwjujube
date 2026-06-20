__int64 __fastcall iommu_debug_profiling_open(__int64 a1, __int64 a2)
{
  return single_open(a2, iommu_debug_profiling_show, *(_QWORD *)(a1 + 696));
}
