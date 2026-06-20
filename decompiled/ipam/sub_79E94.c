void sub_79E94()
{
  __int64 v0; // x23
  unsigned __int64 StatusReg; // x24
  __int64 v2; // x25
  size_t v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa3_pre_init__alloc_tag_1193;
  v3 = strlen(*(const char **)(v0 + 4064));
  _kmalloc_noprof(v3 + 1, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x77444);
}
