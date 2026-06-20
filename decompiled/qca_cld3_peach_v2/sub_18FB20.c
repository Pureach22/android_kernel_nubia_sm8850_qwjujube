void sub_18FB20()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_qdf_mem_valloc__alloc_tag;
  vzalloc_noprof();
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x18FB10);
}
