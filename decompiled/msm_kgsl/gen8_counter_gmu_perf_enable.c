__int64 __fastcall gen8_counter_gmu_perf_enable(__int64 a1, _QWORD *a2, unsigned int a3, unsigned int a4)
{
  __int64 v5; // x19

  if ( a4 > 0xFF )
    return 4294967274LL;
  v5 = *a2 + 48LL * a3;
  kgsl_regmap_rmw(a1 + 13200, *(unsigned int *)(v5 + 24), (unsigned int)(255 << (8 * (a3 & 3))), a4 << (8 * (a3 & 3)));
  kgsl_regmap_write(a1 + 13200, 1);
  *(_QWORD *)(v5 + 32) = 0;
  return 0;
}
