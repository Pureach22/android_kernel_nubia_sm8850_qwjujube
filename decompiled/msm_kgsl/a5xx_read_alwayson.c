__int64 __fastcall a5xx_read_alwayson(__int64 a1)
{
  unsigned int v2; // w19
  __int64 v3; // x8

  v2 = kgsl_regmap_read(a1 + 13200);
  if ( **(_DWORD **)(a1 + 14264) == 540 )
    v3 = kgsl_regmap_read(a1 + 13200) << 32;
  else
    v3 = 0;
  return v3 | v2;
}
