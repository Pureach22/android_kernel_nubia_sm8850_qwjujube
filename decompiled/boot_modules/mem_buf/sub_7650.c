void __fastcall sub_7650(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 StatusReg; // x23
  __int64 v5; // x24
  __int64 (__fastcall *v6)(_QWORD, _QWORD, _QWORD); // x0
  __int64 v7; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = *(_QWORD *)(StatusReg + 80);
  v6 = mem_buf_vmid_perm_list_to_gh_acl;
  *(_QWORD *)(StatusReg + 80) = &prepare_altmap__alloc_tag;
  v7 = _kmalloc_cache_noprof(v6, 3520, 22, a4);
  *(_QWORD *)(StatusReg + 80) = v5;
  if ( !v7 )
    JUMPOUT(0x75EC);
  JUMPOUT(0x74C4);
}
