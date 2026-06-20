void sub_1700C4()
{
  __int64 v0; // x20
  unsigned __int64 StatusReg; // x21
  __int64 v2; // x22
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_hw_cdm_component_bind__alloc_tag_169;
  v3 = _kvmalloc_node_noprof(4880, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  *(_QWORD *)(v0 + 3680) = v3;
  if ( !v3 )
    JUMPOUT(0x16F2F4);
  JUMPOUT(0x16F234);
}
