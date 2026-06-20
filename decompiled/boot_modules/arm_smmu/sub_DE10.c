void sub_DE10()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20
  __int64 v2; // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = iommu_logger_unregister;
  *(_QWORD *)(StatusReg + 80) = &arm_smmu_domain_alloc_paging__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 312);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0xDE00);
  JUMPOUT(0xDDD0);
}
