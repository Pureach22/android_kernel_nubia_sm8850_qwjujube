__int64 __fastcall ieee80211_mgmt_tx_cookie(__int64 a1)
{
  __int64 v1; // x8
  bool v2; // cf
  __int64 v3; // x8

  v1 = *(_QWORD *)(a1 + 5336);
  v2 = __CFADD__(v1, 1);
  v3 = v1 + 1;
  *(_QWORD *)(a1 + 5336) = v3;
  if ( v2 )
  {
    __break(0x800u);
    v3 = *(_QWORD *)(a1 + 5336) + 1LL;
    *(_QWORD *)(a1 + 5336) = v3;
  }
  return v3;
}
