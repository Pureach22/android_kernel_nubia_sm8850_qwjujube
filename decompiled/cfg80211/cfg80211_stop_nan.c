__int64 __fastcall cfg80211_stop_nan(__int64 result, __int64 a2)
{
  __int64 v2; // x8
  _DWORD *v4; // x20
  __int64 v5; // x0
  __int64 (__fastcall *v6)(_QWORD); // x8

  if ( *(_DWORD *)(a2 + 8) != 12 )
  {
    __break(0x800u);
    return result;
  }
  v2 = *(_QWORD *)(a2 + 32);
  v4 = (_DWORD *)result;
  if ( v2 )
  {
    if ( (*(_QWORD *)(v2 + 168) & 1) == 0 )
      return result;
  }
  else if ( *(_BYTE *)(a2 + 66) != 1 )
  {
    return result;
  }
  v5 = result + 992;
  v6 = *(__int64 (__fastcall **)(_QWORD))(*(_QWORD *)v4 + 792LL);
  if ( *((_DWORD *)v6 - 1) != 1366774891 )
    __break(0x8228u);
  result = v6(v5);
  *(_BYTE *)(a2 + 66) = 0;
  --v4[28];
  return result;
}
