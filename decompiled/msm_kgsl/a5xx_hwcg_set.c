__int64 __fastcall a5xx_hwcg_set(__int64 result, char a2)
{
  __int64 v2; // x21
  __int64 v3; // x19
  unsigned int v5; // w22
  __int64 v6; // x1
  __int64 v7; // x1
  unsigned int v8; // w20

  if ( *(_BYTE *)(result + 20434) == 1 )
  {
    v2 = *(_QWORD *)(result + 14264);
    v3 = result;
    if ( *(_DWORD *)(v2 + 144) )
    {
      v5 = 0;
      do
      {
        if ( (a2 & 1) != 0 )
          v6 = *(unsigned int *)(*(_QWORD *)(v2 + 136) + 8LL * (int)v5 + 4);
        else
          v6 = 0;
        kgsl_regmap_write(v3 + 13200, v6);
        ++v5;
      }
      while ( v5 < *(_DWORD *)(v2 + 144) );
    }
    if ( (a2 & 1) != 0 )
      v7 = 2863180288LL;
    else
      v7 = 0;
    if ( (a2 & 1) != 0 )
      v8 = 386;
    else
      v8 = 384;
    kgsl_regmap_write(v3 + 13200, v7);
    return kgsl_regmap_write(v3 + 13200, v8);
  }
  return result;
}
