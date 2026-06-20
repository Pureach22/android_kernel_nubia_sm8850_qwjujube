void sub_65C5C()
{
  __int64 *v0; // x19
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x22
  __int64 (__fastcall *v3)(_QWORD); // x0
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  v3 = kfree;
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  v4 = _kmalloc_cache_noprof(v3, 3520, 16);
  *(_QWORD *)(StatusReg + 80) = v2;
  *v0 = v4;
  if ( !v4 )
    JUMPOUT(0x65C40);
  JUMPOUT(0x65BB4);
}
