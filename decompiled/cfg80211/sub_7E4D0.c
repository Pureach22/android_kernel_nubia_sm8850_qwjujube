void sub_7E4D0()
{
  __int64 v0; // x21
  unsigned __int64 StatusReg; // x24
  __int64 v2; // x26
  __int64 v3; // x0

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_cfg80211_bss_update__alloc_tag;
  v3 = _kmalloc_noprof(*(int *)(v0 + 1124) + 208LL, 2336);
  *(_QWORD *)(StatusReg + 80) = v2;
  if ( !v3 )
    JUMPOUT(0x7E228);
  JUMPOUT(0x7DD28);
}
