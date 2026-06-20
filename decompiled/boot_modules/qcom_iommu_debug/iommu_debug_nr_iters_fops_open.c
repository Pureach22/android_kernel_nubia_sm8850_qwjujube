__int64 __fastcall iommu_debug_nr_iters_fops_open(
        __int64 a1,
        __int64 a2,
        __int64 a3,
        __int64 a4,
        __int64 a5,
        __int64 a6)
{
  return simple_attr_open(a1, a2, iommu_debug_nr_iters_get, iommu_debug_nr_iters_set, "%llu\n", a6);
}
