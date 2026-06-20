void sub_29A320()
{
  unsigned int v0; // w19
  unsigned __int64 StatusReg; // x27
  __int64 v2; // x28
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_camera_cci_i2c_read_seq__alloc_tag;
  v3 = _kvmalloc_node_noprof(v0, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x29A250);
  JUMPOUT(0x29A0EC);
}
