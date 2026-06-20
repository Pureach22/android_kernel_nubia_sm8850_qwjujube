void sub_2A156C()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x23
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_sensor_get_i2c_ptr__alloc_tag;
  v2 = _kvmalloc_node_noprof(88, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x2A1534);
  JUMPOUT(0x2A1444);
}
