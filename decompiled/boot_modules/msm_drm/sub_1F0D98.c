void sub_1F0D98()
{
  __int64 v0; // x27
  __int64 v1; // x29
  unsigned __int64 StatusReg; // x20
  __int64 v3; // x25
  __int64 v4; // x0
  __int64 v5; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &dsi_panel_parse_freq_step_table__alloc_tag_31;
  v4 = 32LL * *(unsigned int *)(v0 + 2472);
  *(_QWORD *)(v1 - 24) = v4;
  v5 = _kmalloc_noprof(v4, 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  if ( !v5 )
    JUMPOUT(0x1F0D44);
  JUMPOUT(0x1F0828);
}
