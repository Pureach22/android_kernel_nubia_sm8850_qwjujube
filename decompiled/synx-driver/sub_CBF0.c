void sub_CBF0()
{
  unsigned __int64 StatusReg; // x25
  __int64 v1; // x26
  __int64 v2; // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _stack_chk_fail;
  *(_QWORD *)(StatusReg + 80) = &synx_internal_async_wait__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 2336, 120);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0xCB14);
  JUMPOUT(0xC910);
}
