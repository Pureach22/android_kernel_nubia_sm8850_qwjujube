void sub_6878()
{
  int v0; // w20
  unsigned __int64 StatusReg; // x24
  __int64 v2; // x25
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &mhi_sat_rpmsg_cb__alloc_tag;
  v3 = _kmalloc_noprof(v0 + 32LL, 2080);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x66E0);
  JUMPOUT(0x6730);
}
