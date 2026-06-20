void sub_133678()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &kgsl_iommu_bind__alloc_tag;
  _alloc_pages_noprof(69058, 0, 0, 0);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x1335A0);
}
