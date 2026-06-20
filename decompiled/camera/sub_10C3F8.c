void sub_10C3F8()
{
  unsigned __int64 StatusReg; // x23
  __int64 v1; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_req_mgr_debug_record_bind_latency__alloc_tag;
  _kvmalloc_node_noprof(32, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x10C2A4);
}
