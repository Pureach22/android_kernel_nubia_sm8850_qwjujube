void sub_75EFC()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  int (*v2)(timer_t); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = timer_delete;
  *(_QWORD *)(StatusReg + 80) = &regulatory_hint_country_ie__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 64);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x75EE4);
  JUMPOUT(0x75E60);
}
