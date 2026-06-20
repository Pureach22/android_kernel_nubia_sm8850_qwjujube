void sub_2561D4()
{
  __int64 v0; // x29
  __int64 v1; // x8
  unsigned __int64 StatusReg; // x22
  __int64 v3; // x23

  v1 = *(unsigned int *)(v0 - 16);
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_jpeg_init_devices__alloc_tag_153;
  _kvmalloc_node_noprof(8 * v1, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x255A78);
}
