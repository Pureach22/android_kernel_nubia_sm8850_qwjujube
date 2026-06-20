void sub_8948()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x22
  __int64 (__fastcall *v3)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD, _QWORD); // x0
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  v3 = printk;
  *(_QWORD *)(StatusReg + 80) = &gpi_dump_debug_reg__alloc_tag_105;
  v4 = _kmalloc_cache_noprof(v3, 2336, 176);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 1392) = v4;
  if ( !v4 )
    JUMPOUT(0x81EC);
  JUMPOUT(0x7E98);
}
