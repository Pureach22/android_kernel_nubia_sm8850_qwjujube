__int64 __fastcall ieee80211_txq_airtime_check(__int64 a1, __int64 a2)
{
  unsigned int v2; // w8
  __int64 v3; // x10
  __int64 v4; // x10
  __int64 v5; // x11
  _DWORD *v6; // x11
  unsigned int v7; // t1

  v2 = 1;
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 72) + 117LL) & 1) == 0 )
    return v2;
  v3 = *(_QWORD *)(a2 + 8);
  if ( !v3 )
    return v2;
  v2 = 1;
  if ( *(_BYTE *)(a2 + 16) == 16 )
    return v2;
  if ( *(unsigned __int8 *)(a2 + 17) < 4uLL )
  {
    v4 = v3 - 2160;
    v5 = v4 + 40LL * *(unsigned __int8 *)(a2 + 17);
    v7 = *(_DWORD *)(v5 + 28);
    v6 = (_DWORD *)(v5 + 28);
    v2 = 1;
    if ( v7 >= v6[1] )
    {
      if ( *(_DWORD *)(a1 + 444) >= *(_DWORD *)(a1 + 440) )
        return 0;
      v2 = 1;
      if ( *v6 >= *(_DWORD *)(v4 + 40LL * *(unsigned __int8 *)(a2 + 17) + 36) )
        return 0;
    }
    return v2;
  }
  __break(0x5512u);
  return ieee80211_tx_h_select_key(a1);
}
