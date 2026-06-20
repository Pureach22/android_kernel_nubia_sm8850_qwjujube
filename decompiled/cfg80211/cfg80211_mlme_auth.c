__int64 __fastcall cfg80211_mlme_auth(__int64 *a1, __int64 a2, __int64 *a3)
{
  __int64 v3; // x9
  int v4; // w8
  __int64 v5; // x10
  int v6; // w12
  int v7; // w11
  int *v9; // x10
  int v10; // w9
  int v11; // w10
  __int64 v12; // x8
  _QWORD *v13; // x0
  __int64 (__fastcall *v14)(_QWORD); // x8

  v3 = *a3;
  if ( !*a3 )
    return 4294967294LL;
  v4 = *((char *)a3 + 72);
  v5 = *(_QWORD *)(a2 + 992);
  if ( (v4 & 0x80000000) == 0 && (*(_BYTE *)(*(_QWORD *)v5 + 100LL) & 2) == 0
    || *((_DWORD *)a3 + 9) == 1 && (!a3[5] || !*((_BYTE *)a3 + 48) || *((unsigned __int8 *)a3 + 49) > 3u) )
  {
    return 4294967274LL;
  }
  if ( (*(_BYTE *)(v5 + 164) & 1) != 0 )
  {
    v7 = *(unsigned __int16 *)(v3 + 76);
    v6 = *(_DWORD *)(v3 + 72);
    if ( !(*(_DWORD *)(v5 + 280) ^ v6 | (unsigned __int16)(*(_WORD *)(v5 + 284) ^ v7)) )
      return 4294967182LL;
  }
  else
  {
    v6 = *(_DWORD *)(v3 + 72);
    v7 = *(unsigned __int16 *)(v3 + 76);
  }
  v9 = *(int **)(a2 + 1008);
  v10 = *v9;
  v11 = *((unsigned __int16 *)v9 + 2);
  if ( !(v10 ^ v6 | v11 ^ v7)
    || (v4 & 0x80000000) == 0 && !(*(_DWORD *)a3[10] ^ v10 | *(unsigned __int16 *)(a3[10] + 4) ^ v11) )
  {
    return 4294967274LL;
  }
  v12 = *a1;
  v13 = a1 + 124;
  v14 = *(__int64 (__fastcall **)(_QWORD))(v12 + 336);
  if ( *((_DWORD *)v14 - 1) != -881606998 )
    __break(0x8228u);
  return v14(v13);
}
