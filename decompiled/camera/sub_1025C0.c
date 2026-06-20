void sub_1025C0()
{
  unsigned __int64 StatusReg; // x22
  __int64 v1; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_req_mgr_util_init__alloc_tag_4;
  _kvmalloc_node_noprof(32, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x1024A0);
}
