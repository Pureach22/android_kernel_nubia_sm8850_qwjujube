__int64 __fastcall a6xx_counter_read_norestore(__int64 a1, _QWORD *a2, unsigned int a3)
{
  __int64 v3; // x21
  unsigned int v5; // w20

  v3 = *a2 + 48LL * a3;
  v5 = kgsl_regmap_read(a1 + 13200);
  return *(_QWORD *)(v3 + 32) + v5 + (kgsl_regmap_read(a1 + 13200) << 32);
}
