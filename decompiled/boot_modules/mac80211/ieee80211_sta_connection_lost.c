__int64 __fastcall ieee80211_sta_connection_lost(__int64 a1, unsigned __int8 a2, unsigned int a3)
{
  __int16 v3; // w20
  __int64 v5; // x0
  __int64 result; // x0
  _QWORD v7[2]; // [xsp+0h] [xbp-40h] BYREF
  __int16 v8; // [xsp+10h] [xbp-30h]
  __int16 v9; // [xsp+12h] [xbp-2Eh]
  int v10; // [xsp+14h] [xbp-2Ch]
  _QWORD v11[3]; // [xsp+18h] [xbp-28h] BYREF
  __int16 v12; // [xsp+30h] [xbp-10h]
  __int64 v13; // [xsp+38h] [xbp-8h]

  v3 = a2;
  v13 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v12 = 0;
  memset(v11, 0, sizeof(v11));
  ieee80211_set_disassoc(a1, 192, a2, a3, v11);
  v5 = *(_QWORD *)(a1 + 1608);
  v7[0] = 1;
  v7[1] = 3;
  v8 = v3;
  v9 = 0;
  v10 = 0;
  cfg80211_tx_mlme_mgmt(v5, v11, 26, 0);
  result = drv_event_callback(*(_QWORD *)(a1 + 1616), a1, v7);
  _ReadStatusReg(SP_EL0);
  return result;
}
