__int64 __fastcall gen8_halt_gbif(__int64 a1)
{
  unsigned int v2; // w20

  kgsl_regmap_write(a1 + 13200, 1);
  adreno_wait_for_halt_ack_3(a1, 1);
  kgsl_regmap_write(a1 + 13200, 2);
  v2 = adreno_wait_for_halt_ack_3(a1, 2);
  kgsl_regmap_write(a1 + 13200, 0);
  return v2;
}
