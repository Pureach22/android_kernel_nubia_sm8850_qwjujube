void __fastcall sub_4EBA8(_QWORD *a1, int a2)
{
  unsigned __int64 StatusReg; // x19
  __int64 v3; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cvp_kmem_cache_zalloc__alloc_tag;
  kmem_cache_alloc_noprof(*a1, a2 | 0x100u);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x4EB7C);
}
