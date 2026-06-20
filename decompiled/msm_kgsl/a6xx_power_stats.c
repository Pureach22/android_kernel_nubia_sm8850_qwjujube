__int64 __fastcall a6xx_power_stats(__int64 a1, unsigned __int64 *a2)
{
  __int64 v4; // x23
  __int64 result; // x0
  unsigned int v6; // w9
  unsigned int v7; // w8
  char v8; // w9
  __int64 v9; // x27
  unsigned int v10; // w0
  unsigned int v11; // w8
  unsigned int v12; // w21
  unsigned int v13; // w0
  unsigned int v14; // w8
  unsigned int v15; // w22
  unsigned int v16; // w8
  unsigned int v17; // w3
  int v18; // w8
  __int64 v19; // x8
  unsigned int v20; // w8
  unsigned __int64 v21; // x8
  unsigned int v22; // w8
  int v23; // w8
  unsigned int v24; // w9
  unsigned int v25; // w8
  unsigned __int64 v26; // x22
  unsigned int v27; // w9
  unsigned int v28; // w8
  unsigned __int64 v29; // x21
  unsigned int v30; // w9
  __int64 v31; // x8
  __int64 v32; // x22
  unsigned int v33; // w9
  __int64 v34; // x8
  __int64 v35; // x22
  unsigned int v36; // w9
  __int64 v37; // x8
  unsigned int v38; // w9
  __int64 v39; // x8

  v4 = a1 + 20336;
  result = kgsl_regmap_read(a1 + 13200);
  v6 = *(_DWORD *)v4;
  if ( *(_DWORD *)v4 )
  {
    v7 = result - v6;
    if ( (unsigned int)result < v6 )
      v7 = result + ~v6;
  }
  else
  {
    v7 = 0;
  }
  v8 = *(_BYTE *)(v4 + 96);
  v9 = v7;
  *(_DWORD *)v4 = result;
  if ( (v8 & 1) == 0 && *(_BYTE *)(v4 + 101) != 1 )
    goto LABEL_20;
  v10 = kgsl_regmap_read(a1 + 13200);
  v11 = *(_DWORD *)(v4 + 32);
  if ( v11 )
  {
    v12 = v10 - v11;
    if ( v10 < v11 )
      v12 = v10 + ~v11;
  }
  else
  {
    v12 = 0;
  }
  *(_DWORD *)(v4 + 32) = v10;
  v13 = kgsl_regmap_read(a1 + 13200);
  v14 = *(_DWORD *)(v4 + 36);
  if ( v14 )
  {
    v15 = v13 - v14;
    if ( v13 < v14 )
      v15 = v13 + ~v14;
  }
  else
  {
    v15 = 0;
  }
  *(_DWORD *)(v4 + 36) = v13;
  result = kgsl_regmap_read(a1 + 13200);
  v16 = *(_DWORD *)(v4 + 40);
  if ( v16 )
  {
    v17 = result - v16;
    if ( (unsigned int)result < v16 )
      v17 = result + ~v16;
  }
  else
  {
    v17 = 0;
  }
  v18 = *(unsigned __int8 *)(v4 + 101);
  *(_DWORD *)(v4 + 40) = result;
  if ( v18 != 1 )
  {
    v20 = **(_DWORD **)(a1 + 14264) - 620;
    if ( v20 <= 0x1E && ((1 << v20) & 0x40000007) != 0 )
      v21 = (42 * v12 + 500 * v15 + 917 * ((__int64)(v17 - (12 * v15 + (unsigned __int64)v12)) / 22)) / 1000;
    else
      v21 = (5 * v12 + 50 * v15 + 90 * v17) / 0x64uLL;
    v19 = -(__int64)v21;
  }
  else
  {
LABEL_20:
    v19 = 0;
  }
  *a2 = (unsigned __int64)((10
                          * ((v19 + v9) & (unsigned __int64)~((v19 + v9) >> 63))
                          * (unsigned __int128)0x2AAAAAAAAAAAAAABuLL) >> 64) >> 5;
  if ( (*(_BYTE *)(*(_QWORD *)(a1 + 14264) + 32LL) & 0x40) != 0 )
  {
    result = kgsl_regmap_read(a1 + 13200);
    v22 = *(_DWORD *)(v4 + 28);
    if ( v22 )
    {
      *(_DWORD *)(v4 + 28) = result;
      if ( (unsigned int)result < v22 )
        v23 = ~v22;
      else
        v23 = -v22;
      *(_DWORD *)(v4 + 312) += v23 + result;
    }
    else
    {
      *(_DWORD *)(v4 + 28) = result;
    }
  }
  if ( *(_BYTE *)(a1 + 10368) == 1 )
  {
    if ( *(_DWORD *)(v4 + 52) )
    {
      result = kgsl_regmap_read(a1 + 13200);
      v24 = *(_DWORD *)(v4 + 4);
      if ( v24 )
      {
        v25 = result - v24;
        if ( (unsigned int)result < v24 )
          v25 = result + ~v24;
      }
      else
      {
        v25 = 0;
      }
      *(_DWORD *)(v4 + 4) = result;
    }
    else
    {
      v25 = 0;
    }
    v26 = v25;
    if ( *(_DWORD *)(v4 + 68) )
    {
      result = kgsl_regmap_read(a1 + 13200);
      v27 = *(_DWORD *)(v4 + 20);
      if ( v27 )
      {
        v28 = result - v27;
        if ( (unsigned int)result < v27 )
          v28 = result + ~v27;
      }
      else
      {
        v28 = 0;
      }
      v29 = v28;
      *(_DWORD *)(v4 + 20) = result;
    }
    else
    {
      v29 = 0;
    }
    if ( **(_DWORD **)(a1 + 14264) != 630 )
    {
      if ( *(_DWORD *)(v4 + 56) )
      {
        result = kgsl_regmap_read(a1 + 13200);
        v30 = *(_DWORD *)(v4 + 8);
        if ( v30 )
        {
          LODWORD(v31) = result - v30;
          if ( (unsigned int)result < v30 )
            LODWORD(v31) = result + ~v30;
        }
        else
        {
          LODWORD(v31) = 0;
        }
        v31 = (unsigned int)v31;
        *(_DWORD *)(v4 + 8) = result;
      }
      else
      {
        v31 = 0;
      }
      v32 = v31 + v26;
      if ( *(_DWORD *)(v4 + 60) )
      {
        result = kgsl_regmap_read(a1 + 13200);
        v33 = *(_DWORD *)(v4 + 12);
        if ( v33 )
        {
          LODWORD(v34) = result - v33;
          if ( (unsigned int)result < v33 )
            LODWORD(v34) = result + ~v33;
        }
        else
        {
          LODWORD(v34) = 0;
        }
        v34 = (unsigned int)v34;
        *(_DWORD *)(v4 + 12) = result;
      }
      else
      {
        v34 = 0;
      }
      v35 = v32 + v34;
      if ( *(_DWORD *)(v4 + 64) )
      {
        result = kgsl_regmap_read(a1 + 13200);
        v36 = *(_DWORD *)(v4 + 16);
        if ( v36 )
        {
          LODWORD(v37) = result - v36;
          if ( (unsigned int)result < v36 )
            LODWORD(v37) = result + ~v36;
        }
        else
        {
          LODWORD(v37) = 0;
        }
        v37 = (unsigned int)v37;
        *(_DWORD *)(v4 + 16) = result;
      }
      else
      {
        v37 = 0;
      }
      v26 = v35 + v37;
      if ( *(_DWORD *)(v4 + 72) )
      {
        result = kgsl_regmap_read(a1 + 13200);
        v38 = *(_DWORD *)(v4 + 24);
        if ( v38 )
        {
          LODWORD(v39) = result - v38;
          if ( (unsigned int)result < v38 )
            LODWORD(v39) = result + ~v38;
        }
        else
        {
          LODWORD(v39) = 0;
        }
        v39 = (unsigned int)v39;
        *(_DWORD *)(v4 + 24) = result;
      }
      else
      {
        v39 = 0;
      }
      v29 += v39;
    }
    a2[1] = v26;
    a2[2] = v29;
  }
  return result;
}
