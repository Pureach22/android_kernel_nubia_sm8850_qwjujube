__int64 __fastcall nl80211_del_pmk(__int64 a1, _QWORD *a2)
{
  int v2; // w9
  _BYTE *v4; // x19
  __int64 (__fastcall *v6)(_QWORD); // x9

  v2 = *(_DWORD *)(*(_QWORD *)(a2[7] + 992LL) + 8LL);
  if ( v2 != 8 && v2 != 2 )
    return 4294967201LL;
  v4 = (_BYTE *)a2[6];
  if ( (v4[1106] & 1) == 0 )
    return 4294967201LL;
  if ( !*(_QWORD *)(a2[4] + 48LL) )
    return 4294967274LL;
  v6 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v4 + 848LL);
  if ( !v6 )
    return 4294967201LL;
  if ( *((_DWORD *)v6 - 1) != 1857162459 )
    __break(0x8229u);
  return v6(v4 + 992);
}
