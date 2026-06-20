void __usercall sub_F883C(__int64 a1@<X8>)
{
  __int64 v1; // x20
  unsigned __int64 StatusReg; // x22
  __int64 v3; // x26
  __int64 v4; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_cam_req_mgr_create_subdevs__alloc_tag;
  v4 = _kvmalloc_node_noprof(320 * a1, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v3;
  *(_QWORD *)(v1 + 40) = v4;
  if ( !v4 )
    JUMPOUT(0xF874C);
  JUMPOUT(0xF85A8);
}
