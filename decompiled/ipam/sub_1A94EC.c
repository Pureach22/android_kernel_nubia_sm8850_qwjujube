void sub_1A94EC()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa_rm_peers_list_create__alloc_tag_6;
  _kmalloc_noprof(16LL * *(int *)(*(_QWORD *)v0 + 8LL), 2336);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x1A93B4);
}
