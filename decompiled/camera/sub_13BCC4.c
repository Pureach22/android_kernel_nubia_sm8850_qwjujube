void sub_13BCC4()
{
  unsigned __int64 StatusReg; // x26
  __int64 v1; // x27
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_smmu_iommu_fault_handler__alloc_tag;
  v2 = _kvmalloc_node_noprof(64, 0, 2336, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x13BB84);
  JUMPOUT(0x13BC00);
}
