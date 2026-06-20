void sub_8094()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 v2; // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _stack_chk_fail;
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  v3 = _kmalloc_cache_noprof(v2, 2336, 500);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x8080);
  JUMPOUT(0x8044);
}
