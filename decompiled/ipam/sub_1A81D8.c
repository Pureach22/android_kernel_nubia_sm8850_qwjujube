void sub_1A81D8()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20
  __int64 (__fastcall *v2)(_QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = raw_spin_lock_irqsave;
  *(_QWORD *)(StatusReg + 80) = &ipa_rm_initialize__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 208);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x1A7FD8);
}
