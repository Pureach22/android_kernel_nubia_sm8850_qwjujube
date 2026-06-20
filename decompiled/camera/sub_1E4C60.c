void __usercall sub_1E4C60(unsigned int a1@<W8>)
{
  unsigned __int64 StatusReg; // x19
  __int64 v2; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_ife_mgr_acquire_hw__alloc_tag_103;
  _kvmalloc_node_noprof((unsigned __int64)a1 << 7, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x1E3D64);
}
