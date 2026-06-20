void sub_1426F8()
{
  int v0; // w25
  unsigned __int64 StatusReg; // x26
  __int64 v2; // x27

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &sde_dbg_dump_sde_dbg_bus__alloc_tag;
  vzalloc_noprof(v0);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x142534);
}
