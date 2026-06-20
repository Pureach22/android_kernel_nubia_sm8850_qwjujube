void sub_2280EC()
{
  __int64 v0; // x20
  unsigned __int64 StatusReg; // x27
  __int64 v2; // x0
  __int64 v3; // [xsp+20h] [xbp+20h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_icp_mgr_acquire_hw__alloc_tag;
  v2 = _kvmalloc_node_noprof(8, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v3;
  *(_QWORD *)(v0 + 1720) = v2;
  if ( !v2 )
    JUMPOUT(0x227E28);
  JUMPOUT(0x227DB0);
}
