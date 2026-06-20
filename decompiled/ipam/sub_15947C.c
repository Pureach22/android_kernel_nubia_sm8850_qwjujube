void sub_15947C()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa3_rmnet_ll_init__alloc_tag;
  _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 744);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x15910C);
}
