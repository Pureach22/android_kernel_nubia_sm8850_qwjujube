void sub_1A8B60()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  __int64 (__fastcall *v2)(_QWORD, _QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = _kmalloc_noprof;
  *(_QWORD *)(StatusReg + 80) = &ipa_rm_dep_graph_create__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 176);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x1A8B3C);
}
