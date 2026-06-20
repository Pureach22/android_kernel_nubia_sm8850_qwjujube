void sub_7568()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &zcomp_init__alloc_tag;
  pcpu_alloc_noprof(16, 8, 0, 3264);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x74C8);
}
