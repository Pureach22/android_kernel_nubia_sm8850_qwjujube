void sub_246218()
{
  __int64 v0; // x29
  __int64 v1; // x8
  unsigned __int64 StatusReg; // x23
  __int64 v3; // x24

  v1 = *(unsigned int *)(v0 - 12);
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_icp_alloc_processor_devs__alloc_tag_9;
  _kvmalloc_node_noprof(8 * v1, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x246124);
}
