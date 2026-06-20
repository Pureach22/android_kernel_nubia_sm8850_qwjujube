void sub_1010F8()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_media_device_setup__alloc_tag;
  _kvmalloc_node_noprof(696, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x100B68);
}
