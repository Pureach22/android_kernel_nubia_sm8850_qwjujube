__int64 __fastcall a6xx_counter_gbif_enable(__int64 a1, _QWORD *a2, unsigned int a3, unsigned int a4)
{
  __int64 v5; // x21
  unsigned int v7; // w20
  char v8; // w22

  if ( a4 > 0x7F )
    return 4294967274LL;
  v5 = *a2 + 48LL * a3;
  v7 = 1 << a3;
  v8 = 8 * a3;
  kgsl_regmap_rmw(a1 + 13200, (unsigned int)(*(_DWORD *)(v5 + 24) - 1), v7, v7);
  kgsl_regmap_rmw(a1 + 13200, (unsigned int)(*(_DWORD *)(v5 + 24) - 1), v7, 0);
  kgsl_regmap_rmw(a1 + 13200, *(unsigned int *)(v5 + 24), (unsigned int)(255 << v8), a4 << v8);
  kgsl_regmap_rmw(a1 + 13200, (unsigned int)(*(_DWORD *)(v5 + 24) - 2), v7, v7);
  *(_QWORD *)(v5 + 32) = 0;
  return 0;
}
