__int64 __fastcall gen7_power_feature_stats(__int64 result)
{
  __int64 v1; // x19
  __int64 v2; // x22
  unsigned int v3; // w8
  int v4; // w8
  unsigned int v5; // w8
  unsigned int v6; // w8
  unsigned __int64 v7; // t2
  unsigned int v8; // w9
  int v9; // w8

  v1 = result;
  v2 = result + 20364;
  if ( (*(_BYTE *)(*(_QWORD *)(result + 14264) + 32LL) & 0x40) != 0 )
  {
    result = kgsl_regmap_read(result + 13200);
    v3 = *(_DWORD *)v2;
    if ( *(_DWORD *)v2 )
    {
      *(_DWORD *)v2 = result;
      if ( (unsigned int)result < v3 )
        v4 = ~v3;
      else
        v4 = -v3;
      *(_DWORD *)(v2 + 284) += v4 + result;
    }
    else
    {
      *(_DWORD *)v2 = result;
    }
  }
  if ( *(_BYTE *)(v2 + 73) == 1 )
  {
    *(_DWORD *)(v2 + 4) = kgsl_regmap_read(v1 + 13200);
    *(_DWORD *)(v2 + 8) = kgsl_regmap_read(v1 + 13200);
    result = kgsl_regmap_read(v1 + 13200);
    *(_DWORD *)(v2 + 12) = result;
    v5 = **(_DWORD **)(v1 + 14264);
    if ( v5 - 459264 < 2
      || v5 == 460288
      || v5 >> 1 == 230528
      || (HIDWORD(v7) = v5 - 461568, LODWORD(v7) = v5 - 461568, v6 = v7 >> 8, v6 <= 6) && ((1 << v6) & 0x59) != 0 )
    {
      result = kgsl_regmap_read(v1 + 13200);
      v8 = *(_DWORD *)(v2 + 20);
      if ( v8 )
      {
        v9 = result - v8;
        if ( (unsigned int)result < v8 )
          v9 = result + ~v8;
      }
      else
      {
        v9 = 0;
      }
      *(_DWORD *)(v2 + 20) = result;
      *(_DWORD *)(v2 + 3644) += 10 * v9 / 0xC0u;
    }
  }
  return result;
}
