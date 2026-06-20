void __fastcall sub_191FBC(__int64 a1, unsigned int a2)
{
  unsigned __int64 StatusReg; // x20
  __int64 v3; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &sde_hw_intr_init__alloc_tag_6;
  _kmalloc_noprof(20LL * a2, 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x191994);
}
