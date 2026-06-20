void sub_7AA38()
{
  unsigned int v0; // w23
  __int64 v1; // x8
  unsigned __int64 StatusReg; // x23
  __int64 v3; // x24
  __int64 v4; // x0

  v1 = 96LL * v0;
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &regdom_intersect__alloc_tag;
  v4 = _kmalloc_noprof(v1 + 32, 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  if ( !v4 )
    JUMPOUT(0x7A9E8);
  JUMPOUT(0x7A720);
}
