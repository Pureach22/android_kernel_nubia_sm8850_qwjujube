void sub_231214()
{
  unsigned __int64 StatusReg; // x24
  __int64 v1; // x25
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_icp_mgr_send_ping__alloc_tag;
  v2 = _kvmalloc_node_noprof(24, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x231050);
  JUMPOUT(0x230F38);
}
