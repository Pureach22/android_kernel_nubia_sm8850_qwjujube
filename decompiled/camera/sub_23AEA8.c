void sub_23AEA8()
{
  unsigned __int64 StatusReg; // x23
  __int64 v1; // x24
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_icp_mgr_process_cfg_io_cmd__alloc_tag;
  v2 = _kvmalloc_node_noprof(24, 0, 2336, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x23ADD4);
  JUMPOUT(0x23AD40);
}
