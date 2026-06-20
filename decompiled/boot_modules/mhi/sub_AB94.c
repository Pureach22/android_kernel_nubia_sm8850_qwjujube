void sub_AB94()
{
  unsigned int v0; // w25
  __int64 *v1; // x26
  unsigned __int64 StatusReg; // x20
  __int64 v3; // x22
  __int64 v4; // x23

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &mhi_alloc_bhie_table__alloc_tag_12;
  if ( (v0 & 0x80000000) != 0 )
    v4 = 0;
  else
    v4 = _kmalloc_noprof(32LL * v0, 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  *v1 = v4;
  if ( !v4 )
    JUMPOUT(0xAB20);
  JUMPOUT(0xA9B8);
}
