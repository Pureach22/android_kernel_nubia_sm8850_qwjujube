__int64 __fastcall ieee80211_ibss_finish_csa(__int64 a1, _QWORD *a2)
{
  __int64 v3; // x20
  _QWORD *bss; // x1
  __int64 v5; // x9
  __int64 v6; // x10
  __int64 v7; // x8

  if ( *(_DWORD *)(a1 + 2520) != 1 )
    return 4294967229LL;
  if ( *(_DWORD *)(a1 + 2346) | *(unsigned __int16 *)(a1 + 2350) )
  {
    v3 = a1;
    bss = (_QWORD *)_cfg80211_get_bss(
                      *(_QWORD *)(*(_QWORD *)(a1 + 1616) + 72LL),
                      *(_QWORD *)(a1 + 2400),
                      a1 + 2346,
                      a1 + 2352,
                      *(unsigned __int8 *)(a1 + 2384),
                      2,
                      *(unsigned __int8 *)(a1 + 2342) ^ 1u,
                      1);
    a1 = v3;
    if ( bss )
    {
      *bss = *(_QWORD *)(v3 + 3784);
      cfg80211_put_bss(*(_QWORD *)(*(_QWORD *)(v3 + 1616) + 72LL), bss);
      a1 = v3;
    }
  }
  v5 = *(_QWORD *)(a1 + 3792);
  v6 = *(_QWORD *)(a1 + 3800);
  *(_QWORD *)(a1 + 2400) = *(_QWORD *)(a1 + 3784);
  v7 = *(_QWORD *)(a1 + 3808);
  *(_QWORD *)(a1 + 2408) = v5;
  *(_QWORD *)(a1 + 2416) = v6;
  *(_QWORD *)(a1 + 2424) = v7;
  return ieee80211_ibss_csa_beacon(a1, 0, a2);
}
