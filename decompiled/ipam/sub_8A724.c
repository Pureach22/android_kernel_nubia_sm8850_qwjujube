void sub_8A724()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x22
  __int64 (*v2)(_QWORD, _QWORD, const char *, ...); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = scnprintf;
  *(_QWORD *)(StatusReg + 80) = &ipa3_setup_exception_path__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 312);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x8A4D8);
  JUMPOUT(0x89CFC);
}
