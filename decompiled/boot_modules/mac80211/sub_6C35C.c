void sub_6C35C()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 (__fastcall *v2)(_QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _usecs_to_jiffies;
  *(_QWORD *)(StatusReg + 80) = &rate_control_alloc__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3264, 16);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x6C2F8);
  JUMPOUT(0x6C1CC);
}
