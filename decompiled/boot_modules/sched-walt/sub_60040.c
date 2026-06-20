void sub_60040()
{
  unsigned int v0; // w19
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x22

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &createRingBuffer__alloc_tag_6;
  _kmalloc_noprof(88LL * v0, 3264);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x5FF10);
}
