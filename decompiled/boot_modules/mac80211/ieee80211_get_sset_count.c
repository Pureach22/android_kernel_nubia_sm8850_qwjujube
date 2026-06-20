__int64 __fastcall ieee80211_get_sset_count(__int64 a1, unsigned int a2)
{
  __int64 v2; // x20
  __int64 v4; // x1
  __int64 v5; // x0
  _DWORD *v6; // x8
  int v7; // w0
  int v8; // w8
  unsigned int v9; // w8

  v2 = *(_QWORD *)(a1 + 4304);
  if ( *(_QWORD *)(*(_QWORD *)(v2 + 464) + 544LL) )
  {
    v4 = a1 + 7408;
    v5 = *(_QWORD *)(a1 + 4304);
    v6 = *(_DWORD **)(*(_QWORD *)(v2 + 464) + 544LL);
    if ( *(v6 - 1) != -109195373 )
      __break(0x8228u);
    v7 = ((__int64 (__fastcall *)(__int64, __int64, _QWORD))v6)(v5, v4, a2);
  }
  else
  {
    v7 = 0;
  }
  if ( a2 == 1 )
    v8 = 21;
  else
    v8 = 0;
  v9 = v7 + v8;
  if ( v9 )
    return v9;
  else
    return 4294967201LL;
}
