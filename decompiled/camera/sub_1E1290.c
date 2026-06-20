void sub_1E1290()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_ife_hw_mgr_init__alloc_tag_59;
  _kvmalloc_node_noprof(4LL * *(unsigned int *)(v0 + 1468), 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x1E0FA4);
}
