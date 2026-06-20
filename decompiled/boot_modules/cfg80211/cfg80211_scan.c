__int64 __fastcall cfg80211_scan(__int64 *a1)
{
  __int64 v1; // x19
  __int64 v2; // x8
  __int64 *v3; // x0
  __int64 (__fastcall *v4)(__int64 *, __int64); // x8
  __int64 v6; // x8
  __int64 v7; // x9
  unsigned int v8; // w23
  int v9; // w10
  int v10; // w11
  int **v11; // x12
  __int64 v12; // x13
  _DWORD *v13; // x14
  int *v14; // x15
  int v15; // w15
  __int64 v16; // x8
  _DWORD **v17; // x10
  _DWORD *v18; // t1
  unsigned __int64 v20; // x21
  _DWORD *v21; // x0
  _DWORD *v22; // x20
  unsigned __int64 v23; // x13
  __int64 v24; // x9
  unsigned int v25; // w12
  _DWORD *v26; // x14
  unsigned __int64 v27; // x13
  bool v28; // cf
  unsigned __int64 v29; // x13
  int v30; // w9
  _DWORD *v31; // x9

  v1 = a1[28];
  if ( (*((_BYTE *)a1 + 1092) & 4) == 0 )
  {
    if ( *(_DWORD *)(v1 + 8) || !*(_QWORD *)v1 )
    {
      v2 = *a1;
      v3 = a1 + 124;
      v4 = *(__int64 (__fastcall **)(__int64 *, __int64))(v2 + 320);
      if ( *((_DWORD *)v4 - 1) != 1783679515 )
        __break(0x8228u);
      return v4(v3, v1);
    }
    goto LABEL_38;
  }
  v6 = *(unsigned int *)(v1 + 12);
  if ( !(_DWORD)v6 )
    return ((__int64 (*)(void))cfg80211_scan_6ghz)();
  if ( (_DWORD)v6 == 1 )
  {
    v7 = 0;
    v8 = 0;
  }
  else
  {
    v7 = (unsigned int)v6 & 0xFFFFFFFE;
    v9 = 0;
    v10 = 0;
    v11 = (int **)(v1 + 168);
    v12 = v7;
    do
    {
      v13 = *(v11 - 1);
      v14 = *v11;
      v11 += 2;
      v15 = *v14;
      if ( *v13 != 3 )
        ++v9;
      if ( v15 != 3 )
        ++v10;
      v12 -= 2;
    }
    while ( v12 );
    v8 = v10 + v9;
    if ( v7 == v6 )
      goto LABEL_21;
  }
  v16 = v6 - v7;
  v17 = (_DWORD **)(v1 + 8 * v7 + 160);
  do
  {
    v18 = *v17++;
    if ( *v18 != 3 )
      ++v8;
    --v16;
  }
  while ( v16 );
LABEL_21:
  if ( !v8 )
    return ((__int64 (*)(void))cfg80211_scan_6ghz)();
  v20 = 8LL * v8 + 160;
  v21 = (_DWORD *)_kmalloc_noprof(v20, 3520);
  v22 = v21;
  if ( !v21 )
    return 4294967284LL;
  memcpy(v21, (const void *)v1, 0xA0u);
  v22[3] = v8;
  v23 = *(unsigned int *)(v1 + 12);
  if ( !(_DWORD)v23 )
  {
LABEL_33:
    *(_BYTE *)(v1 + 130) = 0;
    v30 = v22[2];
    a1[29] = (__int64)v22;
    if ( v30 || !*(_QWORD *)v22 )
    {
      v31 = *(_DWORD **)(*a1 + 320);
      if ( *(v31 - 1) != 1783679515 )
        __break(0x8229u);
      return ((__int64 (__fastcall *)(__int64 *, _DWORD *))v31)(a1 + 124, v22);
    }
LABEL_38:
    __break(0x800u);
    return 4294967274LL;
  }
  v24 = 0;
  v25 = 0;
  while ( 1 )
  {
    v26 = *(_DWORD **)(v1 + 160 + 8 * v24);
    if ( *v26 == 3 )
      goto LABEL_26;
    v27 = 8LL * v25 + 160;
    v28 = v20 >= v27;
    v29 = v20 - v27;
    if ( !v28 || v29 < 8 )
      break;
    *(_QWORD *)&v22[2 * v25++ + 40] = v26;
    v23 = *(unsigned int *)(v1 + 12);
LABEL_26:
    if ( ++v24 >= v23 )
      goto LABEL_33;
  }
  __break(1u);
  return ((__int64 (*)(void))cfg80211_scan_6ghz)();
}
