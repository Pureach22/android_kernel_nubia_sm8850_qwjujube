void __fastcall sub_82FAC(__int64 a1)
{
  __int64 v1; // x21
  unsigned __int64 StatusReg; // x24
  __int64 v3; // x25
  __int64 v4; // x22

  StatusReg = _ReadStatusReg(SP_EL0);
  v3 = *(_QWORD *)(StatusReg + 80);
  *(_QWORD *)(StatusReg + 80) = &_cfg80211_connect_result__alloc_tag;
  v4 = kmemdup_noprof(a1 + 2, v1, 2080);
  *(_QWORD *)(StatusReg + 80) = v3;
  _rcu_read_unlock(v4);
  if ( !v4 )
    JUMPOUT(0x82E20);
  JUMPOUT(0x82DF4);
}
