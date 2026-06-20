__int64 __fastcall gen7_counter_gmu_xoclk_enable(__int64 a1, _QWORD *a2, unsigned int a3, unsigned int a4)
{
  unsigned int v5; // w8
  char v6; // w9
  __int64 v7; // x19

  if ( a4 > 0xFF )
    return 4294967274LL;
  v5 = a3 - 6;
  if ( a3 == 10 )
    v6 = 0;
  else
    v6 = a3;
  if ( v5 >= 4 )
    LOBYTE(v5) = v6;
  v7 = *a2 + 48LL * a3;
  if ( (a3 & 0xFFFFFFFE) == 4 )
    LOBYTE(v5) = a3 - 4;
  kgsl_regmap_rmw(a1 + 13200, *(unsigned int *)(v7 + 24), (unsigned int)(255 << (8 * v5)), a4 << (8 * v5));
  *(_QWORD *)(v7 + 32) = 0;
  kgsl_regmap_write(a1 + 13200, 1);
  return 0;
}
