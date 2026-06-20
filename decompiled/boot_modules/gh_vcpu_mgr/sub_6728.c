void __fastcall sub_6728(__int64 a1, __int64 a2, __int64 a3, __int64 a4)
{
  unsigned __int64 StatusReg; // x19
  __int64 v5; // x20
  __int64 v6; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = *(_QWORD *)(StatusReg + 80);
  v6 = _tracepoint_android_rvh_gh_after_vcpu_run;
  *(_QWORD *)(StatusReg + 80) = &_start_alloc_tags;
  _kmalloc_cache_noprof(v6, 3520, &print_fmt_gh_hcall_vcpu_run[64], a4);
  *(_QWORD *)(StatusReg + 80) = v5;
  JUMPOUT(0x65AC);
}
