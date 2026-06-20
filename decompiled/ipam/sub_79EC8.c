void sub_79EC8()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x22
  __int64 (__fastcall *v2)(_QWORD, _QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _kmalloc_noprof;
  *(_QWORD *)(StatusReg + 80) = &ipa3_pre_init__alloc_tag_1207;
  _kmalloc_cache_noprof(v2, 3520, 184);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x779E4);
}
