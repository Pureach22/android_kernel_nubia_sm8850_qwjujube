void sub_D0684()
{
  unsigned __int64 StatusReg; // x23
  __int64 v1; // x24
  __int64 (__fastcall *v2)(_QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = sg_next;
  *(_QWORD *)(StatusReg + 80) = &_ipa_get_flt_rt_stats__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 2);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xCFD30);
}
