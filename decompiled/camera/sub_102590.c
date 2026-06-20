void sub_102590()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x22

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_req_mgr_util_init__alloc_tag;
  _kvmalloc_node_noprof(10256, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x10244C);
}
