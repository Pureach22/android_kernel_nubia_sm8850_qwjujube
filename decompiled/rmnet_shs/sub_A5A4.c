void sub_A5A4()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  pcpu_alloc_noprof(8, 4, 0, 3264);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xA2B4);
}
