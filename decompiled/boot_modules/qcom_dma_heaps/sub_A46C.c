void sub_A46C()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = of_platform_device_create;
  *(_QWORD *)(StatusReg + 80) = &dynamic_page_pool_create_pools__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3264, 24);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0xA44C);
  JUMPOUT(0xA314);
}
