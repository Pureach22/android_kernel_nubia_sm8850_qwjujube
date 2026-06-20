void sub_65C94()
{
  __int64 v0; // x21
  unsigned __int64 StatusReg; // x22
  __int64 v2; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa_smmu_store_sgt__alloc_tag_7;
  _kmalloc_noprof(32 * v0, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x65BC8);
}
