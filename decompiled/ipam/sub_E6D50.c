void sub_E6D50()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  __int64 (*v2)(_QWORD, _QWORD, const char *, ...); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = scnprintf;
  *(_QWORD *)(StatusReg + 80) = &ipa_opt_log_init__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 320);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xE69F0);
}
