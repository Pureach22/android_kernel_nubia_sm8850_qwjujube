__int64 __fastcall nl80211_join_ocb(__int64 a1, __int64 a2)
{
  __int64 v2; // x19
  __int64 v3; // x20
  __int64 result; // x0
  _QWORD v5[5]; // [xsp+8h] [xbp-28h] BYREF

  v5[4] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(a2 + 48);
  v3 = *(_QWORD *)(a2 + 56);
  memset(v5, 0, 32);
  result = nl80211_parse_chandef(v2, a2, 0, (__int64)v5);
  if ( !(_DWORD)result )
    result = cfg80211_join_ocb(v2, v3, v5);
  _ReadStatusReg(SP_EL0);
  return result;
}
