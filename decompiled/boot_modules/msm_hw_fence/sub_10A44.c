void sub_10A44()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x23
  __int64 v2; // x24
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &init_hw_fences_table__alloc_tag;
  v3 = _kmalloc_noprof(8LL * *(unsigned int *)(v0 + 80), 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 72) = v3;
  if ( !v3 )
    JUMPOUT(0x108A4);
  JUMPOUT(0x10684);
}
