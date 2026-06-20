__int64 __fastcall gen7_counter_gmu_perf_enable(__int64 a1, _QWORD *a2, unsigned int a3, unsigned int a4)
{
  __int64 v5; // x19
  char v6; // w8
  __int64 v8; // x0

  if ( a4 > 0xFF )
    return 4294967274LL;
  v5 = *a2 + 48LL * a3;
  v6 = 8 * a3 - 32;
  v8 = a1 + 13200;
  if ( a3 <= 3 )
    v6 = 8 * a3;
  kgsl_regmap_rmw(v8, *(unsigned int *)(v5 + 24), (unsigned int)(255 << v6), a4 << v6);
  kgsl_regmap_write(a1 + 13200, 1);
  *(_QWORD *)(v5 + 32) = 0;
  return 0;
}
