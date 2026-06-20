void sub_20D700()
{
  unsigned __int64 StatusReg; // x21
  __int64 v1; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_isp_dev_component_bind__alloc_tag_14;
  if ( is_mul_ok(dword_3A8B70, 0x228u) )
    _kvmalloc_node_noprof(552LL * dword_3A8B70, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x20D264);
}
