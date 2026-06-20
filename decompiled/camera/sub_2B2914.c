void sub_2B2914()
{
  unsigned __int64 StatusReg; // x20
  __int64 v1; // x25
  __int64 v2; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &i2c_write__alloc_tag;
  v2 = _kvmalloc_node_noprof(150, 0, 3520, 0xFFFFFFFFLL);
  *(_QWORD *)(StatusReg + 80) = v1;
  if ( !v2 )
    JUMPOUT(0x2B2264);
  JUMPOUT(0x2B20EC);
}
