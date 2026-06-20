void sub_101E24()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &sde_core_irq_preinstall__alloc_tag_15;
  _kmalloc_noprof(4LL * *(unsigned int *)(v0 + 1904), 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x101CA0);
}
