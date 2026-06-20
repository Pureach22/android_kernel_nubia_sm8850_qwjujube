void sub_54988()
{
  unsigned __int64 StatusReg; // x24
  __int64 v1; // x25
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _kmalloc_cache_noprof;
  *(_QWORD *)(StatusReg + 80) = &create_votable__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 136);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x5493C);
  JUMPOUT(0x548A0);
}
