void sub_BD14()
{
  __int64 v0; // x22
  unsigned __int64 StatusReg; // x24
  __int64 v2; // x25
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_fast_smmu_create_mapping_sized__alloc_tag_8;
  v3 = vzalloc_noprof(*(unsigned int *)(v0 + 48));
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 56) = v3;
  if ( !v3 )
    JUMPOUT(0xBCEC);
  JUMPOUT(0xBAB4);
}
