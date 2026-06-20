__int64 __fastcall ieee80211_dfs_cac_cancel(__int64 result, __int64 a2)
{
  _QWORD *v2; // x22
  _QWORD *v3; // x23
  __int64 v5; // x20
  __int64 v6; // x24
  __int64 v7; // x25
  __int64 i; // x26
  __int64 *v9; // x21
  _QWORD *v10; // x8
  __int64 v11; // x10
  __int64 v12; // x8
  __int64 v13; // x9
  __int64 v14; // [xsp+8h] [xbp-28h] BYREF
  __int64 v15; // [xsp+10h] [xbp-20h]
  __int64 v16; // [xsp+18h] [xbp-18h]
  __int64 v17; // [xsp+20h] [xbp-10h]
  __int64 v18; // [xsp+28h] [xbp-8h]

  v18 = *(_QWORD *)(_ReadStatusReg(SP_EL0) + 1808);
  v2 = *(_QWORD **)(result + 4616);
  v3 = (_QWORD *)(result + 4616);
  v16 = 0;
  v17 = 0;
  v14 = 0;
  v15 = 0;
  if ( v2 != (_QWORD *)(result + 4616) )
  {
    v5 = result;
    v6 = a2 + 152;
    do
    {
      v7 = 57;
      for ( i = 571; i != 586; ++i )
      {
        v9 = (__int64 *)v2[i];
        if ( v9 && (!a2 || v6 == *(_QWORD *)(v9[118] + 832)) )
        {
          result = wiphy_delayed_work_cancel(*(_QWORD *)(v5 + 72), v9 + 58);
          if ( LOBYTE(v2[v7]) == 1 )
          {
            v10 = (_QWORD *)v9[118];
            v11 = v10[18];
            v14 = v10[17];
            v15 = v11;
            v13 = v10[19];
            v12 = v10[20];
            v16 = v13;
            v17 = v12;
            ieee80211_link_release_channel(v9);
            result = cfg80211_cac_event(v2[201], &v14, 2, 3264, (unsigned int)(i - 571));
          }
        }
        v7 += 9;
      }
      v2 = (_QWORD *)*v2;
    }
    while ( v2 != v3 );
  }
  _ReadStatusReg(SP_EL0);
  return result;
}
