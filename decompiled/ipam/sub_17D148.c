void sub_17D148()
{
  unsigned __int64 StatusReg; // x24
  __int64 v1; // x26
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &ipa_wigig_reg_intf__alloc_tag_25;
  v2 = _kmalloc_cache_noprof(raw_spin_unlock_irqrestore, 3520, 620);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x17D07C);
  JUMPOUT(0x17C9B0);
}
