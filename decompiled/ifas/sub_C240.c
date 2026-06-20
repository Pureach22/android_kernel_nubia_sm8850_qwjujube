void sub_C240()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 (__fastcall *v2)(_QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = ktime_get;
  *(_QWORD *)(StatusReg + 80) = &gpu_max_pwrlevel_limit_store__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 128);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0xC1A8);
  JUMPOUT(0xC0B8);
}
