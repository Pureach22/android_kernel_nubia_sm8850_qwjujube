void sub_79EF8()
{
  __int64 v0; // x21
  __int64 v1; // x9
  unsigned __int64 StatusReg; // x23
  __int64 v3; // x24

  v1 = *(_QWORD *)(v0 + 2056);
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa3_pre_init__alloc_tag_1203;
  _kmalloc_noprof(16LL * *(unsigned int *)(v1 + 43752), 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x777F0);
}
