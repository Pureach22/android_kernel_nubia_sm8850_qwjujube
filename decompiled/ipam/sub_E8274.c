void sub_E8274()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 (*v2)(_QWORD, _QWORD, const char *, ...); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = scnprintf;
  *(_QWORD *)(StatusReg + 80) = &ipa_pm_register__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 280);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xE7C1C);
}
