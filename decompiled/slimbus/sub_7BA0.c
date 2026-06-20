void sub_7BA0()
{
  int v0; // w21
  unsigned __int64 StatusReg; // x23
  __int64 v2; // x24

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &slim_stream_prepare__alloc_tag;
  if ( is_mul_ok(v0, 0x24u) )
    _kmalloc_noprof(36LL * v0, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x78C8);
}
