void sub_14072C()
{
  unsigned int v0; // w24
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x25

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &sde_dump_array__alloc_tag;
  vzalloc_noprof(v0);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x13FD00);
}
