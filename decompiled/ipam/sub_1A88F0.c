void sub_1A88F0()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  long double (*v2)(_QWORD, const char *, ...); // x0
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = ipc_log_string;
  *(_QWORD *)(StatusReg + 80) = &ipa_rm_perf_profile_notify_to_ipa__alloc_tag;
  v3 = _kmalloc_cache_noprof(v2, 2336, 40);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v3 )
    JUMPOUT(0x1A87D8);
  JUMPOUT(0x1A87A4);
}
