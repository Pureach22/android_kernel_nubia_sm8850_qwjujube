__int64 __fastcall nl80211_disconnect(__int64 a1, __int64 a2)
{
  __int64 v3; // x1
  __int64 v4; // x0
  __int64 v5; // x9
  int v6; // w10
  __int64 v7; // x8
  __int64 v8; // x2
  int v10; // w8

  v3 = *(_QWORD *)(a2 + 56);
  v4 = *(_QWORD *)(a2 + 48);
  v5 = *(_QWORD *)(v3 + 992);
  v6 = *(_DWORD *)(v5 + 100);
  if ( v6 && v6 != *(_DWORD *)(a2 + 4) )
    return 0xFFFFFFFFLL;
  v7 = *(_QWORD *)(*(_QWORD *)(a2 + 32) + 432LL);
  if ( v7 )
  {
    v8 = *(unsigned __int16 *)(v7 + 4);
    if ( !*(_WORD *)(v7 + 4) )
      return 4294967274LL;
  }
  else
  {
    v8 = 3;
  }
  v10 = *(_DWORD *)(v5 + 8);
  if ( v10 == 8 || v10 == 2 )
    return cfg80211_disconnect(v4, v3, v8, 1);
  else
    return 4294967201LL;
}
