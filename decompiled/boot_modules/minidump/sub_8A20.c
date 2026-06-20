void sub_8A20()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x22
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &md_register_trace_buf__alloc_tag;
  v2 = _kmalloc_large_noprof(0x200000, 3520);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x86EC);
  JUMPOUT(0x863C);
}
