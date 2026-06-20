__int64 __fastcall nl80211_tdls_oper(__int64 a1, _QWORD *a2)
{
  _BYTE *v2; // x19
  __int64 v3; // x8
  __int64 v4; // x9
  __int64 v5; // x8
  __int64 v6; // x1
  __int64 v7; // x3
  _DWORD *v8; // x9

  v2 = (_BYTE *)a2[6];
  if ( (v2[1093] & 0x80) == 0 || !*(_QWORD *)(*(_QWORD *)v2 + 624LL) )
    return 4294967201LL;
  v3 = a2[4];
  v4 = *(_QWORD *)(v3 + 1104);
  if ( !v4 )
    return 4294967274LL;
  v5 = *(_QWORD *)(v3 + 48);
  if ( !v5 )
    return 4294967274LL;
  v6 = a2[7];
  v7 = *(unsigned __int8 *)(v4 + 4);
  v8 = *(_DWORD **)(*(_QWORD *)v2 + 624LL);
  if ( *(v8 - 1) != 383144933 )
    __break(0x8229u);
  return ((__int64 (__fastcall *)(_BYTE *, __int64, __int64, __int64))v8)(v2 + 992, v6, v5 + 4, v7);
}
