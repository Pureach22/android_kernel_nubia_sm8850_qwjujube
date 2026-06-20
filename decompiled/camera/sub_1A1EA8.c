void sub_1A1EA8()
{
  __int64 v0; // x23
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x22
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_sfe_top_print_debug_reg_info__alloc_tag_95;
  v3 = _kvmalloc_node_noprof(4 * v0, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x1A1E68);
  JUMPOUT(0x1A1A3C);
}
