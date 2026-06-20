void sub_143020()
{
  unsigned __int64 StatusReg; // x24
  __int64 v1; // x25

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &cam_generic_expand_monitor_table__alloc_tag;
  _kvmalloc_node_noprof(206848, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x142EF8);
}
