void sub_143DDC()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21
  __int64 (*v2)(_QWORD, _QWORD, const char *, ...); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = scnprintf;
  *(_QWORD *)(StatusReg + 80) = &rmnet_ipa_get_network_stats_and_update__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 3520, 336);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x143CBC);
  JUMPOUT(0x143C58);
}
