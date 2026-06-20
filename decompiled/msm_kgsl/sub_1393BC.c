void sub_1393BC()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &kgsl_core_init__alloc_tag;
  _kmalloc_large_noprof(20480, 3520);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x139334);
}
