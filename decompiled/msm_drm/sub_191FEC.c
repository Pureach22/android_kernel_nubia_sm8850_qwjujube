void sub_191FEC()
{
  unsigned int v0; // w19
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &sde_hw_intr_init__alloc_tag_8;
  _kmalloc_noprof(16LL * v0, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x1919B8);
}
