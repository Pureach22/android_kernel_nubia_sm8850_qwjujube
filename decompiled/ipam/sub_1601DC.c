void sub_1601DC()
{
  __int64 v0; // x24
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x22
  __int64 (*v3)(_QWORD, _QWORD, const char *, ...); // x0
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  v3 = scnprintf;
  *(_QWORD *)(StatusReg + 80) = &ipa_gsb_driver_init__alloc_tag;
  v4 = _kmalloc_cache_noprof(v3, 3520, 408);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 2528) = v4;
  if ( !v4 )
    JUMPOUT(0x15FE0C);
  JUMPOUT(0x15F230);
}
