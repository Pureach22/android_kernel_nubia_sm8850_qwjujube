void sub_B14C()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23
  __int64 (__fastcall *v2)(_QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = ktime_get;
  *(_QWORD *)(StatusReg + 80) = &ifas_enable_store__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 128);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0xB004);
}
