__int64 arm_smmu_domain_alloc_paging()
{
  __int64 result; // x0
  __int64 v1; // x19

  result = _kmalloc_cache_noprof(iommu_logger_unregister, 3520, 312);
  if ( result )
  {
    v1 = result;
    _mutex_init(result + 80, "&smmu_domain->init_mutex", &arm_smmu_domain_alloc_paging___key);
    *(_QWORD *)(v1 + 128) = 0;
    *(_DWORD *)(v1 + 160) = 0;
    *(_DWORD *)(v1 + 140) = -1;
    return v1 + 184;
  }
  return result;
}
