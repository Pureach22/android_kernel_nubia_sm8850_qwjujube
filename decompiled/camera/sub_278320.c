void sub_278320()
{
  unsigned __int64 StatusReg; // x23
  __int64 v1; // x24
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_csiphy_io_dump__alloc_tag;
  v2 = _kvmalloc_node_noprof(250, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x278280);
  JUMPOUT(0x2780EC);
}
