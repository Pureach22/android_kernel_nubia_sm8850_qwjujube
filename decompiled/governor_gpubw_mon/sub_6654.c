void sub_6654()
{
  int v0; // w20
  unsigned __int64 StatusReg; // x23
  __int64 v2; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &gpubw_start__alloc_tag_6;
  _kmalloc_noprof(v0, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x6408);
}
