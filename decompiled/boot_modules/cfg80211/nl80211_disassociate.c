__int64 __fastcall nl80211_disassociate(__int64 a1, __int64 a2)
{
  __int64 v3; // x1
  __int64 *v4; // x0
  __int64 v5; // x10
  int v6; // w9
  __int64 v7; // x9
  __int64 v8; // x8
  __int64 v9; // x11
  int v10; // w10

  v3 = *(_QWORD *)(a2 + 56);
  v4 = *(__int64 **)(a2 + 48);
  v5 = *(_QWORD *)(v3 + 992);
  v6 = *(_DWORD *)(v5 + 100);
  if ( v6 && v6 != *(_DWORD *)(a2 + 4) )
    return 0xFFFFFFFFLL;
  v7 = *(_QWORD *)(a2 + 32);
  v8 = *(_QWORD *)(v7 + 48);
  if ( !v8 )
    return 4294967274LL;
  v9 = *(_QWORD *)(v7 + 432);
  if ( !v9 )
    return 4294967274LL;
  if ( *(_QWORD *)(*v4 + 360) )
  {
    v10 = *(_DWORD *)(v5 + 8);
    if ( v10 == 8 || v10 == 2 )
    {
      if ( *(_WORD *)(v9 + 4) )
        return cfg80211_mlme_disassoc(v4, v3, v8 + 4);
      return 4294967274LL;
    }
  }
  return 4294967201LL;
}
