void sub_1688C()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &syna_dev_probe__alloc_tag;
  _kmalloc_large_noprof(204800, 3264);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x16588);
}
