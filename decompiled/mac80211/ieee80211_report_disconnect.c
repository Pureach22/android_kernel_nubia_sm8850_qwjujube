__int64 __fastcall ieee80211_report_disconnect(__int64 a1, __int64 a2, __int64 a3, char a4, __int16 a5, char a6)
{
  __int64 v7; // x0
  int v8; // w8
  __int64 result; // x0
  __int64 v10; // [xsp+0h] [xbp-20h] BYREF
  int v11; // [xsp+8h] [xbp-18h]
  int v12; // [xsp+Ch] [xbp-14h]
  __int16 v13; // [xsp+10h] [xbp-10h]
  __int16 v14; // [xsp+12h] [xbp-Eh]
  int v15; // [xsp+14h] [xbp-Ch]
  __int64 v16; // [xsp+18h] [xbp-8h]

  v16 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v7 = *(_QWORD *)(a1 + 1608);
  if ( (a4 & 1) != 0 )
    v8 = 3;
  else
    v8 = 2;
  v10 = 1;
  v11 = v8;
  v12 = 0;
  v13 = a5;
  v14 = 0;
  v15 = 0;
  if ( (a4 & 1) != 0 )
    cfg80211_tx_mlme_mgmt(v7, a2, a3, a6 & 1);
  else
    cfg80211_rx_mlme_mgmt(v7, a2, a3);
  result = drv_event_callback(*(_QWORD *)(a1 + 1616), a1, &v10);
  _ReadStatusReg(SP_EL0);
  return result;
}
