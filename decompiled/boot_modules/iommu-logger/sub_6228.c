void sub_6228()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x28
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _kmalloc_cache_noprof;
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  v3 = _kmalloc_cache_noprof(v2, 3520, 72);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x6210);
  JUMPOUT(0x614C);
}
