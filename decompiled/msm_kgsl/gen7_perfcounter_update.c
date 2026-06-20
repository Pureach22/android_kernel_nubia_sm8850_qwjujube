__int64 __fastcall gen7_perfcounter_update(__int64 a1, int *a2, char a3, int a4, char a5)
{
  int v6; // w28
  __int64 v9; // x22
  int v11; // w21
  __int64 v12; // x25
  int v13; // w9
  unsigned int v14; // w26
  int v16; // w10
  int v17; // w9
  __int64 v18; // x27
  _DWORD *v19; // x10
  __int16 v20; // w10
  unsigned int v21; // w8
  int v22; // w9
  int v23; // w8
  char v24; // [xsp+Ch] [xbp-4h]

  v6 = *(unsigned __int16 *)(a1 + 24548);
  v9 = *(_QWORD *)(*(_QWORD *)(a1 + 20464) + 8LL);
  v11 = *(unsigned __int16 *)(v9 + 14);
  v12 = v9 + 16;
  v13 = 2 * (*(unsigned __int8 *)(v9 + 13) + *(unsigned __int8 *)(v9 + 12));
  v14 = v13 + 3 * v6;
  if ( (a5 & 2) != 0 )
  {
    if ( v11 != v6 )
    {
      v16 = 3 * v6 + v13;
      if ( (((_WORD)v11 - (_WORD)v6) & 0xFFFE) != 0 )
        v17 = (unsigned __int16)(v11 - v6);
      else
        v17 = 1;
      v18 = (unsigned int)(v16 + 2);
      v19 = (_DWORD *)(v9 + 4LL * v14 + 20);
      while ( *v19 != a2[6] || *(v19 - 1) != a4 )
      {
        if ( *v19 != 1280 )
        {
          --v17;
          v14 += 3;
          v18 += 3;
          v19 += 3;
          if ( v17 )
            continue;
        }
        goto LABEL_15;
      }
      v24 = a3;
      if ( (unsigned int)kgsl_hwlock(*(_QWORD *)(*(_QWORD *)(a1 + 20464) + 8LL)) )
        goto LABEL_16;
      v23 = *a2;
LABEL_22:
      *(_DWORD *)(v12 + 4 * v18) = v23;
      kgsl_hwunlock(v9);
      if ( (v24 & 1) == 0 )
        return 0;
      goto LABEL_4;
    }
  }
  else if ( v11 != v6 )
  {
    if ( (a3 & 1) == 0 )
      return 0;
LABEL_4:
    kgsl_regmap_write(a1 + 13200, (unsigned int)*a2);
    return 0;
  }
LABEL_15:
  v24 = a3;
  if ( !(unsigned int)kgsl_hwlock(*(_QWORD *)(*(_QWORD *)(a1 + 20464) + 8LL)) )
  {
    if ( v11 == v6 )
      *(_WORD *)(v9 + 14) = *(_WORD *)(a1 + 24548) + 1;
    if ( (a5 & 2) != 0 )
    {
      *(_DWORD *)(v12 + 4LL * v14) = a4;
      v20 = *(_WORD *)(v9 + 14);
      *(_DWORD *)(v12 + 4LL * (v14 + 1)) = a2[6];
      v21 = v14 + 2;
      v22 = *a2;
      v14 += 3;
      *(_WORD *)(v9 + 14) = v20 + 1;
      *(_DWORD *)(v12 + 4LL * v21) = v22;
    }
    *(_DWORD *)(v12 + 4LL * v14) = 0;
    v18 = v14 + 2;
    *(_DWORD *)(v12 + 4LL * (v14 + 1)) = 1280;
    v23 = 1;
    goto LABEL_22;
  }
LABEL_16:
  kgsl_hwunlock(v9);
  return 4294967280LL;
}
