__int64 __fastcall a6xx_counter_gbif_pwr_enable(__int64 a1, _QWORD *a2, unsigned int a3, int a4)
{
  __int64 v4; // x22
  unsigned int v6; // w21
  char v8; // w23

  v4 = *a2 + 48LL * a3;
  v6 = 0x10000 << a3;
  v8 = 8 * a3;
  kgsl_regmap_rmw(a1 + 13200, (unsigned int)(*(_DWORD *)(v4 + 24) + 1), v6, v6);
  kgsl_regmap_rmw(a1 + 13200, (unsigned int)(*(_DWORD *)(v4 + 24) + 1), v6, 0);
  kgsl_regmap_rmw(
    a1 + 13200,
    (unsigned int)(*(_DWORD *)(v4 + 24) + 3),
    (unsigned int)(255 << v8),
    (unsigned int)(a4 << v8));
  kgsl_regmap_rmw(a1 + 13200, *(unsigned int *)(v4 + 24), v6, v6);
  *(_QWORD *)(v4 + 32) = 0;
  return 0;
}
