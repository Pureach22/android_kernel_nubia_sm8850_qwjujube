__int64 __fastcall nl80211_send_rx_auth(__int64 a1, __int64 a2, __int64 a3, __int64 a4, unsigned int a5)
{
  __int64 result; // x0
  _QWORD v6[3]; // [xsp+0h] [xbp-40h] BYREF
  int v7; // [xsp+18h] [xbp-28h]
  __int64 v8; // [xsp+1Ch] [xbp-24h]
  __int64 v9; // [xsp+24h] [xbp-1Ch]
  __int64 v10; // [xsp+2Ch] [xbp-14h]
  int v11; // [xsp+34h] [xbp-Ch]
  __int64 v12; // [xsp+38h] [xbp-8h]

  v12 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v6[0] = 37;
  v6[1] = a3;
  v6[2] = a4;
  v7 = -1;
  v8 = 0;
  v9 = 0;
  v10 = 0;
  v11 = 0;
  result = nl80211_send_mlme_event(a1, a2, v6, a5);
  _ReadStatusReg(SP_EL0);
  return result;
}
