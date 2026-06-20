__int64 __fastcall ieee80211_mgd_quiesce(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 v3; // x1
  __int64 v4; // x8
  int v5; // w8
  _QWORD v6[3]; // [xsp+0h] [xbp-50h] BYREF
  __int16 v7; // [xsp+18h] [xbp-38h]
  int v8; // [xsp+1Ah] [xbp-36h]
  __int16 v9; // [xsp+1Eh] [xbp-32h]
  int v10; // [xsp+20h] [xbp-30h] BYREF
  __int16 v11; // [xsp+24h] [xbp-2Ch]
  _QWORD v12[3]; // [xsp+28h] [xbp-28h] BYREF
  __int16 v13; // [xsp+40h] [xbp-10h]
  __int64 v14; // [xsp+48h] [xbp-8h]

  v1 = result;
  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD *)(result + 2480);
  v13 = 0;
  memset(v12, 0, sizeof(v12));
  if ( v2 )
  {
    v3 = v2 + 48;
  }
  else
  {
    v4 = *(_QWORD *)(result + 2488);
    if ( !v4 )
      goto LABEL_10;
    v3 = v4 + 960;
  }
  ieee80211_send_deauth_disassoc(result, v3, v3, 192, 3, 0, v12);
  if ( *(_QWORD *)(v1 + 2488) )
    ieee80211_destroy_assoc_data(v1, 3);
  if ( *(_QWORD *)(v1 + 2480) )
    ieee80211_destroy_auth_data(v1, 0);
  result = cfg80211_tx_mlme_mgmt(*(_QWORD *)(v1 + 1608), v12, 26, 0);
LABEL_10:
  if ( (*(_BYTE *)(v1 + 2477) & 8) != 0 && (*(_BYTE *)(*(_QWORD *)(v1 + 1616) + 1472LL) & 1) == 0 )
  {
    v10 = 0;
    v6[0] = &v10;
    v6[1] = 0;
    v7 = 3;
    v5 = *(_DWORD *)(v1 + 4802);
    v11 = 0;
    v6[2] = 0;
    v10 = v5;
    LOWORD(v5) = *(_WORD *)(v1 + 4806);
    v8 = 0;
    v9 = 0;
    v11 = v5;
    result = ieee80211_mgd_deauth(v1, v6);
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
