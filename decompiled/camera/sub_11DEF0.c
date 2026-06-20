void sub_11DEF0()
{
  __int64 v0; // x19
  __int64 v1; // x22
  unsigned __int64 StatusReg; // x21
  __int64 v3; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_debug_sysfs_node_store__alloc_tag;
  kmemdup_noprof(v1, v0 + 1, 3264);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x11D9C8);
}
