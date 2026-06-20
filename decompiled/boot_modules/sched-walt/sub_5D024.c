void sub_5D024()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22
  __int64 (__fastcall *v2)(_QWORD, _QWORD, _QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = android_rvh_probe_register;
  *(_QWORD *)(StatusReg + 80) = &q_affinity_work__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 56);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x5CF28);
}
