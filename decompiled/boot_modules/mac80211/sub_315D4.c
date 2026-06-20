void sub_315D4()
{
  unsigned __int64 StatusReg; // x9
  __int64 (__fastcall *v1)(_QWORD, _QWORD, _QWORD, _QWORD, _QWORD); // x0
  unsigned __int64 v2; // x19
  __int64 v3; // x0
  __int64 v4; // [xsp+0h] [xbp+0h]

  StatusReg = _ReadStatusReg(SP_EL0);
  v1 = init_timer_key;
  v4 = *(_QWORD *)(StatusReg + 80);
  v2 = StatusReg;
  *(_QWORD *)(StatusReg + 80) = &_ieee80211_start_rx_ba_session__alloc_tag;
  v3 = _kmalloc_cache_noprof(v1, 3520, 160);
  *(_QWORD *)(v2 + 80) = v4;
  if ( !v3 )
    JUMPOUT(0x31500);
  JUMPOUT(0x313F8);
}
