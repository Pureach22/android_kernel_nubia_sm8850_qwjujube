void sub_10BA6C()
{
  __int64 v0; // x19
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_req_mgr_workq_create__alloc_tag_15;
  _kvmalloc_node_noprof(72LL * *(unsigned int *)(v0 + 304), 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x10B8A0);
}
