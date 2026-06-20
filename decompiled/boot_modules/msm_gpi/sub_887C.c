void sub_887C()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &gpi_dump_debug_reg__alloc_tag_113;
  v3 = _kmalloc_noprof(*(unsigned int *)(v0 + 1424), 2336);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 1416) = v3;
  if ( !v3 )
    JUMPOUT(0x81EC);
  JUMPOUT(0x803C);
}
