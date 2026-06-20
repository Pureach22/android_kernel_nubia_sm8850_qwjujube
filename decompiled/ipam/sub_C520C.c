void sub_C520C()
{
  __int64 *v0; // x19
  __int64 v1; // x8
  unsigned __int64 StatusReg; // x25
  __int64 v3; // x26
  __int64 v4; // x0

  v1 = ipa3_ctx;
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_ipa_create_flt_entry__alloc_tag;
  v4 = kmem_cache_alloc_noprof(*(_QWORD *)(v1 + 29376), 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  *v0 = v4;
  if ( !v4 )
    JUMPOUT(0xC51D0);
  JUMPOUT(0xC50D4);
}
