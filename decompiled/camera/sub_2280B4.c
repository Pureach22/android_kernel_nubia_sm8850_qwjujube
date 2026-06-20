void sub_2280B4()
{
  __int64 v0; // x27
  __int64 v1; // x29
  unsigned __int64 StatusReg; // x21
  __int64 v3; // x27

  StatusReg = _ReadStatusReg(SP_EL0);
  *(_QWORD *)(v1 - 24) = v0;
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_icp_mgr_allocate_ctx__alloc_tag_62;
  _kvmalloc_node_noprof(6560, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x2278AC);
}
