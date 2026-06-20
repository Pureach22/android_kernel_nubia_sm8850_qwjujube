void sub_12B598()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x26
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_context_flush_req_to_hw__alloc_tag_57;
  v2 = _kvmalloc_node_noprof(8, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x12B478);
  JUMPOUT(0x12B1B4);
}
