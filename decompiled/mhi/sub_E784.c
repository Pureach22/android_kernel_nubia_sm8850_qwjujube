void sub_E784()
{
  unsigned __int64 v0; // x23
  unsigned __int64 StatusReg; // x24
  __int64 v2; // x25

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &parse_ev_cfg__alloc_tag;
  if ( is_mul_ok(v0, 0x108u) )
    _kmalloc_noprof(264 * v0, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0xE0A4);
}
