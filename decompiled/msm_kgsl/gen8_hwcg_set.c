__int64 __fastcall gen8_hwcg_set(__int64 a1, char a2)
{
  int *v2; // x21
  int v5; // w9
  bool v7; // zf
  char v8; // w22
  unsigned int v9; // w20
  __int64 v10; // x2
  unsigned int *v11; // x8

  v2 = *(int **)(a1 + 14264);
  v5 = *v2;
  v7 = (unsigned int)(*v2 - 0x80000) < 2 || v5 == 525824 || v5 == 525312;
  if ( v7 && (a2 & 1) != 0 )
    kgsl_regmap_write(a1 + 13200, 1794);
  v8 = *(_BYTE *)(a1 + 20434) & a2;
  if ( v2[34] )
  {
    v9 = 0;
    do
    {
      v11 = (unsigned int *)(*((_QWORD *)v2 + 16) + 8LL * (int)v9);
      if ( (v8 & 1) != 0 )
        v10 = v11[1];
      else
        v10 = 0;
      gmu_core_regwrite(a1, *v11, v10);
      ++v9;
    }
    while ( v9 < v2[34] );
  }
  kgsl_regmap_write(a1 + 13200, 1);
  kgsl_regmap_write(a1 + 13200, v8 & 1);
  if ( (v8 & 1) == 0 )
    return kgsl_regmap_rmw(a1 + 13200, 15360, 458752, 0);
  kgsl_regmap_write(a1 + 13200, 1);
  _const_udelay(4295);
  if ( (kgsl_regmap_read(a1 + 13200) & 1) != 0 )
    return kgsl_regmap_write(a1 + 13200, 0);
  _const_udelay(4295);
  if ( (kgsl_regmap_read(a1 + 13200) & 1) != 0 )
    return kgsl_regmap_write(a1 + 13200, 0);
  _const_udelay(4295);
  if ( (kgsl_regmap_read(a1 + 13200) & 1) != 0 )
    return kgsl_regmap_write(a1 + 13200, 0);
  dev_err(*(_QWORD *)a1, "RBBM_CGC_P2S_STATUS:TXDONE Poll failed\n");
  return kgsl_device_snapshot(a1, 0, 0, 0);
}
