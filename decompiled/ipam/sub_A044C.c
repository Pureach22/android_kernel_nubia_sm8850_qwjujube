void sub_A044C()
{
  __int64 v0; // x20
  __int64 v1; // x0
  unsigned __int64 StatusReg; // x21
  __int64 v3; // x22

  v1 = *(_QWORD *)(v0 + 3368);
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa_do_host_ramdump__alloc_tag_62;
  _kmalloc_cache_noprof(v1, 3520, 40);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x9FF60);
}
