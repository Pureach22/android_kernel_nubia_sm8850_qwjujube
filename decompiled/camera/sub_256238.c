void sub_256238()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_jpeg_setup_workqs__alloc_tag_164;
  _kvmalloc_node_noprof(720, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x255FD8);
}
