void sub_64D4()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x25
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &tz_init_ca__alloc_tag;
  v2 = _kmalloc_cache_noprof(_stack_chk_fail, 3520, 4096);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x640C);
  JUMPOUT(0x6384);
}
