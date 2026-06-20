__int64 __fastcall gen8_perfcounter_remove(__int64 a1, _DWORD *a2, unsigned int a3)
{
  __int64 v3; // x24
  int v4; // w20
  __int64 v5; // x19
  int v6; // w8
  int v7; // w9
  __int64 v9; // x21
  int v10; // w23
  __int64 v11; // x22
  unsigned int v12; // w20
  unsigned int v13; // w11
  unsigned int v14; // w25
  __int64 v15; // x26
  int v16; // w24
  unsigned int v17; // w11
  _DWORD *i; // x10
  int v19; // w28
  int v20; // w8
  int v21; // w8
  __int64 v22; // x20
  __int16 v23; // w8
  _QWORD *v24; // x8

  v3 = a1 + 20480;
  v4 = *(unsigned __int16 *)(a1 + 24548);
  v5 = *(_QWORD *)(*(_QWORD *)(a1 + 20464) + 8LL);
  if ( a3 > 0x36 )
    goto LABEL_27;
  if ( ((1LL << a3) & 0x70008FC) != 0 )
  {
    v6 = 4096;
    goto LABEL_6;
  }
  if ( ((1LL << a3) & 0x78E00000000000LL) != 0 )
    v6 = 0x2000;
  else
LABEL_27:
    v6 = 0;
LABEL_6:
  v7 = *(unsigned __int16 *)(v5 + 14) - v4;
  if ( !v7 )
    return 4294967274LL;
  v9 = v5 + 16;
  v10 = *(unsigned __int8 *)(v5 + 13) + *(unsigned __int8 *)(v5 + 12);
  v11 = (unsigned int)(3 * v4 + 2 * v10);
  if ( (*(_BYTE *)(**(_QWORD **)(*(_QWORD *)(a1 + 14264) + 48LL) + 56LL * a3 + 24) & 2) == 0 )
  {
    if ( (unsigned __int16)(*(_WORD *)(v5 + 14) - v4) != 2 )
      return 0;
    if ( (unsigned int)kgsl_hwlock(*(_QWORD *)(*(_QWORD *)(a1 + 20464) + 8LL)) )
      goto LABEL_11;
    if ( *(_DWORD *)(v3 + 3564) )
    {
      v12 = 0;
      goto LABEL_32;
    }
    v24 = (_QWORD *)(v9 + 4LL * (unsigned int)v11);
    v24[1] = 0;
    v24[2] = 0;
    *v24 = 0;
    v23 = *(_WORD *)(v3 + 4068);
LABEL_31:
    v12 = 0;
    *(_WORD *)(v5 + 14) = v23;
    goto LABEL_32;
  }
  v13 = (unsigned __int16)(*(_WORD *)(v5 + 14) - v4);
  if ( v13 < 3 )
    return 4294967294LL;
  v14 = v13 + 2 * (unsigned __int16)v7;
  v15 = v11 << 32;
  v16 = 0;
  v17 = v13 - 2;
  for ( i = (_DWORD *)(v5 + 4LL * (unsigned int)v11 + 20); *i != a2[6] || *(i - 1) != v6; i += 3 )
  {
    --v17;
    v15 += 0x300000000LL;
    v16 += 3;
    if ( !v17 )
      return 4294967294LL;
  }
  v19 = v11 + v16;
  if ( (_DWORD)v11 + v16 == -1 )
    return 4294967294LL;
  if ( a2[10] )
  {
    if ( a2[11] )
      v20 = 6;
    else
      v20 = 3;
    v19 = v20 + v11 + v16;
  }
  if ( !(unsigned int)kgsl_hwlock(*(_QWORD *)(*(_QWORD *)(a1 + 20464) + 8LL)) )
  {
    memcpy(
      (void *)(v9 + (v15 >> 30)),
      (const void *)(v9 + 4LL * (unsigned int)(v19 + 3)),
      4LL * (v14 + (unsigned int)v11 - v19 - 3));
    v21 = 6 * v4;
    v22 = (unsigned int)(v19 - v11 - v16 + 3);
    memset((void *)(v9 + 4LL * (v21 + 4 * v10 + v14 - v19 + v16 - 3)), 0, 4 * v22);
    v23 = *(_WORD *)(v5 + 14) - (int)v22 / 3uLL;
    goto LABEL_31;
  }
LABEL_11:
  v12 = -16;
LABEL_32:
  kgsl_hwunlock(v5);
  return v12;
}
