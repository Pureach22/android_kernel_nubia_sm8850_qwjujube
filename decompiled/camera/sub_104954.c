void sub_104954()
{
  unsigned __int64 StatusReg; // x19
  __int64 v1; // x20

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_mem_mgr_init__alloc_tag;
  _kvmalloc_node_noprof(256, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x104430);
}
