unsigned __int64 __fastcall nl80211_testmode_do(__int64 a1, __int64 a2)
{
  _QWORD *v3; // x19
  unsigned __int64 result; // x0
  __int16 *v5; // x2
  _WORD *v6; // x2
  __int16 v7; // t1
  __int64 v8; // x3
  _DWORD *v9; // x8

  v3 = *(_QWORD **)(a2 + 48);
  result = _cfg80211_wdev_from_attrs((__int64)v3, *(void **)(a2 + 40), *(_QWORD *)(a2 + 32));
  if ( !*(_QWORD *)(*v3 + 448LL) )
    return 4294967201LL;
  if ( result < 0xFFFFFFFFFFFFF001LL )
  {
    if ( *(_QWORD **)result != v3 + 124 )
      return 4294967274LL;
  }
  else
  {
    if ( (_DWORD)result != -22 )
      return result;
    result = 0;
  }
  if ( !*(_QWORD *)(*(_QWORD *)(a2 + 32) + 552LL) )
    return 4294967274LL;
  v3[37] = a2;
  v5 = *(__int16 **)(*(_QWORD *)(a2 + 32) + 552LL);
  v7 = *v5;
  v6 = v5 + 2;
  v8 = (unsigned __int16)(v7 - 4);
  v9 = *(_DWORD **)(*v3 + 448LL);
  if ( *(v9 - 1) != 995036090 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(_QWORD *, unsigned __int64, _WORD *, __int64))v9)(v3 + 124, result, v6, v8);
  v3[37] = 0;
  return result;
}
