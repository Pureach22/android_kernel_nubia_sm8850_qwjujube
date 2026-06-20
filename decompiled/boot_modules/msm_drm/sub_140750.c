void sub_140750()
{
  int v0; // w27
  unsigned __int64 StatusReg; // x19
  __int64 v2; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &sde_dbg_dump_dsi_dbg_bus__alloc_tag;
  vzalloc_noprof(v0);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x1405D8);
}
