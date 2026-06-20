void sub_21B9FC()
{
  unsigned __int64 StatusReg; // x24
  __int64 v1; // x28

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_cam_isp_ctx_acquire_hw_v2__alloc_tag_494;
  _kvmalloc_node_noprof(5256, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x21B104);
}
