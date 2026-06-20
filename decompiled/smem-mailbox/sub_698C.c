void sub_698C()
{
  unsigned __int16 *v0; // x20
  unsigned __int64 StatusReg; // x23
  __int64 v2; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  _kmalloc_noprof(*v0, 3264);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x6874);
}
