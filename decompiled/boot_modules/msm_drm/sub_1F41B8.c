void sub_1F41B8()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x22
  __int64 v2; // x23
  __int64 v3; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &dsi_panel_parse_qsync_caps__alloc_tag;
  v3 = *(unsigned int *)(v0 + 1992);
  if ( (v3 & 0x80000000) == 0 )
    _kmalloc_noprof(4 * v3, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x1F34A8);
}
