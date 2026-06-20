__int64 __fastcall gen7_counter_gbif_pwr_enable(__int64 a1, _QWORD *a2, unsigned int a3, unsigned int a4)
{
  __int64 v5; // x20
  __int64 v7; // x21
  char v8; // w22

  if ( a4 > 0xFF )
    return 4294967274LL;
  v5 = 1LL << ((unsigned __int8)a3 + 16);
  v7 = *a2 + 48LL * a3;
  v8 = 8 * a3;
  kgsl_regmap_rmw(a1 + 13200, 15553, (unsigned int)v5, (unsigned int)v5);
  kgsl_regmap_rmw(a1 + 13200, 15553, (unsigned int)v5, 0);
  kgsl_regmap_rmw(a1 + 13200, *(unsigned int *)(v7 + 24), (unsigned int)(255 << v8), a4 << v8);
  kgsl_regmap_rmw(a1 + 13200, 15552, (unsigned int)v5, (unsigned int)v5);
  *(_QWORD *)(v7 + 32) = 0;
  return 0;
}
