void sub_24A20()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &synx_init__alloc_tag_197;
  vzalloc_noprof(23080);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x24698);
}
