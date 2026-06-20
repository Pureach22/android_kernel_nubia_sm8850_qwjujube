void sub_7ACC()
{
  unsigned int v0; // w19
  unsigned __int64 StatusReg; // x26
  __int64 v2; // x27
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  v3 = _kmalloc_noprof(8LL * v0 + 224, 10496);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x7A7C);
  JUMPOUT(0x78E0);
}
