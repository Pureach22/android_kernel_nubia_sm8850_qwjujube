void sub_135C64()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x25

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &iommu_get_guard_page__alloc_tag;
  _alloc_pages_noprof(69058, 0, 0, 0);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x135B58);
}
