__int64 __fastcall wlan_hdd_del_station(__int64 a1, __int64 a2)
{
  __int64 v2; // x1
  __int64 result; // x0
  __int64 v4; // [xsp+8h] [xbp-18h] BYREF
  __int64 v5; // [xsp+10h] [xbp-10h]
  __int64 v6; // [xsp+18h] [xbp-8h]

  v6 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v4 = a2;
  v5 = 0;
  v2 = *(_QWORD *)(a1 + 32);
  LOBYTE(v5) = 12;
  WORD1(v5) = 3;
  result = wlan_hdd_cfg80211_del_station(a1, v2, &v4);
  _ReadStatusReg(SP_EL0);
  return result;
}
