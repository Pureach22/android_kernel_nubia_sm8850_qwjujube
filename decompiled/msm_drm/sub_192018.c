void __fastcall sub_192018(__int64 a1)
{
  unsigned __int64 StatusReg; // x19
  __int64 v2; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &sde_hw_intr_init__alloc_tag_10;
  _kmalloc_noprof(4LL * *(unsigned int *)(a1 + 312), 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x191ED0);
}
