void sub_2A51D8()
{
  unsigned int v0; // w27
  unsigned __int64 StatusReg; // x19
  __int64 v2; // x23
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_get_dt_power_setting_data__alloc_tag_109;
  v3 = _kvmalloc_node_noprof(112LL * v0, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x2A4DB8);
  JUMPOUT(0x2A4C40);
}
