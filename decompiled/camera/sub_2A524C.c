void sub_2A524C()
{
  __int64 v0; // x23
  unsigned __int64 StatusReg; // x19
  __int64 v2; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_get_dt_power_setting_data__alloc_tag_127;
  _kvmalloc_node_noprof(112 * v0, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x2A50A4);
}
