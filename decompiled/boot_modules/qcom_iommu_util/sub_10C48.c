void sub_10C48()
{
  int v0; // w24
  unsigned __int64 StatusReg; // x22
  __int64 v2; // x23
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_iommu_alloc_pages__alloc_tag_0;
  v3 = _alloc_pages_noprof(v0 | 0x100u, 0, 0, 0);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x10B90);
  JUMPOUT(0x10B04);
}
