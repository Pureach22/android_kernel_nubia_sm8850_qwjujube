void sub_F8D0()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 (__fastcall *v2)(_QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = xa_destroy;
  *(_QWORD *)(StatusReg + 80) = &mem_buf_lend_notify__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 8);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0xF8B8);
  JUMPOUT(0xF838);
}
