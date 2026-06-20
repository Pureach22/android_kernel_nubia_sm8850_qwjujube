__int64 __fastcall a5xx_counter_pwr_gpmu_enable(__int64 a1, _QWORD *a2, unsigned int a3, unsigned int a4)
{
  int v4; // w9
  __int64 v7; // x19

  v4 = **(_DWORD **)(a1 + 14264);
  if ( v4 == 530 )
  {
    if ( a4 > 0x2B )
      return 4294967274LL;
  }
  else if ( a4 >= 0x30 && v4 == 540 )
  {
    return 4294967274LL;
  }
  v7 = *a2 + 48LL * a3;
  kgsl_regmap_rmw(a1 + 13200, *(unsigned int *)(v7 + 24), (unsigned int)(255 << (8 * (a3 & 3))), a4 << (8 * (a3 & 3)));
  kgsl_regmap_write(a1 + 13200, 1);
  *(_QWORD *)(v7 + 32) = 0;
  return 0;
}
