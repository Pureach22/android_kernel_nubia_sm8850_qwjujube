__int64 __fastcall netdev_notify(__int64 a1, __int64 a2, __int64 a3)
{
  _QWORD *v3; // x8
  __int64 *v4; // x9
  __int64 v5; // x9
  __int64 v7; // x10

  if ( a2 != 11 )
    return 0;
  v3 = *(_QWORD **)a3;
  v4 = *(__int64 **)(*(_QWORD *)a3 + 992LL);
  if ( !v4 )
    return 0;
  v5 = *v4;
  if ( !v5 || *(_UNKNOWN ***)(v5 + 320) != &mac80211_wiphy_privid )
    return 0;
  v7 = v3[38];
  v3[541] = v3[37];
  v3[542] = v7;
  return 1;
}
