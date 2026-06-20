void sub_242018()
{
  __int64 v0; // x23
  unsigned __int64 StatusReg; // x26
  __int64 v2; // x27

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_icp_v2_component_bind__alloc_tag_16;
  _kvmalloc_node_noprof(4LL * *(unsigned int *)(v0 + 72), 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x241D30);
}
