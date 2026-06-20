__int64 __fastcall ieee80211_dfs_radar_detected_work(__int64 a1, __int64 a2)
{
  __int64 v2; // x21
  __int64 v3; // x19
  __int64 v4; // x20
  _QWORD *v5; // x22
  __int64 v6; // x8
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 result; // x0
  __int64 v10; // [xsp+8h] [xbp-28h] BYREF
  __int64 v11; // [xsp+10h] [xbp-20h]
  __int64 v12; // [xsp+18h] [xbp-18h]
  __int64 v13; // [xsp+20h] [xbp-10h]
  __int64 v14; // [xsp+28h] [xbp-8h]

  v2 = a2 + 3504;
  v14 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v3 = *(_QWORD *)(a2 + 3504);
  if ( v3 != a2 + 3504 )
  {
    v4 = a2 - 1480;
    v5 = (_QWORD *)(a2 - 1408);
    v12 = 0;
    v13 = 0;
    v10 = 0;
    v11 = 0;
    do
    {
      if ( *(_DWORD *)(v3 + 64) != 2 && *(_BYTE *)(v3 + 256) == 1 )
      {
        v6 = *(_QWORD *)(v3 + 152);
        v7 = *(_QWORD *)(v3 + 160);
        *(_BYTE *)(v3 + 256) = 0;
        v10 = v6;
        v11 = v7;
        v8 = *(_QWORD *)(v3 + 176);
        v12 = *(_QWORD *)(v3 + 168);
        v13 = v8;
        ieee80211_dfs_cac_cancel(v4, v3);
        result = _cfg80211_radar_event(*v5, &v10, 0, 3264);
      }
      v3 = *(_QWORD *)v3;
    }
    while ( v3 != v2 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
