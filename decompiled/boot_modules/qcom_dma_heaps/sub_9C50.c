void sub_9C50()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = of_property_read_string;
  *(_QWORD *)(StatusReg + 80) = &dynamic_page_pool_create__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3264, 112);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x9C24);
  JUMPOUT(0x9BB4);
}
