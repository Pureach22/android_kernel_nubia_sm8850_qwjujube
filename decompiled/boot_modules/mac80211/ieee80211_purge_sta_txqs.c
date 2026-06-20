__int64 __fastcall ieee80211_purge_sta_txqs(__int64 result)
{
  __int64 v1; // x8
  _QWORD *v2; // x20
  __int64 v3; // x19
  __int64 v4; // x8
  __int64 v5; // x8
  __int64 v6; // x8
  __int64 v7; // x8
  __int64 v8; // x8
  __int64 v9; // x8
  __int64 v10; // x8
  __int64 v11; // x8
  __int64 v12; // x8
  __int64 v13; // x8
  __int64 v14; // x8
  __int64 v15; // x8
  __int64 v16; // x8
  __int64 v17; // x8
  __int64 v18; // x8
  __int64 v19; // x8

  v1 = *(_QWORD *)(result + 2736);
  v2 = (_QWORD *)result;
  v3 = *(_QWORD *)(*(_QWORD *)(result + 80) + 1616LL);
  if ( v1 )
    result = ieee80211_txq_purge(*(_QWORD *)(*(_QWORD *)(result + 80) + 1616LL), v1 - 232);
  v4 = v2[343];
  if ( v4 )
    result = ieee80211_txq_purge(v3, v4 - 232);
  v5 = v2[344];
  if ( v5 )
    result = ieee80211_txq_purge(v3, v5 - 232);
  v6 = v2[345];
  if ( v6 )
    result = ieee80211_txq_purge(v3, v6 - 232);
  v7 = v2[346];
  if ( v7 )
    result = ieee80211_txq_purge(v3, v7 - 232);
  v8 = v2[347];
  if ( v8 )
    result = ieee80211_txq_purge(v3, v8 - 232);
  v9 = v2[348];
  if ( v9 )
    result = ieee80211_txq_purge(v3, v9 - 232);
  v10 = v2[349];
  if ( v10 )
    result = ieee80211_txq_purge(v3, v10 - 232);
  v11 = v2[350];
  if ( v11 )
    result = ieee80211_txq_purge(v3, v11 - 232);
  v12 = v2[351];
  if ( v12 )
    result = ieee80211_txq_purge(v3, v12 - 232);
  v13 = v2[352];
  if ( v13 )
    result = ieee80211_txq_purge(v3, v13 - 232);
  v14 = v2[353];
  if ( v14 )
    result = ieee80211_txq_purge(v3, v14 - 232);
  v15 = v2[354];
  if ( v15 )
    result = ieee80211_txq_purge(v3, v15 - 232);
  v16 = v2[355];
  if ( v16 )
    result = ieee80211_txq_purge(v3, v16 - 232);
  v17 = v2[356];
  if ( v17 )
    result = ieee80211_txq_purge(v3, v17 - 232);
  v18 = v2[357];
  if ( v18 )
    result = ieee80211_txq_purge(v3, v18 - 232);
  v19 = v2[358];
  if ( v19 )
    return ieee80211_txq_purge(v3, v19 - 232);
  return result;
}
