void sub_31660()
{
  unsigned int v0; // w19
  unsigned __int64 StatusReg; // [xsp+0h] [xbp+0h]
  __int64 v2; // [xsp+10h] [xbp+10h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v2 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_ieee80211_start_rx_ba_session__alloc_tag_7;
  _kmalloc_noprof(8LL * v0, 3520);
  *(_QWORD *)(StatusReg + 80) = v2;
  JUMPOUT(0x3145C);
}
