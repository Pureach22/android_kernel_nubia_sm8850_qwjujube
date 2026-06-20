void sub_F73A0()
{
  unsigned __int64 StatusReg; // x25
  __int64 v1; // x26
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_cam_req_mgr_reserve_link__alloc_tag;
  v2 = _kvmalloc_node_noprof(3480, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0xF7288);
  JUMPOUT(0xF7184);
}
