void sub_CB80()
{
  __int64 v0; // x24
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_fast_smmu_alloc_pages__alloc_tag;
  v3 = _kmalloc_noprof(v0, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0xC818);
  JUMPOUT(0xC744);
}
