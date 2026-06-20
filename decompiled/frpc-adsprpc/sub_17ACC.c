void sub_17ACC()
{
  __int64 v0; // x21
  unsigned __int64 StatusReg; // x24
  unsigned __int64 v2; // x28
  __int64 v3; // [xsp+20h] [xbp+20h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &fastrpc_context_alloc__alloc_tag_313;
  v2 = *(int *)(v0 + 16);
  if ( is_mul_ok(v2, 0x18u) )
    _kmalloc_noprof(24 * v2, 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x170DC);
}
