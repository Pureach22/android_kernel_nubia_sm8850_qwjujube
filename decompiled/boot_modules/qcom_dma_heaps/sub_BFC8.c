void sub_BFC8()
{
  __int64 v0; // x22
  unsigned __int64 StatusReg; // x24
  __int64 v2; // x25

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &hyp_unassign_sg_from_flags__alloc_tag;
  if ( ((v0 << 32) & 0x8000000000000000LL) == 0 )
    _kmalloc_noprof((4 * v0) & 0x3FFFFFFFFLL, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0xBE98);
}
