void sub_1FD88()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &fastrpc_create_persistent_headers__alloc_tag;
  v2 = _kmalloc_cache_noprof(of_find_property, 3520, 1792);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x1FCF4);
  JUMPOUT(0x1FBCC);
}
