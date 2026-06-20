void sub_7C64()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 (__fastcall *v2)(_QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = raw_spin_lock;
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  v3 = _kmalloc_cache_noprof(v2, 3520, 360);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x7AEC);
  JUMPOUT(0x7A28);
}
