__int64 __fastcall ieee80211_tkip_encrypt_data(__int64 a1, __int64 a2, __int64 a3, __int64 a4, __int64 a5)
{
  __int64 result; // x0
  _QWORD v9[3]; // [xsp+8h] [xbp-18h] BYREF

  v9[2] = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v9[0] = 0;
  v9[1] = 0;
  ieee80211_get_tkip_p2k(a2 + 536, a3, (__int64)v9);
  result = ieee80211_wep_encrypt_data(a1, v9, 16, a4, a5);
  _ReadStatusReg(SP_EL0);
  return result;
}
