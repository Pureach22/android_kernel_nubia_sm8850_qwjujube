__int64 __fastcall a6xx_halt_gbif(__int64 a1)
{
  kgsl_regmap_write(a1 + 13200, 1);
  adreno_wait_for_halt_ack_0(a1, 15430, 1);
  kgsl_regmap_write(a1 + 13200, 2);
  return adreno_wait_for_halt_ack_0(a1, 15430, 2);
}
