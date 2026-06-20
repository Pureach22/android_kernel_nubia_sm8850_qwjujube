__int64 __fastcall nl80211_crit_protocol_start(__int64 a1, __int64 a2)
{
  _DWORD *v2; // x19
  __int64 result; // x0
  __int64 v4; // x8
  __int64 v6; // x1
  __int64 v7; // x9
  _DWORD *v8; // x8

  v2 = *(_DWORD **)(a2 + 48);
  if ( !*(_QWORD *)(*(_QWORD *)v2 + 704LL) )
    return 4294967201LL;
  if ( !*(_QWORD *)(*(_QWORD *)v2 + 712LL) )
  {
    __break(0x800u);
    return 4294967274LL;
  }
  if ( v2[162] )
    return 4294967280LL;
  v4 = *(_QWORD *)(a2 + 32);
  v6 = *(_QWORD *)(a2 + 56);
  v7 = *(_QWORD *)(v4 + 1432);
  if ( v7 )
  {
    if ( *(unsigned __int16 *)(v7 + 4) <= 3u && *(_QWORD *)(v4 + 1440) )
      goto LABEL_9;
    return 4294967274LL;
  }
  if ( !*(_QWORD *)(v4 + 1440) )
    return 4294967274LL;
LABEL_9:
  v8 = *(_DWORD **)(*(_QWORD *)v2 + 704LL);
  if ( *(v8 - 1) != -1091267344 )
    __break(0x8228u);
  result = ((__int64 (__fastcall *)(_DWORD *, __int64))v8)(v2 + 248, v6);
  if ( !(_DWORD)result )
    v2[162] = *(_DWORD *)(a2 + 4);
  return result;
}
