void __usercall sub_1E11F4(__int64 a1@<X8>)
{
  unsigned __int64 StatusReg; // x19
  __int64 v2; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_ife_hw_mgr_init__alloc_tag_47;
  _kvmalloc_node_noprof(4LL * *(unsigned int *)(a1 + 1456), 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x1E0E90);
}
