void sub_1E4BF0()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_ife_mgr_acquire_hw__alloc_tag_90;
  _kvmalloc_node_noprof(5256, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x1E2C58);
}
