__int64 __fastcall nl80211_send_rx_assoc(__int64 a1, __int64 a2, __int64 *a3)
{
  __int64 v3; // x9
  __int64 v4; // x10
  int v5; // w8
  __int64 v6; // x9
  __int64 result; // x0
  _QWORD v8[3]; // [xsp+0h] [xbp-40h] BYREF
  int v9; // [xsp+18h] [xbp-28h]
  int v10; // [xsp+1Ch] [xbp-24h]
  __int64 v11; // [xsp+20h] [xbp-20h]
  __int64 v12; // [xsp+28h] [xbp-18h]
  __int64 v13; // [xsp+30h] [xbp-10h]
  __int64 v14; // [xsp+38h] [xbp-8h]

  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *a3;
  v4 = a3[1];
  v13 = 0;
  v8[0] = 38;
  v8[1] = v3;
  v5 = *((_DWORD *)a3 + 8);
  v8[2] = v4;
  v9 = v5;
  v10 = 0;
  v6 = a3[3];
  v11 = a3[2];
  v12 = v6;
  result = nl80211_send_mlme_event(a1, a2, (unsigned int *)v8, 0xCC0u);
  _ReadStatusReg(SP_EL0);
  return result;
}
