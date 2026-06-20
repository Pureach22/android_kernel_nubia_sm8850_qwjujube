void sub_64A8()
{
  unsigned int v0; // w22
  unsigned __int64 StatusReg; // x23
  __int64 v2; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  if ( (v0 & 0x80000000) == 0 )
    _kmalloc_noprof(4LL * v0, 3264);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x6354);
}
