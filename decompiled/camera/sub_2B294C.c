void sub_2B294C()
{
  unsigned __int64 StatusReg; // x25
  __int64 v1; // x26
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &i2c_write__alloc_tag_9;
  v2 = _kvmalloc_node_noprof(3000, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x2B21C0);
  JUMPOUT(0x2B211C);
}
