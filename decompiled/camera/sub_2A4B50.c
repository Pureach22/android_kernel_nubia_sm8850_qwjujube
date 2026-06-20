void sub_2A4B50()
{
  __int64 v0; // x20
  unsigned __int64 StatusReg; // x19
  __int64 v2; // x22
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_sensor_update_power_settings__alloc_tag_92;
  v3 = _kvmalloc_node_noprof(1344, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 24) = v3;
  if ( !v3 )
    JUMPOUT(0x2A4264);
  JUMPOUT(0x2A41F4);
}
