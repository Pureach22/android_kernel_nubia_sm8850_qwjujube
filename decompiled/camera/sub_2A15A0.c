void sub_2A15A0()
{
  unsigned int v0; // w19
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_sensor_get_i2c_ptr__alloc_tag_244;
  _kvmalloc_node_noprof(16LL * v0, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x2A14C4);
}
