__int64 __fastcall ieee80211_aggr_check(__int64 result, _BYTE *a2, __int64 a3)
{
  _QWORD **v3; // x8
  int v4; // w8

  v3 = *(_QWORD ***)(*(_QWORD *)(result + 1616) + 2536LL);
  if ( v3
    && a2
    && (**v3 & 2) != 0
    && a2[2926] == 1
    && a2[2698] == 1
    && *(_WORD *)(a3 + 124)
    && *(unsigned __int16 *)(a3 + 180) != *(unsigned __int16 *)(result + 1940) )
  {
    v4 = *(_DWORD *)(a3 + 144);
    if ( !*(_QWORD *)&a2[8 * (v4 & 0xF) + 904] )
      return ieee80211_start_tx_ba_session(a2 + 2688, v4 & 0xF, 0);
  }
  return result;
}
