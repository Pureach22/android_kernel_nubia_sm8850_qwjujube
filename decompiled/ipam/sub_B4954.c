void sub_B4954()
{
  __int64 v0; // x22
  __int64 v1; // x8
  unsigned __int64 StatusReg; // x21
  __int64 v3; // x23

  v1 = *(_QWORD *)(v0 + 2056);
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa3_send_nop_desc__alloc_tag;
  kmem_cache_alloc_noprof(*(_QWORD *)(v1 + 29440), 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0xB480C);
}
