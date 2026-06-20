void sub_1411C4()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa3_rmnet_ctl_init__alloc_tag;
  _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 728);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x140F8C);
}
