void __usercall sub_F140(const char *a1@<X2>, int a2@<W3>, int a3@<W4>, int a4@<W8>)
{
  unsigned __int64 StatusReg; // x19
  __int64 v5; // x24
  __int64 v6; // x26

  StatusReg = _ReadStatusReg(SP_EL0);
  v5 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &dispatcher_marshal_in__alloc_tag;
  if ( is_mul_ok(a4, 0x18u) )
    v6 = _kmalloc_noprof(24LL * a4, print_fmt_cbo_dispatch_wait, a1, a2, a3);
  else
    v6 = 0;
  *(_QWORD *)(StatusReg + 80) = v5;
  if ( !v6 )
    JUMPOUT(0xED8C);
  JUMPOUT(0xE9D0);
}
