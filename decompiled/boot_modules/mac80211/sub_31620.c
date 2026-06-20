void sub_31620()
{
  unsigned int v0; // w19
  __int64 v1; // x0
  unsigned __int64 StatusReg; // x19
  __int64 v3; // [xsp+0h] [xbp+0h]

  v1 = 24LL * v0;
  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_ieee80211_start_rx_ba_session__alloc_tag_5;
  _kmalloc_noprof(v1, 3520);
  *(_QWORD *)(StatusReg + 80) = v3;
  JUMPOUT(0x31448);
}
