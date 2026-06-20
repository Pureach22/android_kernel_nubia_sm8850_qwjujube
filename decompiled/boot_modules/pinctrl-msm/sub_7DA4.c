void sub_7DA4()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  _kmalloc_large_noprof(30000, 3264);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x7D9C);
}
