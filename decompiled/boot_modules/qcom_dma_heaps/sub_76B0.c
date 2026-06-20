void sub_76B0()
{
  int *v0; // x19
  unsigned __int64 StatusReg; // x22
  __int64 v2; // x23
  unsigned __int64 v3; // x8

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &parse_heap_dt__alloc_tag_4;
  v3 = *v0;
  if ( is_mul_ok(v3, 0x38u) )
    _kmalloc_noprof(56 * v3, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x72F4);
}
