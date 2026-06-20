void sub_DEBB4()
{
  unsigned int v0; // w22
  unsigned __int64 StatusReg; // x20
  __int64 v2; // x21

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &adreno_rpmh_build_bw_votes__alloc_tag_4;
  if ( (v0 & 0x80000000) == 0 )
    _kmalloc_noprof(8LL * v0, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0xDE7D4);
}
