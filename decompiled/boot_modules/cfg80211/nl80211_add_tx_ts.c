__int64 __fastcall nl80211_add_tx_ts(__int64 a1, _QWORD *a2)
{
  __int64 v2; // x0
  _QWORD *v4; // x9
  __int64 v5; // x11
  __int64 v6; // x1
  __int64 v7; // x11
  __int64 v8; // x9
  int v9; // w10

  v2 = a2[6];
  if ( (*(_BYTE *)(v2 + 1103) & 4) == 0 )
    return 4294967201LL;
  v4 = (_QWORD *)a2[4];
  v5 = v4[210];
  if ( !v5 )
    return 4294967274LL;
  if ( !v4[6] )
    return 4294967274LL;
  if ( !v4[211] )
    return 4294967274LL;
  if ( *(unsigned __int8 *)(v5 + 4) > 7u )
    return 4294967274LL;
  v6 = a2[7];
  v7 = v4[212];
  v8 = *(_QWORD *)(v6 + 992);
  if ( v7 )
  {
    if ( !*(_WORD *)(v7 + 4) )
      return 4294967274LL;
  }
  v9 = *(_DWORD *)(v8 + 8);
  if ( v9 != 8 && v9 != 2 )
    return 4294967201LL;
  if ( (*(_BYTE *)(v8 + 164) & 1) != 0 )
    return rdev_add_tx_ts(v2, v6);
  else
    return 4294967189LL;
}
