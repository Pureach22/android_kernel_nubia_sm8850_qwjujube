void sub_17452C()
{
  unsigned __int64 StatusReg; // x23
  __int64 v1; // x24
  __int64 (__fastcall *v2)(_QWORD); // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  v2 = raw_spin_lock_irqsave;
  *(_QWORD *)(StatusReg + 80) = &ipa_wdi_init_per_inst__alloc_tag;
  _kmalloc_cache_noprof(v2, 3520, 200);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x17403C);
}
