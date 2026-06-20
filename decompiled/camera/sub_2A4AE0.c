void sub_2A4AE0()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x23
  __int64 v2; // x24
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_sensor_update_power_settings__alloc_tag;
  v3 = _kvmalloc_node_noprof(v0, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x2A40C8);
  JUMPOUT(0x2A4060);
}
