void sub_DB6D8()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 (__fastcall *v2)(_QWORD); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = kfree;
  *(_QWORD *)(StatusReg + 80) = &ipa3_nat_ipv6ct_allocate_tmp_memory__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 16);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0xDB5A8);
  JUMPOUT(0xDB410);
}
