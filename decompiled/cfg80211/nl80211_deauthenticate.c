__int64 __fastcall nl80211_deauthenticate(__int64 a1, __int64 a2)
{
  __int64 v3; // x1
  __int64 *v4; // x0
  __int64 v5; // x10
  int v6; // w9
  _QWORD *v7; // x9
  __int64 v8; // x8
  __int64 v9; // x11
  int v10; // w10
  __int16 *v11; // x3
  __int16 v12; // t1
  __int64 v13; // x4

  v3 = *(_QWORD *)(a2 + 56);
  v4 = *(__int64 **)(a2 + 48);
  v5 = *(_QWORD *)(v3 + 992);
  v6 = *(_DWORD *)(v5 + 100);
  if ( v6 && v6 != *(_DWORD *)(a2 + 4) )
    return 0xFFFFFFFFLL;
  v7 = *(_QWORD **)(a2 + 32);
  v8 = v7[6];
  if ( !v8 )
    return 4294967274LL;
  v9 = v7[54];
  if ( !v9 )
    return 4294967274LL;
  if ( !*(_QWORD *)(*v4 + 352) )
    return 4294967201LL;
  v10 = *(_DWORD *)(v5 + 8);
  if ( v10 != 8 && v10 != 2 )
    return 4294967201LL;
  if ( !*(_WORD *)(v9 + 4) )
    return 4294967274LL;
  v11 = (__int16 *)v7[42];
  if ( v11 )
  {
    v12 = *v11;
    v11 += 2;
    v13 = (unsigned __int16)(v12 - 4);
  }
  else
  {
    v13 = 0;
  }
  return cfg80211_mlme_deauth(v4, v3, (int *)(v8 + 4), (__int64)v11, v13, *(unsigned __int16 *)(v9 + 4), v7[95] != 0);
}
