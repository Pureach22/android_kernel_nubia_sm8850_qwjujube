void sub_1BD0A4()
{
  unsigned __int64 StatusReg; // x28
  __int64 v1; // [xsp+8h] [xbp+8h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_vfe_bus_ver3_init_wm_resource__alloc_tag_42;
  _kvmalloc_node_noprof(240, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x1BCE74);
}
