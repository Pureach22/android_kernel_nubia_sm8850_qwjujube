void sub_1A783C()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &sde_hw_rc_init__alloc_tag_29;
  _kvmalloc_node_noprof(21856, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  JUMPOUT(0x1A77DC);
}
