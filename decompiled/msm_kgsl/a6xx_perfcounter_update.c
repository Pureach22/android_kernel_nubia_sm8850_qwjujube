__int64 __fastcall a6xx_perfcounter_update(__int64 a1, unsigned int *a2, char a3)
{
  __int64 v6; // x19
  unsigned int v7; // w10
  unsigned int v8; // w23
  unsigned int v9; // w11
  __int64 v10; // x8
  int v11; // w10
  __int64 v12; // x24
  int v13; // w11
  unsigned int v14; // w20

  v6 = *(_QWORD *)(*(_QWORD *)(a1 + 20464) + 8LL);
  v7 = *(unsigned __int16 *)(v6 + 12);
  if ( v7 >= 2 )
  {
    v9 = v7 >> 1;
    v10 = 0;
    v11 = v7 & 0xFFFE;
    v8 = 2 * v9;
    while ( 1 )
    {
      v12 = v6 + 4 * v10;
      v13 = *(_DWORD *)(v12 + 16);
      if ( v13 == a2[6] )
        break;
      if ( v13 == 1280 )
      {
        v8 = v10;
        goto LABEL_12;
      }
      v10 += 2;
      if ( v11 == (_DWORD)v10 )
        goto LABEL_12;
    }
    if ( (unsigned int)kgsl_hwlock(v6) )
      goto LABEL_13;
    *(_DWORD *)(v12 + 20) = *a2;
    if ( (a3 & 1) == 0 )
      goto LABEL_16;
    goto LABEL_15;
  }
  v8 = 0;
LABEL_12:
  if ( !(unsigned int)kgsl_hwlock(v6) )
  {
    *(_DWORD *)(v6 + 16 + 4LL * v8) = a2[6];
    *(_DWORD *)(v6 + 16 + 4LL * (v8 | 1)) = *a2;
    *(_DWORD *)(v6 + 16 + 4LL * (int)(v8 + 2)) = 1280;
    *(_DWORD *)(v6 + 16 + 4LL * (int)(v8 + 3)) = 1;
    *(_WORD *)(v6 + 12) += 2;
    if ( (a3 & 1) == 0 )
    {
LABEL_16:
      v14 = 0;
      goto LABEL_17;
    }
LABEL_15:
    kgsl_regmap_write(a1 + 13200, *a2);
    goto LABEL_16;
  }
LABEL_13:
  v14 = -16;
LABEL_17:
  kgsl_hwunlock(v6);
  return v14;
}
