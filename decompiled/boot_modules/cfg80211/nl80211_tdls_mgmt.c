__int64 __fastcall nl80211_tdls_mgmt(__int64 a1, _QWORD *a2)
{
  _BYTE *v2; // x19
  _QWORD *v3; // x10
  __int64 v4; // x11
  __int64 v5; // x12
  __int64 v6; // x13
  __int16 *v7; // x8
  __int64 v8; // x9
  __int64 v9; // x14
  __int64 v10; // x7
  __int64 v12; // x1
  __int64 v13; // x14
  __int64 v14; // x4
  __int64 v15; // x6
  __int64 v16; // x5
  __int64 v17; // x3
  _WORD *v18; // x8
  __int16 v19; // t1
  __int64 v20; // x11
  bool v21; // zf
  _DWORD *v22; // x10
  char v23; // w12

  v2 = (_BYTE *)a2[6];
  if ( (v2[1093] & 0x80) == 0 || !*(_QWORD *)(*(_QWORD *)v2 + 616LL) )
    return 4294967201LL;
  v3 = (_QWORD *)a2[4];
  v4 = v3[136];
  if ( !v4 )
    return 4294967274LL;
  v5 = v3[72];
  if ( !v5 )
    return 4294967274LL;
  v6 = v3[137];
  if ( !v6 )
    return 4294967274LL;
  v7 = (__int16 *)v3[42];
  if ( !v7 )
    return 4294967274LL;
  v8 = v3[6];
  if ( !v8 )
    return 4294967274LL;
  v9 = v3[203];
  if ( v9 )
    v10 = *(unsigned int *)(v9 + 4);
  else
    v10 = 0;
  v12 = a2[7];
  v13 = v3[313];
  v14 = *(unsigned __int8 *)(v4 + 4);
  v15 = *(unsigned __int16 *)(v5 + 4);
  v16 = *(unsigned __int8 *)(v6 + 4);
  if ( v13 )
    v17 = *(unsigned __int8 *)(v13 + 4);
  else
    v17 = 0xFFFFFFFFLL;
  v19 = *v7;
  v18 = v7 + 2;
  v20 = (unsigned __int16)(v19 - 4);
  v21 = v3[207] == 0;
  v22 = *(_DWORD **)(*(_QWORD *)v2 + 616LL);
  v23 = !v21;
  if ( *(v22 - 1) != 721051291 )
    __break(0x822Au);
  return ((__int64 (__fastcall *)(_BYTE *, __int64, __int64, __int64, __int64, __int64, __int64, __int64, char, _WORD *, __int64))v22)(
           v2 + 992,
           v12,
           v8 + 4,
           v17,
           v14,
           v16,
           v15,
           v10,
           v23,
           v18,
           v20);
}
