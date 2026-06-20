void sub_22807C()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x24
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_icp_mgr_allocate_ctx__alloc_tag;
  v2 = _kvmalloc_node_noprof(30192, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x22781C);
  JUMPOUT(0x227794);
}
